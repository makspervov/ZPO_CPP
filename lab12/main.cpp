#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <tuple>
#include "Car.h"

using namespace std;

void print_menu() {
    system("cls");
    system("color 0F");
    cout << "Laboratorium 12" << endl
        << "Menu" << endl
        << "1) Task 1" << endl
        << "2) Task 2" << endl
        << "3) Task 3" << endl
        << "e) Exit" << endl;
}

void printPattern() {
    cout << R"(   _                   _
 _( )                 ( )_
(_, |      __ __      | ,_)
   \'\    /  ^  \    /'/
    '\'\,/\      \,/'/'
      '\| []   [] |/'
        (_  /^\  _)
          \  ~  /
          /HHHHH\
        /'/{^^^}\'\
    _,/'/'  ^^^  '\'\,_
   (_, |           | ,_)
     (_)           (_)
    )" << endl;
}

void zad1() {
    vector<int> vec;
    for (int i = 0; i < 10; i++) {
        int n = -100 + rand() % 200;
        vec.push_back(n);
    }

    //wyświetlenie wszystkich elementów w taki sposób aby każdy z elementów oddzielony był od siebie znakiem |
    cout << "vec: ";
    for (int i : vec)
        cout << i << " | ";
    cout << endl;

    //policzenie średniej arytmetycznej elementów w kontenerze
    int sum = 0;
    for (int i : vec)
        sum += i;
    double mean = (double)sum / vec.size();
    cout << "srednia: " << mean << endl;

    //policzenie ile elementów parzystych znajduje się w kontenerze
    int liczParzyste = count_if(vec.begin(), vec.end(), [](int x) { return (x % 2 == 0); });
    cout << "elementow parzystych w vec: " << liczParzyste << endl;

    //usunięcie elementów, które są ujemne
    vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return x < 0; }), vec.end());
    cout << "vec bez elementow ujemnych: ";
    for (int i : vec)
        cout << i << " ";
    cout << endl;

    //posortowanie elementów w kontenerze, tak aby najpierw znajdowały się elementy
    //parzyste a następnie nieparzyste
    stable_sort(vec.begin(), vec.end(), [](int x, int y) {
        return (x % 2 == 0 && y % 2 != 0)
        || (x % 2 == 0 && y % 2 == 0 && x < y)
        || (x % 2 != 0 && y % 2 != 0 && x < y);
        });
    cout << "posortowane elementy: ";
    for (int i : vec)
        cout << i << " ";
    cout << endl;

    //zmodyfikowanie wartości każdego elementu poprzez nadpisanie go liczbą przeciwną
    cout << "zmodyfikowane elementy: ";
    for (int& i : vec) {
        i = -i;
        cout << i << " ";
    }
    cout << endl;

    //policzenie ile elementów jest mniejszych niż otrzymany argument
    int argument = -43;
    int countSmaller = count_if(vec.begin(), vec.end(), [argument](int x) { return x < argument; });
    cout << "elementow mniejszych od " << argument << ": " << countSmaller << endl;
}

void zad2() {
    vector<Car> cars;

    cars.emplace_back("Toyota Camry", 2020, 2.5);
    cars.emplace_back("Honda Civic", 2019, 1.8);
    cars.emplace_back("Ford Mustang", 2018, 5.0);

    sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
        return a.getRok() < b.getRok();
        });

    cout << "Sortowanie rosnaco wzgledem roku produkcji:\n\n";
    int counter = 1;
    for (const auto& car : cars) {
        cout << counter << ": ";
        car.displayInfo();
        counter++;
    }

    sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
        return a.getPojemnosc() > b.getPojemnosc();
        });

    cout << "\nSortowanie malejaco wzgledem pojemnosci silnika:\n\n";
    counter = 1;
    for (const auto& car : cars) {
        cout << counter << ": ";
        car.displayInfo();
        counter++;
    }
}

tuple<size_t, double, string> statystyka(vector<string>& str) {
    size_t minLength = min_element(str.begin(), str.end(),
        [](const string& a1, const string& b1) {
            return a1.length() < b1.length(); })->length();

    double avrStringLength = static_cast<double>
        (accumulate(str.begin(), str.end(), 0,
            [](const size_t& sum, const string& a2) {
                return sum + a2.length(); })) / str.size();;

    string longestString = *max_element(str.begin(), str.end(),
        [](const string& a3, string& b3) {
            return a3.length() < b3.length(); });

    return make_tuple(minLength, avrStringLength, longestString);
}

void zad3() {
    vector<string> str = { "abc","dluginapis","nowak","test","lab12cpp" };
    cout << "vector string: ";
    for (string i : str)
        cout << i << " | ";
    cout << endl;
    int minLength;
    double avrStringLength;
    string longestString;

    tie(minLength, avrStringLength, longestString) = statystyka(str);
    cout << "Dlugosc najkrotszego napisu: " << minLength << endl
        << "Srednia dlugosc napisu: " << avrStringLength << endl
        << "Najdluzszy napis: " << longestString << endl;
}

int main()
{
    char variant;
    bool isTrue = true;
    while (isTrue) {
        print_menu();
        cin >> variant;
        switch (variant) {
        case '1':
            system("cls");
            zad1();
            system("pause");
            break;
        case '2':
            system("cls");
            zad2();
            system("pause");
            break;
        case '3':
            system("cls");
            zad3();
            system("pause");
            break;
        case 'e':
            system("cls");
            system("color 02");
            cout << "Have a nice day! Goodbye..." << endl;
            system("timeout /t 3 /nobreak");
            isTrue = false;
            break;
        default:
            system("cls");
            system("color 40");
            printPattern();
            cout << "\tIncorrect symbol!" << endl;
            system("timeout /t 3 /nobreak");
            break;
        }
    }
    return 0;
}

