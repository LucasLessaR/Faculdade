/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Programa main para implementação do programa de leitura de arquivos utilizando grafos

*/

#include <iostream>
#include <string>

#include "grafo.h"

using namespace std;

int main(){
    string fileName;
    unsigned int opcao, nInput = 0;

    cout << "Para realizar a leitura sobre um arquivo texto, insira seu nome junto da terminacao (****.txt)" << endl;
    cout << "Nome do arquivo: ";
    getline(cin, fileName);

    // inicializacao de um objeto da classe grafo
    Grafo grafo(fileName, nInput);

    while(1){
        cout << "\n\n(1) Printar palavra com maior ocorrencia" << endl;
        cout << "(2) Printar par de palavras com maior ocorrencia" << endl;
        cout << "(3) Printar grupo de N palavras com maior ocorrencia" << endl;
        cout << "(0) Sair" << endl;
        cout << "Selecione a opcao desejada: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                grafo.printPalavraMaisUsada();
                break;
            case 2:
                grafo.printParMaisUsado();
                break;
            case 3:
                cout << "Qual N numero de palavras por grupo deseja?" << endl;
                cin >> nInput;
                // checagem do valor N de agrupamentos passados. Nao pode ter menos de 1 palavra por agrupamento
                if (nInput < 1){
                    cout << "Valor invalido! Insira Apenas valores inteiros e positivos" << endl;
                }
                else{
                    grafo.printNGrupoMaisUsado(nInput);
                }
                break;
            case 0:
                exit(1);

            default:
                cout << "Opcao invalida! Insira valores disponiveis no menu." << endl;
                break;
        }
    }

    return 0;
}