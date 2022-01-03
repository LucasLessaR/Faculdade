/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Arquivo com definicao das funcoes da classe vertices

*/

#include "aresta.h"

Aresta::Aresta(vector<Vertice*> v, unsigned int nAgrupamento){
    vertices = v;
    N = nAgrupamento;
}

vector <Vertice*> Aresta::getVertice(){
    return vertices;
}


unsigned int Aresta::getOcorrencia(){
    return ocorrencia;
}

void Aresta::addOcorrencia(){
        ocorrencia++;
}


// Funcao que ira comparar termo a termo as palavras passadas no vector v com as palavras armazenadas nessa aresta
unsigned int Aresta::verificaAresta(vector <Vertice*> v){
    unsigned int index;
    unsigned int checagem = 0;
    for (index = 0; index < v.size(); index++){
        if (v[index]->getPalavra().compare(vertices[index]->getPalavra()) == 0){    // comparacao das palavras
            checagem++;
        }
    }
    if (checagem == v.size()){      // se todas as palavras forem iguais, retorna 0. Senao retorna 1
        return 0;
    }
    else{
        return 1;
    }
}


