/*

 * UFRJ - Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * EEL670 - Linguagens de Programacao - 2020/2
 * Prof: Miguel Elias Mitre Campista
 * Autor: Lucas Lessa Rodrigues
 * Sobre: README sobre programa de gerenciamento hospitalar

*/

# Informações Sobre a Compilação do Programa
    -> Para compilar o programa podemos utilizar de dois métodos:
    1) Utilização do makefile:
        >> Para utilizar o makefile, digite o seguinte comando na CLI:
            $ make trabalho4
        >> Essa ação irá compilar o código main junto dos código referente as classes Paciente e Cadastro
    
    2) Utilização do comando de compilação direto pela linha de comando:
        >> Para compilar utilizando comando diretamente, utilize o seguinte comando na CLI:
            $ g++ -Wall -o trabalho4 paciente.cpp main.cpp

    -> Após a compilação e geração do executável, podemos executar o programa a partir do comando:
        $ ./trabalho4
    
    -> Caso se queira realizar outra compilação depois da primeira, é necessário limpar os arquivos gerados pela primeira compilação.
    -> Para isso, execute o seguinte comando:
        $ make clean

# Informações sobre utilização do programa
    -> O programa ao executar irá mostrar um menu com opções de ações que podem ser realizadas no Cadastro.
    -> As opções são:
        >> 1) Cadastrar Paciente;
        >> 2) Cadastrar Paciente Agendado;
        >> 3) Buscar Paciente;
        >> 4) Buscar Paciente Agendado;
        >> 5) Printar Cadastro;
        >> 6) Printar Cadastro de Agendado;
        >> 0) Sair.
    
    -> A opção (1) irá adicionar um paciente da classe Paciente.
        -> Antes da inserção será criado um paciente local. No construtor dessa classe será pedido informações básicas do paciente:
            >> No construtor da classe será pedido nome e idade do paciente;
            >> Nome deverá ser uma string;
            >> Idade deverá ser apenas numeros;
        
    -> A opção (2) irá adicionar um paciente da classe PacienteAgendado.
        -> Antes da inserção será criado um paciente local. No construtor dessa classe será pedido informações básicas do paciente:
            >> No construtor da classe será pedido nome, idade e data da consulta;
            >> Nome deverá ser uma string;
            >> Idade deverá ser apenas numeros;
            >> Data da consulta é separada em 3 partes (dia, mês e ano):
                >> Dia deverá ser feito apenas por números e entre 1 e 31 (não existe diferença do número de dias para cada mês);
                >> Mês deverá ser feito apenas por números e entre 1 e 12;
                >> Ano deverá ser feito apenas por números e maior que 2020 (estamos no ano 2021, portanto só faz sentido agendar algo para esse ano ou depois).
        
    -> A opção (3) irá Buscar um paciente da classe Paciente, caso ache irá printar suas informações na tela.
        -> Para realizar a busca é necessário informar o nome do paciente.
        -> O nome do paciente é uma string e deve estar escrito exatamente da forma como foi salvo na árvore (é case sensitive);
        -> Após indicação do nome será realizado processo de busca do paciente;
        -> Ao encontrar o paciente serão printadas suas informações na tela. Caso contrário será apresentada uma mensagem de erro.
        
    -> A opção (4) irá Buscar um paciente da classe Paciente Agendado, caso ache irá printar suas informações na tela.
        -> Para realizar a busca é necessário informar o nome do paciente.
        -> O nome do paciente é uma string e deve estar escrito exatamente da forma como foi salvo na árvore (é case sensitive);
        -> Após indicação do nome será realizado processo de busca do paciente;
        -> Ao encontrar o paciente serão printadas suas informações na tela. Caso contrário será apresentada uma mensagem de erro.
        
    -> A opção (5) irá imprimir na tela todos os pacientes da classe Paciente.
        -> Todas as informações de cada paciente serão impressas na tela.
        -> Cada paciente ocupará uma linha.
        -> As linhas serão ordenadas por ordem alfabética dos nomes dos pacientes.

    -> A opção (6) irá imprimir na tela todos os pacientes da classe Paciente Agendado.
        -> Todas as informações de cada paciente serão impressas na tela.
        -> Cada paciente ocupará uma linha.
        -> As linhas serão ordenadas por ordem alfabética dos nomes dos pacientes.
        
    -> A opção (0) irá finalizar o programa.