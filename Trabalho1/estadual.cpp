/*
 * UFRJ - Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * EEL670 - Linguagens de Programacao - 2020/2
 * Prof: Miguel Elias Mitre Campista
 * Autor: Lucas Lessa Rodrigues
 * Sobre: Definicao das funcoes da classe Estadual 
 * 
*/

#include "estadual.h"

// All states data is unchengeable. Moving average and growth index were calculated in the constructor. Later is used get() functions to retrieve any data from class Estadual
Estadual::Estadual(string nameInput, vector<int> dailyDeathsInput){
    stateName = nameInput;
    dailyDeaths = dailyDeathsInput;

    // Moving average calculation.
    // For each state go by N days and calculate the average of deaths. 
    for (unsigned int averageIndex = 0; averageIndex < dailyDeathsInput.size() - N + 1; averageIndex++){
        float temp = 0;
        for (unsigned int deathIndex = (0 + averageIndex); deathIndex < (N + averageIndex); deathIndex++){
            temp += dailyDeathsInput[deathIndex];
        }
        movingAverage.push_back(temp/N); 
    }

    // Growth Index calculation.
    // Percent growth of daily death with relation to moving average on last day presented.
    unsigned int movingAverageIndex = movingAverage.size() - 1;
    unsigned int dailyDeathsIndex = dailyDeaths.size() - 1; 
    // This if is for cases where daily deaths is equal 0, which would result in a nan.
    if (dailyDeaths[dailyDeathsIndex] == 0){
        growthIndex = 0;
    }
    else{
        growthIndex = (movingAverage[movingAverageIndex]/(float)dailyDeaths[dailyDeathsIndex]) - 1;
    }
}

string Estadual::getName(){
    return stateName;
}

vector<int> Estadual::getDailyDeaths(){
    return dailyDeaths;
}

vector<float> Estadual::getMovingAverage(){
    return movingAverage;
}

float Estadual::getGrowthIndex(){
    return growthIndex;
}