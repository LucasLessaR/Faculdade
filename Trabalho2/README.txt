/*

 * UFRJ - Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * EEL670 - Linguagens de Programacao - 2020/2
 * Prof: Miguel Elias Mitre Campista
 * Autor: Lucas Lessa Rodrigues
 * Sobre: Programa para leitura de arquivo utilizando logica de grafos

*/

# Informações Sobre a Compilação do Programa
    -> Para compilar o programa podemos utilizar de dois métodos:
    1) Utilização do makefile:
        >> Para utilizar o makefile, digite o seguinte comando na CLI:
            $ make trabalho2
        >> Essa ação irá compilar o código main junto dos código referentes as classes Vértice, Aresta e Grafo
    
    2) Utilização do comando de compilação direto pela linha de comando:
        >> Para compilar utilizando comando diretamente, utilize o seguinte comando na CLI:
            $ g++ -Wall -o trabalho2 vertice.cpp aresta.cpp grafo.cpp main.cpp

    -> Após a compilação e geração do executável, podemos executar o programa a partir do comando:
        $ ./trabalho2
    
    -> Caso se queira realizar outra compilação depois da primeira, é necessário limpar os arquivos gerados pela primeira compilação.
    -> Para isso, execute o seguinte comando:
        $ make clean

# Informações sobre utilização do programa
    -> O programa irá perguntar ao usuário o nome do arquivo texto que será lido e o número de agrupamentos (apenas quando a opção de N agrupamentos for escolhida)
    -> Arquivos texto possuem diferenças dependendo do Sistema Operacional utilizado.
        >> Caso o Sistema Operacional seja:
            > Windows: Utilize "arquivo.txt"
            > Unix/Distribuição Linux: Utilize apenas "arquivo"
    -> Garanta que o arquivo texto está presente no mesmo diretório que o programa está sendo executado.
    -> Caso queria realizar um teste, junto aos arquivos do programa existe um arquivo chamado "teste.txt". Ele poderá ser utilizado para testar o 
    programa, onde dentro dele estão palavras aleatórias e algumas pontuações que não seguem as regras do Português.

    -> Após da definição do arquivo texto utilizado, serão exibidas as opções que podem ser realizadas:
        >> (1) Printar palavra com maior ocorrencia
        >> (2) Printar par de palavras com maior ocorrencia
        >> (3) Printar grupo de N palavras com maior ocorrencia  
    
    -> A opcao (1) irá printar a palavra mais frequente no texto
    -> A opcao (2) irá printar o par de palavras mais frequente no texto
    -> A opcao (3) irá printar o grupo de N palavras mais frequente no texto
        >> caso essa opção seja escolhida, será pedido um número N que será o número de palavras no agrupamento que será feito.
        >> Esse número N deverá ser um inteiro maior que 0.
    -> Para finalização do programa é preciso utilizar a opção (0).