/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Arquivo com definicao da classe grafo

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "vertice.h"
#include "aresta.h"

using namespace std;

#ifndef GRAFO_H
#define GRAFO_H

class Grafo
{
    private:
        vector<Aresta*> combinacoes;        // vector com todas as arestas (grupos de N palavras) criadas
        vector<Vertice*> palavras;          // vector com todas as palavras do txt
        fstream file;                       // variavel que ira conter o arquivo txt
        string nomeArquivo;                 // nome do arquivo txt
        string conteudoArquivo = "";        // string para onde ira ser passado o conteudo do arquivo
        vector<string> ordemPalavras;       // vector com todas as palavras + "." para indicar quando houver interrupções devido a caracteres invalidos
        unsigned int N;                     // numero de termos por agrupamento

    public:
        Grafo(string /* Nome do Arquivo *.txt */, unsigned int /* numero de agrupamentos */);
        ~Grafo();

        void setN(unsigned int);                 // funcao para setar o valor de N
        void lerArquivo();                       // funcao para passar o conteudo do arquivo txt para uma string
        void insereVertice();                    // funcao para adicionar cada palavra separadamente dentro do vector palavras
        void insereAresta ();                    // funcao para adicionar cada agrupamento no vector combinacoes
        void printPalavraMaisUsada();            // funcao para printar palavra com maior numero de ocorrencias
        void printParMaisUsado();                // funcao para printar aresta (grupo formado por 2 palavras), com maior numero de ocorrencias
        void printNGrupoMaisUsado(unsigned int); // funcao para printar aresta (grupo formado por N palavras), com maior numero de ocorrencias
        void limparConteudos();                  // funcao para limpar todas as informacoes dessa classe

};

#endif