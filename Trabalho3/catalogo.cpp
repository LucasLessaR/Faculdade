/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Definicao das funcoes pertencentes a classe Catalogo e a struct Filme

*/


#include "Catalogo.h"

ostream& operator<<(ostream& out, Catalogo& catalogoInput){
    catalogoInput.tamanho = catalogoInput.listaFilmes.size();
    out << setw(30) << left << "Nome:\t" << setw(30) << left << "Produtora:\t" << "Nota:\n\n";

    for (unsigned int index = 0; index < catalogoInput.tamanho; index++){
        out << setw(30) << left << catalogoInput.listaFilmes.at(index).nomeFilme << "\t" << setw(30) << left 
            << catalogoInput.listaFilmes.at(index).nomeProdutora << "\t" << catalogoInput.listaFilmes.at(index).notaUser << endl;
    }

    return out;
}

Catalogo::Catalogo(){
    lerCatalogo();
}


Catalogo &Catalogo::operator+=(Filme &filmeInput){
    insercaoOrdenada(filmeInput);
    return *this;
}

Catalogo &Catalogo::operator+=(vector<Filme> &listaFilmeInput){
    unsigned int i = listaFilmes.size();
    if ((i + listaFilmeInput.size()) <= maxFilmes){
        for (unsigned int index = 0; index < listaFilmeInput.size(); index++){
            insercaoOrdenada(listaFilmeInput.at(index));
        }
    }
    else {
        cout << "\nNumero Maximo de filmes ja alocados." << endl;
    }
    return *this;
}

Catalogo &Catalogo::operator-=(Filme &filmeInput){
    tamanho = listaFilmes.size();
    unsigned int index;
    for (index = 0; index < tamanho; index++){
        if (listaFilmes.at(index) == filmeInput){
            for (unsigned int j = index; j < (tamanho-1); j++){
                listaFilmes.at(j) = listaFilmes.at(j+1);
            }
            listaFilmes.resize(tamanho-1);
            break;
        }
    }
    if (index != tamanho){
        cout << "\nFilme " << filmeInput.nomeFilme << " removido com sucesso" << endl;
    }
    else{
        cout << "\nO filme " << filmeInput.nomeFilme << " nao existe no catalogo" << endl;
    }
    return *this;
}


void Catalogo::insercaoOrdenada(Filme &filmeInput){
    if (listaFilmes.size() >= maxFilmes){ return; }
    for (unsigned int index = 0; index < listaFilmes.size(); index++){
        if (listaFilmes.at(index) == filmeInput){
            cout << "O filme " << filmeInput.nomeFilme << " ja existe\n" << endl;
            return;
        }
        if (listaFilmes.at(index) > filmeInput){
            listaFilmes.insert(listaFilmes.begin() + index, filmeInput);
            return;
        }
    }
    listaFilmes.push_back(filmeInput);
}


/*void Catalogo::insercaoOrdenada(Filme &filmeInput){
    tamanho = listaFilmes.size();
    if ((tamanho+1) <= maxFilmes){
        if (tamanho == 0) { listaFilmes.push_back(filmeInput);}
        else{
            // listaFilmes.resize(tamanho+1);
             tamanho = listaFilmes.size();
            for (unsigned int index = 0; index < tamanho; index++){
                if (listaFilmes.at(index) == filmeInput){
                    cout << "O filme " << filmeInput.nomeFilme << " ja existe\n" << endl;
                    listaFilmes.resize(tamanho-1);
                    break;
                }
                else if (listaFilmes.at(index) > filmeInput){
                    for (int j = (tamanho-1); j > (int) index; j--){
                        listaFilmes.at(j) = listaFilmes.at(j-1);
                    }
                    listaFilmes.insert(listaFilmes.begin() + (int)index, filmeInput);
                    break;
                }
            }
        }
    }
    else {
        cout << "\nNumero Maximo de filmes ja alocados." << endl;
    }
}*/

void Catalogo::lerCatalogo(){
    string strAux;
    Filme film;

    file.open(nomeFile, fstream::in);

    if(!file.is_open()){
        cout << "Erro ao abrir arquivo " << nomeFile << endl;
        return;
    }

    while(file.good()){
        while(!file.eof()){
            getline(file, strAux, '_');
            film.nomeFilme = strAux;
            getline(file, strAux, '_');
            film.nomeProdutora = strAux;
            getline(file, strAux);
            film.notaUser = stod(strAux);
            listaFilmes.push_back(film);
        }
    }
    file.close();
}

