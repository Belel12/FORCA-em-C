JOGO DA FORCA implementado em C
    - para rodar o jogo:
        -execute 'run.sh' caso esteja no linux
        -execute 'run.bat' caso esteja no Windows
    - para configurar as palavras:
        - o programa seleciona uma das palavras dentro do arquivo 'palavras.txt' de forma randômica para iniciar o jogo,
        caso o arquivo esteja vazio, uma mensagem de aviso irá aparecer e o jogo não irá continuar
        - o que separa cada palavra é a quebra de linha, ou seja, caso coloque por exemplo:
            "UVA VERDE"
            "BANANA"
        "UVA VERDE" será considerada uma palavra só