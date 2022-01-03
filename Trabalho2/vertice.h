/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Arquivo com definicao da classe vertices

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef VERTICE_H
#define VERTICE_H

class Vertice
{
    private:
        string palavra;     // palavra do texto armazenada no vertice
        unsigned int repeticao = 0;     // numero de vezes que a palavra aparece

    public:
        Vertice(string);

        string getPalavra();
        unsigned int getRepeticao();
        void addRepeticao();
};

#endif