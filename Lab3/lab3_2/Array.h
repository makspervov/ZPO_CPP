#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>

template <typename T>
class Array {
private:
	T* arr;
	int maxSize;
	int firstIndex;
public:
	Array(T value)
	{
		//
	};
	Array(): max, index{

	}
	~Array() {
		cout << "Array class destructor";
	};
	void add(T value);
	void show();
};

template <typename T>
Array<T>::Array(T value) {
	size = value;
}

template <typename T>
Array<T>::Array() {
	max = i;
}

template<typename T>
void Array<T>::show() {
	cout << "Tablica: " << pole[] << endl;
}

template <typename T>
void Array<T>::add(T value) {

}



#endif //ARRAY_H