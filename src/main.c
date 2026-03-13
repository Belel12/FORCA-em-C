#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define palavras_path "./src/palavras.txt"

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
    if(estagio < 0 || estagio > 7){
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
                printf("|                 |\n");
                printf("|                 |\n");
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
            printf("|                /|\n");
            printf("|                 |\n");
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
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 6:
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
        case 7:
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

void imprimir_menu(bool dica_habilitada){
    printf("JOGO DA FORCA\n");
    imprimir_boneco(7);
    printf("\n1) JOGAR\n2) SAIR\n");
    if(dica_habilitada){
        printf("3) DESABILITAR DICAS");
    }
    else{
        printf("3) HABILITAR DICAS");
    };
    return;
}

void to_upper_string(char* str){
    for(int i = 0; str[i]!='\0'; i++){
        str[i] = toupper(str[i]);
    }
}

int quantidadeLinhas(FILE* arquivo){
    if(arquivo == NULL)
        return 0;
    int qtd = 0;
    char buffer[50];
    while( fgets(buffer,sizeof(buffer),arquivo) != NULL)
        qtd++;
    return qtd;
}

int carregar_palavraEdica(int linha, char* palavra, char* dica){ //carrega a palavra e a dica nos ponteiros passados como parâmetro dada a linha da palavra;linha
        char buffer[200];
        FILE* arquivo = fopen(palavras_path,"r");
        if(arquivo == NULL){
                printf("\nERRO AO ABRIR O ARQUIVO PARA LEITURA");
                return 0;
        }
        for(int i = 0; i < linha; i++){
                if(fgets(buffer,sizeof(buffer),arquivo) == NULL){
                        printf("\nERRO AO LER A PALAVRA NA LINHA ESPECIFICADA");
                        return 0;
                }
        }
        fclose(arquivo);
        strcpy(palavra,strtok(buffer,";\n"));
        strcpy(dica,strtok(NULL,";\n"));
        return 1;
}

int main(){
    limpar_tela();
    FILE* arquivo_palavras = fopen(palavras_path,"a+");
    if(arquivo_palavras == NULL){
        printf("\nERRO: ARQUIVO DE PALAVRAS NAO ENCONTRADO");
        return 1;
    };
    int qtdPalavras = quantidadeLinhas(arquivo_palavras);
    fclose(arquivo_palavras);
    if(qtdPalavras == 0){
        printf("Nao ha palavras no arquivo de palavras\ncoloque as palavras a serem usadas no jogo la,\numa por linha.\n");
        return 0;
    }
    srand(time(NULL));
    bool habilitar_dicas = true;
    imprimir_menu(habilitar_dicas);
    char opcao = '0';
    while(true){   
        printf("\nESCOLHA UMA OPCAO: ");
        opcao = getchar();
        limpar_buffer();
        switch (opcao){
            case '1': { //inicia loop do jogo
                limpar_tela();
                int numero_palavra_escolhida = rand()%qtdPalavras;
                if (numero_palavra_escolhida == 0) //para evitar de não ter nenhuma palavra
                        numero_palavra_escolhida = 1;
                char palavra_escolhida[50];
                char dica[100];
                if(!carregar_palavraEdica(numero_palavra_escolhida,palavra_escolhida,dica)){
                        printf("\nERRO AO CARREGAR PALAVRA E DICA");
                        exit(1);
                };
                int tamanho_palavra = strlen(palavra_escolhida);
                to_upper_string(palavra_escolhida);               
                char palavra_advinhada[tamanho_palavra];
                int erros = 0;
                int letras_acertadas = 0;
                char letras_tentadas[26];
                int ultimo_indice_tentadas = 0;
                char error_message[100] = {0};
                for(int i = 0; i<tamanho_palavra;i++){
                    if(palavra_escolhida[i] == ' '){
                        palavra_advinhada[i] = ' ';
                        letras_acertadas++; //os espaços ja vêm como acertadas
                    }else{
                        palavra_advinhada[i] = '_';
                        
                    }
                }
                
                while(true){ //loop principal
                    limpar_tela();
                    imprimir_boneco(erros);
                    
                    if(erros == 7){
                        printf("\nVOCE PERDEU :( ");
                        printf("\nA PALAVRA ERA: %s",palavra_escolhida);
                        break;
                    }
                    if (letras_acertadas == tamanho_palavra){
                        printf("\nPARABENS! :D\nVOCE ACERTOU A PALAVRA -> %s",palavra_escolhida);
                        break;
                    }
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
                    printf("%s",error_message);
                    strcpy(error_message,"");
                    if(erros >= 6 && habilitar_dicas){
                        printf("\nDICA: %s\n",dica);
                    };
                    printf("\n\nESCOLHA UMA LETRA: ");
                    char letra_escolhida = toupper(getchar());
                    limpar_buffer();
                    if (!isalpha(letra_escolhida)) { //verifica se é uma letra válida
                        strcpy(error_message,"\nLETRA INVÁLIDA, DIGITE APENAS LETRAS DO ALFABETO\n");
                        printf("\a");
                        continue;
                    }
                    bool ja_tentou = false;
                    for(int i = 0; i < ultimo_indice_tentadas; i++){
                        if (letra_escolhida == letras_tentadas[i]){
                            ja_tentou = true;
                            break;
                        }
                    }
                    if(ja_tentou){
                        strcpy(error_message,"\nVOCE JA TENTOU ESSA LETRA\n");
                        printf("\a");
                        continue;
                    }
                    letras_tentadas[ultimo_indice_tentadas] = letra_escolhida;
                    ultimo_indice_tentadas+=1;
                    bool acertou = false;
                    for (int i = 0; i < tamanho_palavra ; i++){
                        if (palavra_escolhida[i] == letra_escolhida){
                            palavra_advinhada[i] = letra_escolhida;
                            letras_acertadas+=1;
                            acertou = true;
                        }
                    }
                    if (!acertou){
                        erros+=1;
                    }
                    
                }
                
                printf("\nVOLTAR AO MENU : 1\nSAIR : 2\n");
                while(true){
                    printf("DIGITE UMA OPCAO: ");
                    opcao = getchar();
                    limpar_buffer();
                    if(opcao == '1'){
                        limpar_tela();
                        imprimir_menu(habilitar_dicas);
                        break;
                    }else if(opcao == '2'){
                        limpar_tela();
                        printf("\nOBRIGADO POR JOGAR :)\n");
                        exit(0);
                    }else{
                        printf("\nOPCAO INVALIDA\n");
                    }

                }
                break;
            }
            case '2':
                limpar_tela();
                exit(0);
            case '3':{
                habilitar_dicas = !habilitar_dicas;
                limpar_tela();
                imprimir_menu(habilitar_dicas);
                break;
            }
            default:
                printf("\nOPCAO INVALIDA\n");
                break;
        }
    }

    return 0;
}