/*
*	UFRindicePalavra - Universidade Federal do Rio de indicePalavraaneiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Arquivo com definicao das funcoes da classe grafo

*/

#include "grafo.h"

Grafo::Grafo(string nameInput, unsigned int nGrupos){
    nomeArquivo = nameInput;
    setN(nGrupos);
}

Grafo::~Grafo(){
    for (unsigned int index = 0; index < palavras.size(); index++){
        delete palavras.at(index);
    }

    for (unsigned int index = 0; index < combinacoes.size(); index++){
        delete combinacoes.at(index);
    }
}

void Grafo::limparConteudos(){
    palavras.clear();
    combinacoes.clear();
    ordemPalavras.clear();
    conteudoArquivo = "";
}

// N recebe numero maximo de palavras por agrupamento
void Grafo::setN(unsigned int nInput){
    N = nInput;
}

// funcao para passar o conteudo do arquivo txt para uma string 
void Grafo::lerArquivo(){
    file.open (nomeArquivo, fstream::in);

    if (!file.is_open()){   // checagem de erro na abertura do arquivo
        cout << "Erro ao abrir arquivo " << nomeArquivo << endl;
        return;
    }

    // enquanto nao tiver problemas no arquivo txt, até chegar no eof irá passar caracter por caracter para a string conteudoArquivo
    while (file.good()){    
        while (!file.eof()){
            conteudoArquivo.push_back(file.get());
        }
    }
    file.close();
}

// funcao para adicionar cada palavra separadamente dentro do vector palavras
void Grafo::insereVertice(){
    Vertice *word;
    string stringAux = "";
    unsigned int indiceString = 0;
    unsigned int indicePalavra = 0;

    lerArquivo();

    // iteração para passar caracter por caracter na string que contem todo conteudo do arquivo txt
    for (indiceString = 0; indiceString <= conteudoArquivo.size(); indiceString++){
        // checagem para condicoes que indicam final de uma palavra
        // 1- caracter igual a ' ' (espaço)
        // 2- caracter igual a EOS
        // 3- caracter igual a algum simbolo e fora dos espacos (0,1,2,...,9), (A, B, ..., Z) e (a, b, ..., z), além do caracter '-' para palavras que o utilizam
        if (((conteudoArquivo[indiceString] == ' ') || (conteudoArquivo[indiceString] == '\0')) ||
            ((((conteudoArquivo[indiceString +1] >= '0') && (conteudoArquivo[indiceString+1] <= '9')) || ((conteudoArquivo[indiceString+1] >= 'A') && (conteudoArquivo[indiceString+1] <= 'Z')) || ((conteudoArquivo[indiceString+1] >= 'a') && (conteudoArquivo[indiceString+1] <= 'z')))
                && ((conteudoArquivo[indiceString] < '0') || ((conteudoArquivo[indiceString] > '9') && (conteudoArquivo[indiceString] < 'A')) || ((conteudoArquivo[indiceString] > 'Z') && (conteudoArquivo[indiceString] < 'a')) || (conteudoArquivo[indiceString] > 'z')) && (conteudoArquivo[indiceString] != '-'))){
            // criacao de ponteiro para objeto temporario da classe Vertice
            word = new Vertice(stringAux);
            // inserção no vector palavras da classe grafo quando o mesmo estiver vazio
            if (palavras.size() == 0){
                word->addRepeticao();
                palavras.push_back(word);
                ordemPalavras.push_back(stringAux); // ao mesmo tempo se coloca as palavras nesse vetor ordemPalavras para auxiliar na criacao das arestas (agrupamentos)
            }
            else {
                indicePalavra = 0;
                ordemPalavras.push_back(stringAux);
                // iteracao onde se compara palavra por palavra por palavra do vector palavras para verificar existencia de repeticao
                while ((indicePalavra < palavras.size()) && (palavras.at(indicePalavra)->getPalavra().compare(stringAux) != 0))
                {
                    indicePalavra++;
                }
                // caso indicePalavra nao alcance o tamanho do vector palavras, significa que a palavra da vez é uma repeticao
                if (indicePalavra != (palavras.size())){
                    palavras.at(indicePalavra)->addRepeticao();
                }
                else{
                    word->addRepeticao();
                    palavras.push_back(word);
                    // caso o caracter anterior seja um simbolo invalido, adicionamos um "." no vector ordemPalavras. Esse "." irá indicar interrupções na string que não permitam a criação de uma aresta (agrupamento) do tamanho de N
                    if ((conteudoArquivo[indiceString] != '-') && (conteudoArquivo[indiceString] == ' ') && ((conteudoArquivo[indiceString-1] < '0') || (conteudoArquivo[indiceString-1] > '9' && conteudoArquivo[indiceString-1] < 'A') || (conteudoArquivo[indiceString-1] > 'Z' && conteudoArquivo[indiceString-1] < 'a') || (conteudoArquivo[indiceString-1] > 'z'))){
                        stringAux = ".";
                        ordemPalavras.push_back(stringAux);
                    }
                }
                
            }
            stringAux = "";
        }
        // caso exista uma repeticao de simbolos invalidos, esse elseif irá apenas pula-los
        else if ((conteudoArquivo[indiceString] != '-') && (conteudoArquivo[indiceString] != ' ') && ((conteudoArquivo[indiceString] < '0') || (conteudoArquivo[indiceString] > '9' && conteudoArquivo[indiceString] < 'A') || (conteudoArquivo[indiceString] > 'Z' && conteudoArquivo[indiceString] < 'a') || (conteudoArquivo[indiceString] > 'z'))){ }
        else{
            stringAux.push_back(conteudoArquivo[indiceString]); // adicao dos caracteres numa string auxiliar para insercao no vector de vertices depois
        }
    }
}

