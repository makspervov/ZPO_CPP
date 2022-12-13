#include <iostream>
#include "Employee.h"
#include "Developer.h"
#include "TeamLeader.h"
using namespace std;

void whoWorkMoreThan5Years(Employee** array, int size){
    for (int i = 0; i < size - 1; ++i) {
        if(array[i]->getExperience() > 5){
            cout << array[i]->getSurname()<<" works more than 5 years." << endl;
        }
    }
}

void howManyEarnLessThanMeanBonus(Employee** array, int size){
    int counter = 0;
    int averageBonus = 0;
    for(int i =0; i < size - 1; ++i){
        averageBonus += array[i]->calculateBonus(1);
    }
    averageBonus = averageBonus / size - 1;
    for(int i = 0; i < size - 1; ++i){
        if(array[i]->calculateBonus(2) < averageBonus){
            counter++;
        }
    }
    cout << counter << " people get less bonus thank average of all bonuses." << endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    Employee** e4;
    e4 = new Employee * [5];
    e4[0] = new Developer("Bortsov", 22, 4, 1400);
    e4[1] = new TeamLeader("Frew",35, 8, 7000);
    e4[2] = new Developer("Steal", 19, 1, 800);
    e4[3] = new TeamLeader("Bondar", 18, 5, 20000);
    e4[4] = new Developer("Bukhanets", 28, 1, 659);

    for(int i = 0; i < 4; ++i){
        e4[i]->show();
    }

    whoWorkMoreThan5Years(e4, 4);
    howManyEarnLessThanMeanBonus(e4, 4);

    return 0;
}

