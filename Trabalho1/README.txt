/*

 * UFRJ - Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * EEL670 - Linguagens de Programacao - 2020/2
 * Prof: Miguel Elias Mitre Campista
 * Autor: Lucas Lessa Rodrigues
 * Sobre: Programa para observação de dados dos estados e do país sobre a pandemia de COVID-19 

*/

# Informações Sobre a Compilação do Programa
    -> Para compilar o programa podemos utilizar de dois métodos:
    1) Utilização do makefile:
        >> Para utilizar o makefile, digite o seguinte comando na CLI:
            $ make exec
        >> Essa ação irá compilar o código main junto dos código referentes as classes Estadual e Nacional
    
    2) Utilização do comando de compilação direto pela linha de comando:
        >> Para compilar utilizando comando diretamente, utilize o seguinte comando na CLI:
            $ g++ -Wall -o exec estadual.cpp nacional.cpp main.cpp

    -> Após a compilação e geração do executável, podemos executar o programa a partir do comando:
        $ ./exec
    
    -> Caso se queira realizar outra compilação depois da primeira, é necessário limpar os arquivos gerados pela primeira compilação.
    -> Para isso, execute o seguinte comando:
        $ make clean

# Informações sobre utilização do programa
    -> Os dados sobre Nome e quantidade de óbitos dos estados e do país são inicializados de forma estática.
    -> Esse programa apenas necessita que o usuário indique qual dais seguintes opções se deseja observar:
    
        (1) - Média móvel dos Estados e do País
        (2) - Exibir de forma agrupada os Estados com relação ao índice de crescimento de óbitos (Alta, Estável ou Baixa)
        (3) - Exibir índice de crescimento de óbitos do País
        (4) - Exibir Estados com Maior Alta e Maior Baixa do Índice de Crescimento de óbitos
        (5) - Exibir Total de óbitos dos Estados e do País
        (0) - Sair
    
    -> Para finalização do programa é preciso utilizar a opção (0).