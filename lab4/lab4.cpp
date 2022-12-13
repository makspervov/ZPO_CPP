#include <iostream>
#include "stdc++.h"

using namespace std;

template <typename T> void show(T &con) {
	for (typename T::iterator it = con.begin(); it != con.end(); it++)
		cout << *it << " ";
	cout << endl;
}

void print(int& el) {
	cout << el << " ";
}

void zad2() {
	cout << "Zadanie 2" << endl << endl;
	list<int> list;
	int i;
	int n = rand();

	for (i = 0; i < n; i++) {
		int j = -100 + rand() % 201;
		if (j >= 0)
			list.push_front(j);
		else
			list.push_back(j);
	}

	cout << "Lista dynamiczna list o wylosowanym rozmiarze " << n << ": " << endl;
	show(list);
	cout << endl;

	cout << "Koniec wykonania progamu" << endl;
}

void zad3() {
	cout << "W realizacji..." << endl;
}

bool sumaCyfr(int x, int y) {
	int tempx = x, tempy = y;
	int sumx = 0, sumy = 0;

	while (tempx)
	{
		sumx += tempx % 10;
		tempx /= 10;
	}

	while (tempy)
	{
		sumy += tempy % 10;
		tempy /= 10;
	}

	return sumx < sumy;
}

bool rozmiarLiczby(int x, int y) {
	int tempx = x, tempy = y;

	if (tempx == 0)
		return 1;
	int countx = 0;
	while (tempx != 0) {
		tempx /= 10;
		++countx;
	}

	if (tempy == 0)
		return 1;
	int county = 0;
	while (tempy != 0) {
		tempy /= 10;
		++county;
	}

	return county < countx;
}

void zad4() {
	vector<int> num;
	int n = rand();
	int i;

	cout << "Zadnie 4\nGenerowanie liczb za pomoca komendy rand()" << endl;

	for (i = 0; i < n; i++) {
		int j = -300 + rand() % 600;
		num.push_back(j);
	}

	cout << endl << "Liczby do sortowania" << endl;
	for_each(num.begin(), num.end(), print);
	cout << endl << endl;

	cout << "Liczby posortowano rosnaco wedlug sumy cyfr w liczbie" << endl;
	sort(num.begin(), num.end(), sumaCyfr);
	for_each(num.begin(), num.end(), print);
	cout << endl << endl;

	cout << "Liczby posortowano malejaco wedlug liczby cyfr" << endl;
	sort(num.begin(), num.end(), rozmiarLiczby);
	for_each(num.begin(), num.end(), print);
	cout << endl << endl;

	cout << "Koniec wykonania progamu" << endl;
}

int main() {
	int menu;
	cout << "Laboratorium 4" << endl << "Menu" << endl << "2) Zadanie 2" << endl << "3) Zadanie 3"
		<< endl << "4) Zadanie 4" << endl << "0) Wyjscie" << endl;
	cout << "Wybierz zadanie: ";
	cin >> menu;
	if (menu > 1 && menu < 5 || menu == 0) {
		switch (menu)
		{
		case 2:
			zad2();
			system("pause");
			return 0;
		case 3:
			zad3();
			system("pause");
			return 0;
		case 4: 
			zad4();
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