void Grafo::insereAresta(){
    unsigned int indexPalavras, indexGrupo;
    vector<Vertice*> vectorAux; 
    Aresta* arestaAux;

    indexPalavras = 0;
    while (indexPalavras < ordemPalavras.size()){   // passar por todas as palavras salvas no vector com palavras e interrupções por caracteres inválidos 
        indexGrupo = 0;
        while((indexGrupo < N)){   // agrupar de N em N palavras, ou até quando achar uma interrupção
            if ((indexPalavras + indexGrupo) >= ordemPalavras.size()){
                break;
            }
            else{
                // Checagem para saber se precisa interromper a criacao do vector auxiliar devido a uma interrupcao 
                if (ordemPalavras.at(indexPalavras + indexGrupo) != "."){
                    vectorAux.push_back(new Vertice (ordemPalavras.at(indexPalavras + indexGrupo)));   // Agrupar palavras num vector auxiliar
                    indexGrupo++;
                }
                else{
                    break;
                }
            }
        }

        arestaAux = new Aresta (vectorAux, indexGrupo);    // Criar uma aresta auxiliar com vertices (palavras) agrupadas e indexGrupo representa o numero de vertices agrupados

        if(combinacoes.size() == 0){   // Adiciona uma ocorrência e aloca uma primeira aresta automaticamente
            arestaAux->addOcorrencia();
            combinacoes.push_back(arestaAux);
        }
        else{
            unsigned int indexAux;
            bool igual = false;
            for (indexAux = 0; (indexAux < combinacoes.size()); indexAux++) { 
                // checagem se a aresta da posicao atual possui o mesmo numero de palavras armazenadas que a aresta auxiliar criada
                if (arestaAux->getVertice().size() == combinacoes.at(indexAux)->getVertice().size()){
                    if(combinacoes.at(indexAux)->verificaAresta(arestaAux->getVertice()) == 0){
                        igual = true;
                        break;
                    }
                }
            }
            if (igual){
                combinacoes.at(indexAux)->addOcorrencia();
                delete arestaAux;
            }
            else{
                arestaAux->addOcorrencia();
                combinacoes.push_back(arestaAux);
            }
        }
        vectorAux.clear();  // limpeza do conteudo do vector auxiliar

        // condicao para caso no indicePalavras atual seja uma interrupcao ("."). Caso seja, adicionamos (indexGrupo + 1) para pular a mesma
        if (indexGrupo < N){
            indexPalavras += indexGrupo + 1;
        }
        else{
            indexPalavras++;
        }
    }
}

void Grafo::printPalavraMaisUsada(){
    unsigned int index, indexAparicao;
    unsigned int maiorAparicao = 0;

    // limpamos os conteudos armazenados na classe para fazermos uma nova insercao
    limparConteudos();
    insereVertice();
    // checagem para qual palavra possui maior numero de repeticoes
    for (index = 0, indexAparicao = 0; index < palavras.size(); index++){
        if(palavras.at(index)->getRepeticao() > maiorAparicao){
            maiorAparicao = palavras.at(index)->getRepeticao();
            indexAparicao = index;
        }
    }

    cout << "\nPalavra mais utilizada:\t" << palavras.at(indexAparicao)->getPalavra() << "\t" << palavras.at(indexAparicao)->getRepeticao() << endl;
}

void Grafo::printParMaisUsado(){
    unsigned int index, indexAparicao, maiorAparicao = 0;
    unsigned int nValue = 2;

    limparConteudos();
    setN(nValue);
    insereVertice();
    insereAresta();

    // checagem para qual numero de pares de palavras seguidas possui maior numero de repeticoes
    for (index = 0, indexAparicao = 0; index < combinacoes.size(); index++){
        if(combinacoes.at(index)->getOcorrencia() > maiorAparicao){
            maiorAparicao = combinacoes.at(index)->getOcorrencia();
            indexAparicao = index;
        }
    }

    cout << "\nPar de palavras mais utilizado:\t" 
         << combinacoes.at(indexAparicao)->getVertice().at(0)->getPalavra() << " " 
         << combinacoes.at(indexAparicao)->getVertice().at(1)->getPalavra() << "\t"
         << combinacoes.at(indexAparicao)->getOcorrencia()
         << endl;

}

void Grafo::printNGrupoMaisUsado(unsigned int nValue){
    unsigned int index, indexAparicao, maiorAparicao = 0;

    limparConteudos();
    setN(nValue);
    insereVertice();
    insereAresta();

    // checagem para qual N palavras seguidas possui maior numero de repeticoes
    for (index = 0, indexAparicao = 0; index < combinacoes.size(); index++){
        if(combinacoes.at(index)->getOcorrencia() > maiorAparicao){
            maiorAparicao = combinacoes.at(index)->getOcorrencia();
            indexAparicao = index;
        }
    }

    cout << "\nGrupo de N palavras mais utilizado:\t";
    for (index = 0; index < combinacoes.at(indexAparicao)->getVertice().size(); index++){
        cout << combinacoes.at(indexAparicao)->getVertice().at(index)->getPalavra() << " ";
    }
    cout << combinacoes.at(indexAparicao)->getOcorrencia();
    cout << endl;
}