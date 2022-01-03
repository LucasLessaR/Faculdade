/*

 * UFRJ - Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * EEL670 - Linguagens de Programacao - 2020/2
 * Prof: Miguel Elias Mitre Campista
 * Autor: Lucas Lessa Rodrigues
 * Sobre: Definicao classe Nacional onde estarao presentes todos os dados referentes ao pais

*/

#ifndef __NACIONAL__
#define __NACIONAL__

#include <iostream>
#include <string>
#include <vector>
#include "estadual.h"

using namespace std;

class Nacional {
    private:
        string countryName;
        vector<Estadual> states;
        vector<float> movingAverage;
        vector<int> dailyDeaths;
        float growthIndex;
        unsigned int N = 7;
    
    public:
        Nacional (string, vector<Estadual>);
        string getName();
        vector<Estadual> getStates();
        vector<float> getMovingAverage();
        vector<int> getDailyDeaths();
        float getGrowthIndex();
        
        void printMovingAverage();  // Function to print moving average of all days possible from all states and a coutry
        void printStateGroup();     // Function to print states status in groups according to their growth index
        void printCountryStatus();  // Function to print country status according to it's growths index
        void printGrowthFall();     // Function to print the state with higher and lower moving average
        void printAllDeaths();      // Function to print all deaths that happened until now from all states and the country
};

#endif