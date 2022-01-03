/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Arquivo com definição da classe paciente

*/

#include "paciente.h"


ostream& operator<<(ostream& out, Paciente& pacienteInput){
    out << "\nNome: " << pacienteInput.getNome() << "\tIdade: " << pacienteInput.getIdade() << endl;
    return out;
}

Paciente::Paciente(){
    setNome();
    setIdade();
}

void Paciente::setNome(){
    string name;
    cout << "\nEntra com nome: ";
    cin >> name;
    nome = name;
}

string Paciente::getNome(){
    return nome;
}

void Paciente::setIdade(){
    string aux;
    cout << "\nEntra com idade: ";
    cin >> aux;
    idade = stoul(aux, nullptr);
}

unsigned int Paciente::getIdade(){
    return idade;
}

bool Paciente::operator==(Paciente& pacienteIn){
    if (this->getNome() == pacienteIn.getNome()){ return true;}
    else{ return false; }
}

bool Paciente::operator==(string& nome){
    if (this->getNome() == nome){ return true;}
    else{ return false; }
}

bool Paciente::operator>(Paciente& pacienteIn){
    if (this->getNome() > pacienteIn.getNome()){ return true;}
    else{ return false; }
}

bool Paciente::operator>(string& nome){
    if (this->getNome() == nome){ return true;}
    else{ return false; }
}

void PacienteAgendado::setDia(){
    string aux;
    cout << "\nInsira o Dia da consulta (Numeros apenas): ";
    while(1){    
        cin >> aux;
        dia = stoul(aux, nullptr);
        if (dia < 32 && dia > 0){
            break;
        }
        cout << "Entrada Invalida! Insira um dia numerico valido" << endl;
    }
}

void PacienteAgendado::setMes(){
    string aux;
    cout << "\nInsira o Mes da consulta (Numeros apenas): ";
    while(1){
        cin >> aux;
        mes = stoul(aux, nullptr);
        if (mes < 13 && mes > 0){
            break;
        }
        cout << "Entrada Invalida! Insira um mes numerico valido" << endl;
    }
}

void PacienteAgendado::setAno(){
    string aux;
    cout << "\nInsira o Ano da consulta (Numeros apenas): ";
    while(1){
        cin >> aux;
        ano = stoul(aux, nullptr);
        if (ano > 2020){
            break;
        }
        cout << "Entrada invalida! Insira um ano valido" << endl;
    }
}

unsigned int PacienteAgendado::getDia(){
    return dia;
}

unsigned int PacienteAgendado::getMes(){
    return mes;
}

unsigned int PacienteAgendado::getAno(){
    return ano;
}

ostream& operator<<(ostream &out, PacienteAgendado& pacienteInput){
    out << "\nNome: " << pacienteInput.getNome() 
        << "\tIdade: " << pacienteInput.getIdade() 
        << "\tData Agendamento: " << pacienteInput.getDia() << "/" << pacienteInput.getMes() << "/" << pacienteInput.getAno() << endl;
    return out;
}