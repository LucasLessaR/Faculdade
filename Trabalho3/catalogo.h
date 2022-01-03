/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Definicao da classe Catalogo e da struct Filme

*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

#ifndef CATALOGO_H
#define CATALOGO_H

struct Filme
{
    string nomeFilme;
    string nomeProdutora;
    double notaUser;

    bool operator==(Filme);
    bool operator>(Filme);
    bool operator<=(double);

    friend ostream& operator<< (ostream& , Filme&);
    friend istream& operator>> (istream& , Filme&);
};

class Catalogo
{
    friend ostream& operator<<(ostream &, Catalogo &);

    private:
        vector<Filme> listaFilmes;
        unsigned int tamanho;
        const unsigned int maxFilmes = 5;
        fstream file;
        string nomeFile = "catalogo.txt";

        void insercaoOrdenada (Filme &);
        void lerCatalogo();

    public:
        Catalogo();

        Catalogo &operator+=(Filme &);
        Catalogo &operator+=(vector<Filme> &);
        Catalogo &operator-=(Filme &);
        
        Filme* operator()(string);
        Filme* operator()(string, string);
        Filme* operator()(string, double);

        unsigned int melhorAvaliacao();
        void salvarCatalogo();

    

};

#endif