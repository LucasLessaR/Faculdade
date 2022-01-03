/*

 * UFRJ - Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * EEL670 - Linguagens de Programacao - 2020/2
 * Prof: Miguel Elias Mitre Campista
 * Autor: Lucas Lessa Rodrigues
 * Sobre: Definicao classe Nacional onde estarao presentes todos os dados referentes ao pais

*/

#include <iostream>
#include <string>
#include <vector>
#include "estadual.h"
#include "nacional.h"

using namespace std;

int main (){
    Estadual AC ("Acre", {0, 0, 0, 0, 0, 0, 0, 0, 0});
    Estadual AL ("Alagoas", {149, 278, 626, 415, 35, 279, 146, 538, 144});
    Estadual AP ("Amapa", {235, 366, 303, 207, 172, 45, 161, 512, 210});
    Estadual AM ("Amazonas", {346, 79, 296, 273, 17, 614, 610, 696, 200});
    Estadual BA ("Bahia", {66, 680, 143, 362, 606, 194, 241, 162, 498});
    Estadual CE ("Ceara", {57, 73, 158, 363, 603, 588, 590, 194, 135});
    Estadual DF ("Distrito Federal", {694, 140, 436, 177, 208, 207, 66, 280, 376});
    Estadual ES ("Espirito Santo", {526, 351, 559, 307, 395, 548, 406, 3, 654});
    Estadual GO ("Goias", {458, 227, 229, 323, 642, 660, 515, 425, 107});
    Estadual MA ("Maranhao", {426, 511, 208, 182, 68, 107, 607, 380, 227});
    Estadual MT ("Mato Grosso", {164, 85, 634, 116, 81, 432, 34, 184, 358});
    Estadual MS ("Mato Grosso do Sul", {197, 352, 633, 625, 550, 699, 408, 288, 385});
    Estadual MG ("Minas Gerais", {356, 321, 452, 323, 265, 58, 65, 537, 586});
    Estadual PA ("Para", {316, 74, 123, 401, 157, 215, 300, 683, 416});
    Estadual PB ("Paraiba", {167, 56, 26, 604, 66, 570, 556, 676, 317});
    Estadual PR ("Parana", {198, 83, 138, 540, 501, 577, 499, 417, 186});
    Estadual PE ("Pernambuco", {267, 635, 70, 77, 402, 296, 146, 188, 645});
    Estadual PI ("Piaui", {105, 322, 213, 396, 465, 178, 219, 621, 61});
    Estadual RJ ("Rio de Janeiro", {62, 343, 70, 432, 296, 32, 426, 33, 186});
    Estadual RN ("Rio Grande do Norte", {159, 544, 225, 615, 543, 594, 290, 255, 57});
    Estadual RS ("Rio Grande do Sul", {504, 266, 587, 588, 320, 313, 632, 95, 353});
    Estadual RO ("Rondonia", {213, 365, 177, 330, 438, 312, 305, 465, 126});
    Estadual RR ("Roraima", {389, 127, 249, 319, 99, 436, 479, 476, 16});
    Estadual SC ("Santa Catarina", {591, 59, 175, 353, 628, 516, 23, 381, 240});
    Estadual SP ("Sao Paulo", {431, 98, 259, 578, 556, 2, 44, 220, 58});
    Estadual SE ("Sergipe", {387, 70, 697, 582, 24, 1, 518, 466, 192});
    Estadual TO ("Tocantins", {643, 390, 116, 250, 230, 394, 555, 478, 691});

    Nacional BR ("Brasil", {AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB, PR, PE, PI, RJ, RN, RS, RO, RR, SC, SP, SE, TO});

    unsigned int option;

    // Loop to show user option until decided to quit program
    while (1){
        cout << "\n\t\tMenu Covid-19\n"
            << "1 - Media movel dos Estados e do Pais;\n"
            << "2 - Exibir de forma agrupada os Estados com relacao ao indice de crescimento de obitos;\n"
            << "3 - Exibir indice de crescimento de obitos do Pais;\n"
            << "4 - Exibir Estados com Maior Alta e Maior Baixa do Indice de Crescimento de obitos;\n"
            << "5 - Exibir Total de obitos dos Estados e do Pais;\n"
            << "0 - Sair;\n"
            << "Insira a opcao desejada: ";
        cin >> option;
        
        
        switch (option)
        {
        case 0:
            cout << "Voce esta saindo! Ate a proxima." << endl;
            exit(1);
            break;

        case 1:
            BR.printMovingAverage();
            break;

        case 2:
            BR.printStateGroup();
            break;

        case 3:
            BR.printCountryStatus();
            break;

        case 4:
            BR.printGrowthFall();
            break;

        case 5:
            BR.printAllDeaths();
            break;
            
        default:
            cout << "Opcao Invalida!\n" << "Utilize apenas as opcoes do menu.\n" << endl;
            break;
        }

    }

    return 0;
}