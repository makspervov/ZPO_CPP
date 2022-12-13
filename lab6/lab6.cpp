#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <boost/bind.hpp>

using namespace std;

/*Napisz funkcję szablonową o parametrze T, która jako argument będzie zawierać kontener
vector typu T. Zadaniem funkcji jest wyświetlenie:
• elementów mniejszych niż średnia arytmetyczna wszystkich elementów;
• elementów znajdujących się między średnią arytmetyczna a medianą wszystkich
elementów;
• elementów dodatnich.
Można skorzystać z elementów biblioteki functional. W celu przekazania argumentów do
funkcji należy użyć funkcji bind.*/

template <typename T>
void statistics(vector<T> vec) {
	double median = 0;
	double sum = accumulate(vec.begin(), vec.end(), 0.0);
	double average = sum / vec.size();

	//liczby mniejsze średniej
	cout << endl;
	cout << "Srednia: " << average << endl;
	cout << "Liczby mniejsze od tej sredniej: " << endl;
	for (auto i : vec) {
		if (i < average) {
			cout << i << " ";
		}
	}

	cout << endl << endl;

	// liczby pomiędzy średnią a medianą
	sort(vec.begin(), vec.end());
	if (vec.size() % 2 != 0) {
		median = vec[vec.size() / 2];
	}
	else {
		median = ((vec[(vec.size() / 2) - 1] + vec[vec.size() / 2]) / 2);
	}
	cout << "Srednia: " << average << " , " << "Mediana: " << median << endl;
	cout << "Liczby pomiedzy srednia, a mediana: " << endl;
	if (average > median) {
		swap(average, median);
	}
	for (auto i : vec) {
		if (i > average && i < median) {
			cout << i << " ";
		}
	}
	cout << endl << endl;

	//liczby dodatnie
	cout << "Liczby dodatnie: " << endl;
	for (auto i : vec) {
		if (i > 0) {
			cout << i << " " << endl;
		}
	}

}

void zad3()
{
	srand(unsigned(time(nullptr)));
	vector<int> vec;

	for (int i = 0; i < 10; i++) {
		int k = -100 + rand() % 200;
		vec.push_back(k);
	}

	cout << "vec: ";
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;

	auto stat = boost::bind(&statistics<int>, _1);
	stat(vec);
}

int main()
{
	zad3();

	system("pause");
	return 0;
}