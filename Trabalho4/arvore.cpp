/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Arquivo com implementaçao das funçoes da classe arvore binaria

*/

#include "arvore.h"



No<T>& Arvore::operator+=(T& dataInput){
    newNode = new No<T>*;
    newNode->dados = dataInput;;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode = inserirNo(newNode);
    return newNode;
}

No<T>& Arvore::inserirNo(No<T>* nodeInput){
    if (this->root == nullptr){
        this->root = nodeInput;
        return this->root;
    }

    else if (this->root->dados < nodeInput->dados){
        root->right = inserirNo()
    }
}