/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Arquivo com definição de classe para gerenciamento de arvore binaria

*/

#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <exception>

#include "excecao.h"

using namespace std;

template <class T>
class No{
    private:
    public:
        T dados;
        No *left;
        No *right;

        No(T dadoInput) : dados(dadoInput){
            left = nullptr;
            right = nullptr;
        }

        ~No(){
            delete(left);
            delete(right);
            left = nullptr;
            right = nullptr;
        }

        // Funcao pra inserir um no
        No<T>* inserirNo(T dadoInput){
            if (dados == dadoInput){
                return nullptr;
            }

            // checagem se No inserido e maior ou menor para jogar para esquerda ou direita da arvore
            // apos ir para direita (ou esquerda), se chegar num ponteiro nulo, inserir No
            if (dados > dadoInput){
                if (right == nullptr){
                    right = new No<T>(dadoInput);
                    return right;
                } 
                else{
                    return right->inserirNo(dadoInput);
                }
            }
            else {
                if (left == nullptr){
                    left = new No<T>(dadoInput);
                    return left;
                } 
                else{
                    return left->inserirNo(dadoInput);
                }
            } 
        }
};

// Funcao para realizar busca em arvore binaria de forma recursiva
template <class T>
No<T> *buscaRecursiva(No<T>* no, string dadoInput){
    if (no == nullptr){
        return nullptr;
    }

    if (no->dados == dadoInput){
        return no;
    }

    if (no->dados > dadoInput){
        return buscaRecursiva(no->right, dadoInput);
    }
    else {
        return buscaRecursiva(no->left, dadoInput);
    } 
}

// Funcao para printar elementos da arvore binaria de forma recursiva (e em ordem crescente para um valor do No (nesse trabalho sera o nome))
template <class T>
void printArvore(ostream& out, No<T>* no){
    if (no == nullptr){
        return;
    }

    printArvore(out, no->right);

    out << no->dados << endl;

    printArvore(out, no->left);
}

template <class T>
class Arvore{
    friend ostream& operator<<(ostream &out, Arvore<T> &arvoreInput){
        out << "\nCadastro:\n\n";
        printArvore(out, arvoreInput.root);
        return out;
    }

    private:

    public:
        No<T> *root;
        
        Arvore(){
            root = NULL;
        }

        ~Arvore(){
            delete(root);
            root = nullptr;
        }
        
        // Sobrecarga do operador += para adicionar um No na arvore
        // Essa funcao checa se o No raiz da arvore e nulo, caso contrario aplica a funcao inserirNo
        No<T>* operator+=(T dado){
            if (root == nullptr){
                root = new No<T>(dado);
                return root;
            }
            else{
                No<T>* resultado = root->inserirNo(dado);
                if (resultado == nullptr){
                    throw DuplicadaExcecao();
                }
                return resultado;
            }
        }

        // Sobrecarga do operador() para busca de No dentro da arvore binaria
        T* operator()(string dado){
            No<T>* resultado = buscaRecursiva(root, dado);

            if (resultado == nullptr){
                throw NaoExisteExcecao();
            }
            return &resultado->dados;
        }
};

#endif