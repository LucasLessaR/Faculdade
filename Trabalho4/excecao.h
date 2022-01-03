/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Arquivo com definição da classe excecao

*/

#ifndef EXCECAO_H
#define EXCECAO_H

#include <iostream>
#include <exception>

using namespace std;

class DuplicadaExcecao : public exception{
    private:
    public:
        virtual const char* what() const noexcept { return "Esse paciente ja existe.\n";}
};

class NaoExisteExcecao : public exception{
    private:
    public:
        virtual const char* what() const noexcept { return "Paciente nao existe.\n";} 
};

#endif