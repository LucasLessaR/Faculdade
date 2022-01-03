/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Arquivo com definição da classe paciente

*/

#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Paciente
{
    friend ostream& operator<<(ostream &out, Paciente& pacienteInput);
    private:
        string nome;
        unsigned int idade;
        
    public:
        Paciente();
        void setNome();
        string getNome();
        void setIdade();
        unsigned int getIdade();
        bool operator==(Paciente&);
        bool operator==(string&);
        bool operator>(Paciente&);
        bool operator>(string&);
};


class PacienteAgendado : public Paciente{
    friend ostream& operator<<(ostream &out, PacienteAgendado& pacienteInput);
    private:
        // Essa classe herda elementos private da classe Paciente (nome e idade);
        unsigned int dia;
        unsigned int mes;
        unsigned int ano;
        void setDia();
        void setMes();
        void setAno();

    public:
        PacienteAgendado():Paciente(){
            setDia();
            setMes();
            setAno();
        };
        unsigned int getDia();
        unsigned int getMes();
        unsigned int getAno();
};

#endif