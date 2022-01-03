/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Arquivo com definicao das funcoes da classe vertices

*/

#include "vertice.h"

Vertice::Vertice (string palavraInput){
    palavra = palavraInput;
}

string Vertice::getPalavra(){
    return palavra;
}

unsigned int Vertice::getRepeticao(){
    return repeticao;
}

void Vertice::addRepeticao(){
    repeticao++;
}