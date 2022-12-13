#include <QCoreApplication>
#include <QtAlgorithms>
#include <QSet>
#include "stdc++.h"

using namespace std;

template <typename T>
void show(T& con) {
    for (typename T::iterator it = con.begin(); it != con.end(); it++)
        cout << *it << " ";
    cout << endl;
}

/*Napisz funkcję, która jako argument dostaje napis. Zadaniem funkcji jest sprawdzenie czy
napis jest pangramem. Pangram to napis, w którym występują wszystkie litery alfabetu
(wielkość liter nie ma znaczenia). W zadaniu bierzemy pod uwagę tylko alfabet łaciński.
Przykład pangramu to: The quick brown fox jumps over the lazy dog. W zadaniu należy
wykorzystać kontener QSet. W funkcji main należy przetestować stworzoną funkcję.
*/

void isPangram(QList<char> str, QList<char> test)
{
    QSet<char> unique;
    QSet<char> s(str.begin(), str.end());
    QSet<char> t(test.begin(), test.end());

    cout << "main string: ";
    show(s);
    cout << "test: ";
    show(t);
    cout << endl;

    set_difference(t.begin(), t.end(), s.begin(), s.end(), inserter(unique, unique.end()));

    if (unique.empty() == true)
        cout << "Napis jest pangramem" << endl;
    else{
        cout << "Unikatowy element: ";
        show(unique);
        cout << "Napis nie jest pangramem" << endl;
    }
}

int main()
{
    QList<char> str;
    QList<char> test;

    char arr[] = "the quick brown fox jumps over the lazy dog";
    cout << "Podany napis: " << arr;
    cout << endl << endl;

    int size = sizeof(arr) / sizeof(arr[0]);

    for (char l = 'a'; l <= 'z'; l++)
        test.push_front(l);

    for (int i = 0; i < size-1; i++){
        if (arr[i] != ' ')
            str.push_front(arr[i]);
    }

    isPangram(str, test);

    return 0;
}
