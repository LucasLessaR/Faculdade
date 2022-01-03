/*
*	UFRJ - Universidade Federal do Rio de Janeiro
*	Escola Politecnica
*	Departamento de Eletronica e de Computacao
*	EEL670 - Linguagem de Programacao - Turma 2020/2
*	Prof. Miguel Elias Mitre Campista
*	Autor: Lucas Lessa Rodrigues
*	Descricao: Programa principal para uso das funcoes da classe Catalogo

*/

#include "Catalogo.h"

int main (){
    unsigned int opcao, quantidade;
    string nomeFilme, nomeProdutora;
    double notaUsuario;
    Catalogo cataloguinho;
    

    while (1){
        cout << "\tMenu Principal:" << endl;
        cout << "1) Insercao de Filme no Catalogo;" << endl;
        cout << "2) Remocao de Filme do Catalogo;" << endl;
        cout << "3) Busca de um Filme no Catalogo;" << endl;
        cout << "4) Edicao de um Filme no Catalogo;" << endl;
        cout << "5) Imprimir Catalogo e Filme em exibicao;" << endl;
        cout << "6) Filme mais bem avaliado;" << endl;
        cout << "0) Sair." << endl;
        cout << "\n\nInsira a opcao desejada: ";
        cin >> opcao;
        switch (opcao)
        {
            case 0:{
                cataloguinho.salvarCatalogo();
                cout << "Finalizando Programa! Ate a proxima." << endl;
                exit(0);
            }

            case 1:{
                cout << "Voce deseja inserir quantos filmes?" << endl;
                cout << "Quantidade: ";
                cin >> quantidade;
                if (quantidade <= 0){
                    cout << "Quantidade invalida. Para essa operacao é necessario de pelo menos 1 filme.\n\n";
                    break;
                }
                else{
                    if (quantidade == 1){
                        cout << "Preencha as informacoes a seguir sobre o filme:\n";
                        Filme filmLocal;
                        cin >> filmLocal;
                        cataloguinho += filmLocal;
                        cout << "Filme adicionado com sucesso\n" << endl;
                    }
                    else{
                        vector<Filme> listaFilme;
                        for (unsigned int index = 0; index < quantidade; index++){
                            cout << "Preencha as informacoes a seguir sobre o filme (" << (index + 1) << "):\n";
                            Filme filmLocal;
                            cin >> filmLocal;
                            listaFilme.push_back(filmLocal);
                        }
                        for (unsigned int i = 0; i < listaFilme.size(); i++){
                            cout << listaFilme[i].nomeFilme;
                            cout << endl;
                        }
                        cataloguinho += listaFilme;
                        cout << "Filmes adicionados com sucesso\n\n";
                    }
                }
                break;
            }

            case 2:{
                cout << "Digite o NOME do filme que deseja remover do catalogo.\n";
                cout << "Nome: ";
                cin >> nomeFilme;
                Filme* filmAux;
                filmAux = cataloguinho(nomeFilme);
                if (filmAux == NULL){
                    cout << "O filme desejado nao existe no catalogo. Verifique se o nome digitado esta correto.\n\n";
                    break;
                }
                else{
                    cataloguinho -= *filmAux;
                    cout << "\n";
                }
                break;
            }

            case 3:{
                cout << "Digite o NOME do filme que deseja buscar no catalogo.\n";
                cout << "Nome: ";
                cin >> nomeFilme;
                Filme* filmAux;
                filmAux = cataloguinho(nomeFilme);
                if (filmAux == NULL){
                    cout << "O filme desejado nao existe no catalogo. Verifique se o nome digitado esta correto.\n" << endl;
                    break;
                }
                else{
                    cout << "O filme escolhido foi: " << endl;
                    cout << *filmAux << "\n\n";
                }
                break;
            }

            case 4:{
                cout << "Digite o NOME do filme que deseja alterar uma informacao.\n";
                cout << "Nome: ";
                cin >> nomeFilme;
                cout << "\nQual informacao deseja alterar? (Escolha o numero da opcao desejada)" << endl;
                cout << "(0) Nome da Produtora;\n";
                cout << "(1) Nota do filme.\n";
                cout << "Opcao: ";
                cin >> opcao;
                cout << "\n";
                if ((opcao < 0) || (opcao > 1)){
                    cout << "Opcao Invalida! Escolha uma das opcoes apresentadas da proxima vez.\n" << endl;
                    break;
                }
                else if (opcao == 0){
                    cout << "Escreva o novo NOME da PRODUTORA: ";
                    cin >> nomeProdutora;
                    Filme* filmAux;
                    filmAux = cataloguinho(nomeFilme, nomeProdutora);
                    if (filmAux == NULL){
                        cout << "O filme desejado nao pode ser encontrado! Verifique da proxima vez se os nomes digitados estao corretos.\n" << endl;
                        break;
                    }
                    else{
                        cout << *filmAux;
                    }
                }
                else{
                    cout << "Escreva a nova NOTA do filme: ";
                    cin >> notaUsuario;
                    Filme* filmAux;
                    filmAux = cataloguinho(nomeFilme, notaUsuario);
                    if (filmAux == NULL){
                        cout << "O filme desejado nao pode ser encontrado! Verifique da proxima vez se os nomes digitados estao corretos.\n" << endl;
                        break;
                    }
                    else{
                        cout << *filmAux;
                    }
                }
                break;
            }

            case 5:{
                cout << cataloguinho;
                cout << endl;
                break;
            }

            case 6:{
                cataloguinho.melhorAvaliacao();
                break;
            }

            default:{
                cout << "\tOpcao Invalida!\n" << "Utilize os numeros das opcoes para selecionar a opcao desejada." << endl;
                break;
            }
        }
    }

    return 0;
}