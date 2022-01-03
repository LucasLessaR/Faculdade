/*

 * UFRJ - Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * EEL670 - Linguagens de Programacao - 2020/2
 * Prof: Miguel Elias Mitre Campista
 * Autor: Lucas Lessa Rodrigues
 * Sobre: Definicao classe estadual onde estarao presentes todos os dados referentes a um estado

*/

#ifndef __ESTADUAL__
#define __ESTADUAL__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Estadual {
    private:
        string stateName;
        vector<int> dailyDeaths;   // daily deaths of last N days 
        vector<float> movingAverage;   // moving average of deaths
        float growthIndex;      // Index to indicate growth in daily deaths in comparison to last N days
        unsigned int N = 7;     // N days used to calculate moving average

    public:
        Estadual (string, vector<int> );    // Constructor to class Estadual
        string getName();                   // Function to get state name
        vector<int> getDailyDeaths ();      // Function to get vector with daily deaths
        vector<float> getMovingAverage ();  // Function to get vector with moving average
        float getGrowthIndex();             // Function to get growthIndex        
};

#endif