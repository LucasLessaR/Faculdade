/*

 * UFRJ - Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * EEL670 - Linguagens de Programacao - 2020/2
 * Prof: Miguel Elias Mitre Campista
 * Autor: Lucas Lessa Rodrigues
 * Sobre: Programa para criação de catalogo de filmes

*/

# Informações Sobre a Compilação do Programa
    -> Para compilar o programa podemos utilizar de dois métodos:
    1) Utilização do makefile:
        >> Para utilizar o makefile, digite o seguinte comando na CLI:
            $ make trabalho3
        >> Essa ação irá compilar o código main junto dos código referente a classe Catalogo e a struct Filme
    
    2) Utilização do comando de compilação direto pela linha de comando:
        >> Para compilar utilizando comando diretamente, utilize o seguinte comando na CLI:
            $ g++ -Wall -o trabalho3 catalogo.cpp main.cpp

    -> Após a compilação e geração do executável, podemos executar o programa a partir do comando:
        $ ./trabalho3
    
    -> Caso se queira realizar outra compilação depois da primeira, é necessário limpar os arquivos gerados pela primeira compilação.
    -> Para isso, execute o seguinte comando:
        $ make clean

# Informações sobre utilização do programa
    -> O programa ao executar irá mostrar um menu com opções de ações que podem ser realizadas no catalogo.
    -> Ao iniciar, o construtor da classe Catalogo irá ler os filmes armazenados no arquivo "catalogo.txt"
        >> As informações dentro desse .txt seguem uma ordem específica, onde:
            >>> Cada linha possui informações sobre 1 filme unicamente;
            >>> As informações aparecem na ordem {nomeFilme, nomeProdutora, nota};
            >>> Os dados são separados unicamente por um caracter underline '_';
    -> Caso queira usar outro arquivo .txt, devem seguir as regras listadas acima para organização dos dados e no arquivo catalogo.h modificar o nome do .txt na variavel "nomeArquivo"
    -> O programa apenas permite 5 filmes por vez no catalogo. No entanto essa constante é modificavel e se localiza no arquivo catalogo.h.
        -> Caso modificada a constante, deve-se recompilar o arquivo.
    
    -> Considerando todas essas informações, irá ser falado agora sobre o menu de opções.
    -> As opções são:
        >> 1) Insercao de Filme no Catalogo;
        >> 2) Remocao de Filme do Catalogo;
        >> 3) Busca de um Filme no Catalogo;
        >> 4) Edicao de um Filme no Catalogo;
        >> 5) Imprimir Catalogo e Filme em exibicao;
        >> 6) Filme mais bem avaliado;
    
    -> A opção (1) irá pedir se é desejado inserir 1 ou mais filmes de uma vez.
        -> Essa quantidade deve ser obrigatoriamente um inteiro maior que 0;
        -> Caso escolhido 1 filme apenas:
            >> Irão aparecer espaços para preencher (em ordem), as informações sobre o filme.
            >> A ordem será {nome do filme, nome da produtora, nota do filme}
            >> Não colocar espaços vazios nessas informações pois irão atrapalhar na passagem dessas informações para o arquivo .txt posteriormente
        -> Caso escolhido N filmes:
            >> As mesmas operações acima irão ser realizadas.
            >> Será pedido para entrar com as informações de todos os filmes de 1 vez, onde só após irá indicar possíveis problemas nos dados ou de alocação.

    -> A opção (2) irá Remover um filme do catalogo
        -> Essa opção irá começar buscando o filme (atráves do operador()), utilizando o nome do filme
            >> Verificar atentamente o nome escrito, pois qualquer erro irá impedir de achar o filme, caso exista.    
        -> Caso ache o filme, ele será removido utilizando o operador-=.

    -> A opção (3) irá Buscar um filme no catalogo
        -> Essa opção irá buscar um filme no catalogo utilizando o nome (através do operador())
        -> Caso ache o filme, irá printar suas informações na tela.

    -> A opção (4) irá editar um filme no catalogo
        -> O usuário irá escolher qual informação deseja editar:
            >> (0) Nome da Produtora;
            >> (1) Nota do filme;
        -> Após a escolha da opção (que deve ser feita escolhendo o numero da opção apenas), será utilizado o operador() correspondente para realizar as edições;
        -> Para editar o nome do filme, é necessário que o mesmo seja removido e depois reinserido.

    -> A opção (5) irá imprimir na tela o catalogo inteiro utilizando o operador << interno da classe Catalogo
    -> A opção (6) irá executar a função "melhorAvaliacao()" interna da classe Catalogo
        -> Essa função irá printar o nome e nota do filme mais bem avaliado;
    -> A opção (0) irá finalizar o programa
        -> Sendo que antes de sua finalização, o arquivo .txt, selecionado previamente a execução do programa dentro da classe Catalogo, irá ser reescrito com as novas informações dos filmes presentes no catalogo.        