// lab 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdc++.h"

using namespace std;

template <typename T>
void show(T& con) {
	for (typename T::iterator it = con.begin(); it != con.end(); it++)
		cout << *it << " ";
	cout << endl;
}

/*Napisz funkcję, która jako argument przyjmuje kontener vector przechowujący liczby
całkowite. Zakładamy, że vector przechowuje unikatowe wartości oprócz jednej, która została
zduplikowana. Zadaniem funkcji jest znalezienie wartości, która została zduplikowana oraz
policzenie sumy unikatowych elementów. Funkcja powinna zwrócić obiekt klasy pair.
W zadaniu należy wykorzystać kontener set. W funkcji main należy przetestować funkcję.*/

set<int> foo(vector<int> vec) {
	set<int> duplicates;
	int sum{ 0 };
	sort(vec.begin(), vec.end());
	set<int> distinct(vec.begin(), vec.end());
	set <int> ::iterator it = distinct.begin();
	for (int i = 0; i < distinct.size(); ++i) {
		sum = sum + *it;
		it++;
	}
	cout << "Suma unikalnych elementow " << sum << endl;
	set_difference(vec.begin(), vec.end(), distinct.begin(),
		distinct.end(), inserter(duplicates, duplicates.end()));
	return duplicates;
}

/*pair<int, int> zduplikowana(vector<int>& v) {
	int suma = 0;
	pair <int, int> result;
	set<int> s;
	for (auto &i : v) {
		auto result = s.insert(i);
		if (!s.first())
			s.first = i;
		else
			suma = suma + s(i);
	}
	s.second = suma;
	return result;
}*/

void zad1()
{
	cout << "Zadanie 1" << endl << endl;
	vector<int> vec;
	for (int i = -2; i < 10; ++i) {
		vec.push_back(i);
	}
	vec.push_back(4);
	cout << "vec: ";
	show(vec);
	cout << endl;

	set<int> duplicates = foo(vec);
	cout << "Wartosc zduplikowana: ";
	for (auto& i : duplicates) {
		cout << i << ' ';
	}
	cout << endl;
}

/*Napisz funkcję szablonową, która jako argument przyjmuje dwa zbiory. Funkcja powinna
wyświetlić elementy, które znajdują się tylko w pierwszym lub tylko w drugim zbiorze.
Podpowiedź: Należy zwrócić uwagę z jakim typem wywoływane są algorytmy i iteratory.*/

template<typename T>
set<T> findUnique(vector<T> vec_1, vector<T> vec_2)
{
	set<T> unique;
	set<T> v1(vec_1.begin(), vec_1.end());
	set<T> v2(vec_2.begin(), vec_2.end());
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(unique, unique.end()));
	set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), inserter(unique, unique.end()));
	return unique;
}

void zad2()
{
	cout << "Zadanie 2" << endl << endl;
	//przypisujemy do wektorów liczby
    //vector<int> vec_1 = {};
    //vector<int> vec_2 = {};

	//liczby i rozmiar wektorów są losowane

	vector<int> vec_1;
	vector<int> vec_2;
	int i;
	int n = rand();

	for (i = 0; i < n; i++) {
		int j = rand() % 100;
		vec_1.push_back(j);
	}
	for (i = 0; i < n; i++) {
		int k = rand() % 100;
		vec_2.push_back(k);
    }

	cout << "vec_1: ";
	show(vec_1);
	cout << "vec_2: ";
	show(vec_2);
	cout << endl;

	cout << "Elementy, ktore znajduja sie tylko w pierwszym lub tylko w drugim zbiorze: ";
	set<int> unique = findUnique(vec_1, vec_2);
	cout << "";
	for (auto& i : unique) {
		cout << i << ' ';
	}
	cout << endl;
}

/*Napisz funkcję, która dostaje jako argumenty dwa napisy typu string. Drugi napis jest o jest
o jeden znak dłuższy od pierwszego. Drugi napis zawiera te same znaki co pierwszy napis tylko
w różnej kolejności i dodatkowo jeszcze jeden znak. Zadaniem funkcji jest znalezienie znaku,
który został dodany do drugiego napisu i zwrócenie go. W zadaniu należy wykorzystać
kontener map. W main należy przetestować funkcję*/

void two_strings(string str1, string str2) {
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	map<int, char> item_1;
	map<int, char> item_2;
	for (int i = 0; i < str1.size(); ++i) {
		item_1[i] = str1[i];
	}
	for (int i = 0; i < str2.size(); ++i) {
		item_2[i] = str2[i];
		if (item_1[i] != item_2[i]) {
			cout << item_2[i];
			break;
		}
	}
	/*for (int i = 0; i < str2.size(); ++i) {
		if (item_1[i] != item_2[i]) {
			cout << item_2[i];
			break;
		}
	}*/
}

void zad3()
{
	cout << "Zadanie 3" << endl << endl;
	string text_1{ "A Song of Ice and Fire" };
	string text_2{ "A SognS fo Ice dan Frei" };
	cout << "text_1: " << text_1 << endl;
	cout << "text_2: " << text_2 << endl;
	sort(text_1.begin(), text_1.end());
	sort(text_2.begin(), text_2.end());
	cout << "Dodany znak: ";
	two_strings(text_1, text_2);
	cout << endl;
}

int main()
{
	int menu;
	cout << "Laboratorium 5" << endl << "Menu" << endl << "1) Zadanie 1" << endl << "2) Zadanie 2"
		<< endl << "3) Zadanie 3" << endl << "0) Wyjscie" << endl;
	cout << "Wybierz zadanie: ";
	cin >> menu;
	if (menu >= 0 && menu < 4) {
		switch (menu)
		{
		case 1:
			zad1();
			system("pause");
			return 0;
		case 2:
			zad2();
			system("pause");
			return 0;
		case 3:
			zad3();
			system("pause");
			return 0;
		case 0:
			cout << "Wyjscie z programu..." << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
