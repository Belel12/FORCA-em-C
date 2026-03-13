# JOGO DA FORCA implementado em C

- para rodar o jogo, na pasta raíz do projeto:
    - execute 'run.sh' caso esteja no linux
    - execute 'run.bat' caso esteja no Windows
    - caso o terminal 'pisque' (comum de ocorrer no windows) ao executar com duplo clique, execute o arquivo via terminal

    - AVISO:
    - esses arquivos apenas executam a compilação e rodam o binário automaticamente, para facilitar a vida do usuário,
    porém caso o usuário não tenha o GCC configurado no path nas variáveis de ambiente do sistema, causará erro de compilação.
    - Quaisquer erros de compilação ficam salvos no arquivo da pasta logs/

- para configurar as palavras:
    - o programa seleciona randomicamente uma linha do arquivo de palavras para ler, automaticamente já calculando quantas
        linhas tem no arquivo, então ele armazena a palavra e a dica que a segue, delimitada por ';'
    - O tamanho reservado para palavras é de 50 caracteres e para as dicas são 100 caracteres, caso for adicionar novas
        linhas ou modificar as existentes, tenha em mente que caso o tamanho não seja respeitado pode ocorrer da palavra
        vir cortada
    - O sistema tem suporte para palavras com espaços. ex.: "UVA VERDE" 
    - Voce pode desabilitar as dicas no menu, as dicas aparecem faltando somente 1 erro para perder, visto que elas ajudam bastante   
- João Gabriel F. S. Prado