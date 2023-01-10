//
// Created by maksi on 20.12.2022.
//

#ifndef LAB12_CAR_H
#define LAB12_CAR_H

#include <iostream>
using namespace std;

class Car {
private:
    string model;
    int rok;
    float pojemnosc;

public:
    Car(string model, int rok, float pojemnosc) : model(model), rok(rok), pojemnosc(pojemnosc) {};

    string getModel() const {
        return model;
    }
    int getRok() const {
        return rok;
    }
    float getPojemnosc() const {
        return pojemnosc;
    }

    void setModel(string model) {
        this->model = model;
    }
    void setRok(int rok) {
        this->rok = rok;
    }
    void setPojemnosc(float pojemnosc) {
        this->pojemnosc = pojemnosc;
    }

    void displayInfo() const {
        cout << "Model: " << model <<
            "\tRok produkcji: " << rok <<
            "\tPojemnosc silnika: " << pojemnosc << endl;
    }
};

#endif //LAB12_CAR_H
