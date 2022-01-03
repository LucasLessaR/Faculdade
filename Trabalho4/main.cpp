/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Programa principal referente a gerenciamento hospitalar

*/

#include <iostream>
#include <string>

#include "arvore.h"
#include "excecao.h"
#include "paciente.h"
#include "cadastro.h"

int main(){
    unsigned int opcao = 0;
    string nomeAux = "";
    Cadastro<Paciente> cadastro;
    Cadastro<PacienteAgendado> cadastroAgendamento;

    while (1){
        cout << "\n\tMenu Principal:" << endl;
        cout << "1) Cadastrar Paciente;" << endl;
        cout << "2) Cadastrar Paciente Agendado;" << endl;
        cout << "3) Buscar Paciente;" << endl;
        cout << "4) Buscar Paciente Agendado;" << endl;
        cout << "5) Printar Cadastro;" << endl;
        cout << "6) Printar Cadastro de Agendamento;" << endl;
        cout << "0) Sair." << endl;
        cout << "\n\nInsira a opcao desejada: ";
        cin >> opcao;

        switch (opcao)
        {
            case 0:
                cout << "\nFinalizando Programa! Ate a proxima." << endl;
                exit(-1);

            case 1:{
                Paciente pacienteTemp;
                cadastro += pacienteTemp;
                break;
            }

            case 2:{
                PacienteAgendado pacienteTemp;
                cadastroAgendamento += pacienteTemp;
                break;
            }

            case 3:{
                // Aqui criamos um objeto local de classe Paciente para receber o return da operacao de busca 
                cout << "\nDigite o nome do paciente que deseja buscar:\n";
                cin >> nomeAux;
                Paciente* pacienteTemp;
                pacienteTemp = cadastro(nomeAux);
                cout << *(pacienteTemp);
                nomeAux = "";
                break;
            }

            case 4:{
                // Aqui criamos um objeto local de classe PacienteAgendado para receber o return da operacao de busca
                cout << "\nDigite o nome do paciente agendado que deseja buscar:\n";
                cin >> nomeAux;
                PacienteAgendado* pacienteTemp;
                pacienteTemp = cadastroAgendamento(nomeAux);
                cout << *(pacienteTemp);
                nomeAux = "";
                break;
            }

            case 5:{
                // Utilizacao do operador << para printar arvore de membros Paciente
                cout << cadastro;
                break;
            }

            case 6:{
                // Utilizacao do operador << para printar arvore de membros PacienteAgendado
                cout << cadastroAgendamento;
                break;
            }

            default:{
                cout << "\n\tOpcao Invalida!\n" 
                << "Utiliza os numeros das opcoes para realizar a acao desejada." << endl; 
                break;
            }
        }

    }

    return 0;
}