#include <iostream>
#include <cstdlib>

//#include "Array.h"

using namespace std;

template <typename T, size_t size> T minElement(const T(&array)[size])
{
    T min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int main() {
    //Zadanie 2

    //Tablica statyczna
    
    cout << "Wyswietlanie liczb z tablicy statycznej:" << endl;
    int arrAdd[15];

    srand(time(0));
    for (int i = 0; i < 15; i++) {
        arrAdd[i] = rand();
        cout << "Liczba " << i << " : " << arrAdd[i] << endl;
    }

    cout << endl << "Minimalna liczba z tablicy statycznej: " << minElement(arrAdd) << endl;
    
    //Tablica dynamiczna

    /*cout << "Wyswietlanie liczb z tablicy dynamicznej:" << endl;
    int* arrAdd = new int[10];

    for (int i = 0; i < 10; i++) {
        *arrAdd = i;
        cout << "Liczba " << i << " : " << arrAdd << endl;
    }

    cout << endl << "Minimalna liczba z tablicy: " << minElement(arrAdd) << endl;
    */
    system("pause");
    return 0;
}
