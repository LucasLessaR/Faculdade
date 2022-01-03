/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Arquivo com definicao da classe aresta

*/

#include <iostream>
#include <string>
#include <vector>

#include "vertice.h"

using namespace std;

#ifndef ARESTA_H
#define ARESTA_H

class Aresta
{
    private:
        vector<Vertice*> vertices;      // vector que armazena as palavras desse grupo (aresta)
        unsigned int ocorrencia = 0;    // numero de ocorrencias da aresta
        unsigned int N;                 // numero de termos do grupo
        

    public:
        Aresta(vector<Vertice*>, unsigned int);
        
        vector <Vertice*> getVertice();
        unsigned int verificaAresta(vector <Vertice*>);
        unsigned int getOcorrencia();
        void addOcorrencia();
};

#endif