Filme* Catalogo::operator()(string nameInput){
    tamanho = listaFilmes.size();
    for (unsigned int index = 0; index < tamanho; index++){
        if ((listaFilmes.at(index).nomeFilme.compare(nameInput)) == 0){
            return &(listaFilmes.at(index));
        }
    }
    return NULL;
}

Filme* Catalogo::operator()(string nameInput, string produtoraInput){
    tamanho = listaFilmes.size();
    for (unsigned int index = 0; index < tamanho; index++){
        if ((listaFilmes.at(index).nomeFilme.compare(nameInput)) == 0){
            (listaFilmes.at(index).nomeProdutora) = produtoraInput;
            return &(listaFilmes.at(index));
        }
    }
    return NULL;
}

Filme* Catalogo::operator()(string nomeInput, double notaInput){
    tamanho = listaFilmes.size();

    if ((notaInput < 0.0) || (notaInput > 10.0)){
        cout << "Nota inserida invalida. Utilizar nota entre 0.0 e 10.0\n" << endl;
        exit (-1);
    }


    for (unsigned int index = 0; index < tamanho; index++){
        if ((listaFilmes.at(index).nomeFilme.compare(nomeInput)) == 0){
            (listaFilmes.at(index).notaUser) = notaInput;
            return &(listaFilmes.at(index));
        }
    }
    return NULL;
}

unsigned int Catalogo::melhorAvaliacao(){
    tamanho = listaFilmes.size();
    unsigned int index, posicao;
    float notaAux = 0.0;
    if (tamanho == 0){
        cout << "O catalogo nao possui filmes. Insira algum filme para saber qual possui melhor avaliacao.\n" << endl;
        return(0);
    }
    for (index = 0; index < tamanho; index++){
        if (listaFilmes.at(index).notaUser <= notaAux){}
        else{ 
            notaAux = listaFilmes.at(index).notaUser;
            posicao = index;
        }
    }
    cout << "O filme mais bem avaliado e: " << listaFilmes.at(posicao).nomeFilme << endl;
    cout << "Nota: " << notaAux << endl;
    return (1);
}

void Catalogo::salvarCatalogo(){
    stringstream strAux;
    string str;

    file.open(nomeFile, fstream::out);

    if(!file.is_open()){
        cout << "Erro ao abrir arquivo " << nomeFile << endl;
        return;
    }

    while(file.good()){
        for (unsigned int index = 0; index < listaFilmes.size(); index++){
            if (index != (listaFilmes.size() - 1)){
                strAux << listaFilmes.at(index).nomeFilme;
                strAux << "_";
                strAux << listaFilmes.at(index).nomeProdutora;
                strAux << "_";
                strAux << setprecision(3) << (listaFilmes.at(index).notaUser);
                getline(strAux, str);
                str += "\n";
                file << str;
                strAux.clear();
            }
            else{
                strAux << listaFilmes.at(index).nomeFilme;
                strAux << "_";
                strAux << listaFilmes.at(index).nomeProdutora;
                strAux << "_";
                strAux << setprecision(3) << (listaFilmes.at(index).notaUser);
                getline(strAux, str);
                file << str;
                strAux.clear();
            }
        }
        break;
    }
    file.close();
}


bool Filme::operator==(Filme filmeInput){
    if (this->nomeFilme.compare(filmeInput.nomeFilme) == 0){ return true; }
    else { return false; }
}

bool Filme::operator>(Filme filmeInput){
    if (this->nomeFilme.compare(filmeInput.nomeFilme) > 0) {return true;}
    else {return false;}
}

bool Filme::operator<=(double notaInput){
    if (this->notaUser <= notaInput) { return true;}
    else {return false;}
}

ostream& operator<< (ostream& out, Filme& filmeInput){
    out << setw(30) << left << "Nome\t" << setw(30) << left << "Produtora\t" << "Nota\n\n"; 
    out << setw(30) << left << filmeInput.nomeFilme << "\t" << setw(30) << left << filmeInput.nomeProdutora << "\t" << filmeInput.notaUser << endl;
    return out;
}

istream& operator>> (istream& in, Filme& filmeInput){
    string strAux;
    cout << "Insira nome do filme: \n";
    if (in.peek() == '\n'){ in.ignore();}
    getline(in, filmeInput.nomeFilme);
    cout << "Insira nome da produtora: \n";
    getline(in, filmeInput.nomeProdutora);
    cout << "Insira nota do filme: \n";
    getline(in, strAux);
    filmeInput.notaUser = stod(strAux);
    return in;
}