/*

 * UFRJ - Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * EEL670 - Linguagens de Programacao - 2020/2
 * Prof: Miguel Elias Mitre Campista
 * Autor: Lucas Lessa Rodrigues
 * Sobre: Definicao das funcoes da classe Nacional

*/

#include "nacional.h"

Nacional::Nacional (string countryNameInput, vector<Estadual> statesInput){
    countryName = countryNameInput;
    states = statesInput;

    // Copying total states dailyDeaths from each day to National daily deaths 
    for (unsigned int stateIndex = 0; stateIndex < statesInput.size(); stateIndex++){
        for (unsigned int dayIndex = 0; dayIndex < statesInput[stateIndex].getDailyDeaths().size(); dayIndex++){
            if (dayIndex >= dailyDeaths.size()){
                dailyDeaths.push_back(0);
            }
            dailyDeaths[dayIndex] += statesInput[stateIndex].getDailyDeaths()[dayIndex];
        }
    }

    // Calculate National moving average
    for (unsigned int averageIndex = 0; averageIndex < dailyDeaths.size() - N + 1; averageIndex++){
        float temp = 0;
        for (unsigned int deathIndex = (0 + averageIndex); deathIndex < (N + averageIndex); deathIndex++){
            temp += dailyDeaths[deathIndex];
        }
        movingAverage.push_back(temp/N); 
    }

    // Calculate National growth index
    unsigned int movingAverageIndex = movingAverage.size() - 1;
    unsigned int dailyDeathsIndex = dailyDeaths.size() - 1; 
    if (dailyDeaths[dailyDeathsIndex] == 0){
        growthIndex = 0;
    }
    else{
        growthIndex = (movingAverage[movingAverageIndex]/dailyDeaths[dailyDeathsIndex]) - 1;
    }
}

string Nacional::getName (){
    return countryName;
}

vector<Estadual> Nacional::getStates (){
    return states;
}

vector<float> Nacional::getMovingAverage(){
    return movingAverage;
}

vector<int> Nacional::getDailyDeaths(){
    return dailyDeaths;
}

float Nacional::getGrowthIndex(){
    return growthIndex;
}

void Nacional::printMovingAverage(){
    cout << "\n\t\tMedia Movel feita com grupos de " << N << " dias" << endl;
    for (unsigned int stateIndex = 0; stateIndex < getStates().size(); stateIndex++){
        cout << getStates()[stateIndex].getName() << ":\t";
        for (unsigned int averageIndex = 0; averageIndex < getStates()[stateIndex].getMovingAverage().size(); averageIndex++){
            cout << getStates()[stateIndex].getMovingAverage()[averageIndex] << "\t";
        }
        cout << endl;
    }

}

// Checked states growth index to put then on the right group
// Status where:
// Growing: growthIndex > 15%
// Stabilized: -15% < growthIndex < 15%
// Decay: growthIndex < -15%

void Nacional::printStateGroup(){
    cout << "\n\t\tStatus dos Estados" << endl;
    cout << "Estados em Alta" << endl;
    for (unsigned int stateIndex = 0; stateIndex < getStates().size(); stateIndex++){
        if (getStates()[stateIndex].getGrowthIndex() > 0.15){
            cout << getStates()[stateIndex].getName() << ":\t" << getStates()[stateIndex].getGrowthIndex()*100 << "%\tEm Alta" << endl;
        }
    }
    cout << "\nEstados em Baixa" << endl;
    for (unsigned int stateIndex = 0; stateIndex < getStates().size(); stateIndex++){
        if (getStates()[stateIndex].getGrowthIndex() < (-0.15)){
            cout << getStates()[stateIndex].getName() << ":\t" << getStates()[stateIndex].getGrowthIndex()*100 << "%\tEm Baixa" << endl;
        }
    }
    cout << "\nEstados em Estabilidade" << endl;
    for (unsigned int stateIndex = 0; stateIndex < getStates().size(); stateIndex++){
        if ((getStates()[stateIndex].getGrowthIndex() < 0.15) && (getStates()[stateIndex].getGrowthIndex() > (-0.15))){
            cout << getStates()[stateIndex].getName() << ":\t" << getStates()[stateIndex].getGrowthIndex()*100 << "%\tEm Estabilidade" << endl;
        }
    }
}

// Same status where used to country
void Nacional::printCountryStatus(){
    cout << "\n\t\tStatus do Pais" << endl;
    if (growthIndex > 0.15){
        cout << getName() << ":\t" << getGrowthIndex()*100 << "%\tEm Alta" << endl;
    }
    else if (growthIndex < (-0.15)){
        cout << getName() << ":\t" << getGrowthIndex()*100 << "%\tEm Baixa" << endl;
    }
    else{
        cout << getName() << ":\t" << getGrowthIndex()*100 << "%\tEm Estabilidade" << endl;
    }
}

// To check who has the higher and lower moving average, it's initialized an higher and lower variables, and then it's compared each country growthIndex to these 2 variables, where if it's higher (for higher variable), or lower (for lower variable), the value of the variables is changed to the moving average of said state.
// Despite that, it's used string variables to store the name of these states as well
void Nacional::printGrowthFall(){
    float higher = 0.0;
    float lower = 10000000.0;
    string highStateName;
    string lowStateName;

    for (unsigned int stateIndex = 0; stateIndex < getStates().size(); stateIndex++){
        if (getStates()[stateIndex].getMovingAverage()[getStates()[stateIndex].getMovingAverage().size() - 1] > higher){
            higher = getStates()[stateIndex].getMovingAverage()[getStates()[stateIndex].getMovingAverage().size() - 1];
            highStateName = getStates()[stateIndex].getName();
        }
        else if(getStates()[stateIndex].getMovingAverage()[getStates()[stateIndex].getMovingAverage().size() - 1] < lower){
            lower = getStates()[stateIndex].getMovingAverage()[getStates()[stateIndex].getMovingAverage().size() - 1];
            lowStateName = getStates()[stateIndex].getName();
        }
    }

    cout << "\n\tEstado Com Maior Media Movel" << endl;
    cout << highStateName << ":\t" << higher << endl;
    cout << "\n\tEstado com Menor Media Movel" << endl;
    cout << lowStateName << ":\t" << lower << endl;
}

// This function summs all deaths for each state and country
void Nacional::printAllDeaths(){
    cout << "\n\t\tTotal Obitos por Estado" << endl;
    int totalDeathsCountry = 0;
    for (unsigned int stateIndex = 0; stateIndex < getStates().size(); stateIndex++){
        int totalDeathsState = 0;
        for (unsigned int dailyDeathsIndex = 0; dailyDeathsIndex < getStates()[stateIndex].getDailyDeaths().size(); dailyDeathsIndex++){
            totalDeathsState += getStates()[stateIndex].getDailyDeaths()[dailyDeathsIndex];
        }
        totalDeathsCountry += totalDeathsState;
        cout << getStates()[stateIndex].getName() << ":\t" << totalDeathsState << "\tobitos" << endl;
    }
    cout << "\n\t\tTotal Obitos Pais" << endl;
    cout << getName() << ":\t" << totalDeathsCountry << "\tobitos\n" << endl;
}