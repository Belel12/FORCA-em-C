#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void limpar_buffer(){
    while(getchar() != '\n');
}

void limpar_tela(){
    #ifdef _WIN32
        system("cls");
    #elif defined __linux__
        system("clear");
    #endif
}
void imprimir_boneco(int estagio){
    if(estagio < 0 || estagio > 6){
        printf("estagio do boneco invalido");
        return;
    }
    switch (estagio){
        case 0:
            printf("|-----------------|\n");
            printf("|                 |\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 1:
            printf("|-----------------|\n");
            printf("|                 |\n");
            printf("|               ('-')\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 2:
            printf("|-----------------|\n");
            printf("|                 |\n");
            printf("|               ('-')\n");
            printf("|                 |\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        
        case 3:
            printf("|-----------------|\n");
            printf("|                 |\n");
            printf("|               ('-')\n");
            printf("|                /|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 4:
            printf("|-----------------|\n");
            printf("|                 |\n");
            printf("|               ('-')\n");
            printf("|                /|\\\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 5:
            printf("|-----------------|\n");
            printf("|                 |\n");
            printf("|               ('-')\n");
            printf("|                /|\\\n");
            printf("|                 |\n");
            printf("|                /\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 6:
            printf("|-----------------|\n");
            printf("|                 |\n");
            printf("|               (x-x)\n");
            printf("|                /|\\\n");
            printf("|                 |\n");
            printf("|                / \\\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        default:
            break;
    }
}

void imprimir_menu(){
    printf("\n1) JOGAR\n2) SAIR\n");
    return;
}

typedef struct{
    char** palavras;
    int qtdPalavras;
} MatrizPalavras;

int quantidadePalavras(FILE* arquivo){
    if(arquivo == NULL)
        return 0;
    int qtd = 0;
    char buffer[50];
    while( fgets(buffer,sizeof(buffer),arquivo) != NULL)
        qtd++;
    return qtd;
}
MatrizPalavras* carregar_palavras(){
    FILE* arquivo_palavras = fopen("./palavras.txt","a+");
    rewind(arquivo_palavras);
    MatrizPalavras* matriz = (MatrizPalavras*) malloc(sizeof(MatrizPalavras));
    matriz->qtdPalavras = 0;
    matriz->palavras = (char**) malloc(quantidadePalavras(arquivo_palavras)*sizeof(char*));
    rewind(arquivo_palavras);
    int i = 0;
    char buffer[50];

    while ( fgets(buffer,sizeof(buffer),arquivo_palavras) != NULL){
        matriz->palavras[i] = (char*) malloc(sizeof(buffer));
        strcpy(matriz->palavras[i],buffer);
        i++;
        matriz->qtdPalavras++;
    };
    fclose(arquivo_palavras);
    return matriz;
}

int main(){
    limpar_tela();
    MatrizPalavras* matriz = carregar_palavras();
    if(matriz->qtdPalavras == 0){
        printf("Nao ha palavras no arquivo de palavras\ncoloque as palavras a serem usadas no jogo la,\numa por linha.\n");
        return 0;
    }
    srand(time(NULL));
    printf("JOGO DA FORCA\n");
    imprimir_boneco(6);
    imprimir_menu();
    char opcao = '0';
    while(true){   
        printf("\nESCOLHA UMA OPCAO: ");     
        scanf(" %c", &opcao);
        limpar_buffer();
        switch (opcao){
            case '1': {
                limpar_tela();
                char *palavra_escolhida = matriz->palavras[rand()%matriz->qtdPalavras];
                int tamanho_palavra = strlen(palavra_escolhida);
                printf("palavra escolhida foi: %s\n",palavra_escolhida);
                char palavra_advinhada[tamanho_palavra];
                for(int i = 0; i<tamanho_palavra;i++){
                    palavra_advinhada[i] = '_';
                }
                int erros = 0;
                int letras_acertadas = 0;
                char letras_tentadas[26];
                int ultimo_indice_tentadas = 0;
                limpar_tela();
                while(true){
                    limpar_tela();
                    imprimir_boneco(erros);
                    printf("\nPALAVRA: ");
                    for(int i = 0; i<tamanho_palavra;i++){
                        printf("%c",palavra_advinhada[i]);
                        printf(" ");
                    }
                    printf("\n\nTENTATIVAS ANTERIORES: [");
                    for(int i = 0; i < ultimo_indice_tentadas;i++){
                        printf(" %c ,",letras_tentadas[i]);
                    }
                    printf("]");
                    printf("\n\nESCOLHA UMA LETRA: ");
                    char letra_escolhida = getchar();
                    limpar_buffer();
                    //verificação de letra escolhida
                }
                break;
            }
            case '2':
                limpar_tela();
                exit(0);
            default:
                printf("\nOPCAO INVALIDA\n");
                break;
        }
    }

    return 0;
}