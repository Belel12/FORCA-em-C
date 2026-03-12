JOGO DA FORCA implementado em C

- para rodar o jogo:
    -execute 'run.sh' caso esteja no linux
    -execute 'run.bat' caso esteja no Windows

    #AVISO:
    -esses arquivos apenas executam a compilação e rodam o binário automaticamente, para facilitar a vida do usuário,
    porém caso o usuário não tenha o GCC configurado no path nas variáveis de ambiente do sistema, causará erro de compilação.
    -Quaisquer erros de compilação ficam salvos no arquivo da pasta logs/

- para configurar as palavras:
    - o programa seleciona uma das palavras dentro do arquivo 'palavras.txt' de forma randômica para iniciar o jogo,
    caso o arquivo esteja vazio, uma mensagem de aviso irá aparecer e o jogo não irá continuar
    - o que separa cada palavra é a quebra de linha, ou seja, caso coloque por exemplo:
        "UVA VERDE"
        "BANANA"
    "UVA VERDE" será considerada uma palavra só
    - o programa lê palavras de até 50 caracteres, até o momento caso seja colocado uma palavra maior que 50 caracteres,
        poderá ocorrer comportamento inesperado como palavras cortadas
    - palavras com acento provavelmente irão dar problema visto que as bibliotecas padrão da linguagem C não têm suporte
        nativo à caracteres unicode, talvez eu crie uma função para tirar acentos, mas novamente, as palavras que serão
        usadas no jogo serão sem acento de qualquer forma
        
-João Gabriel F. S. Prado