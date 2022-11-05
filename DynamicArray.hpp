// DynamicArray.hpp
#pragma once

#include <string>
#include <sstream>

#include "Person.h"

using namespace std;

template<typename T>
class DynamicArray {
private:
	int size_now = 0;
	int size_max = 0;
	T* myArray = nullptr;

public:
	DynamicArray() {
		this->size_max = 1;
		this->size_now = 0;
		this->myArray = new T[this->size_max];
	}

	// A - dodanie nowego elementu na końcu tablicy
	void addData(const T& object) {
		if (this->size_now >= this->size_max) {
			this->expand();
		}
		this->myArray[this->size_now++] = object;
	}

	// B - zwrócenie danych i-tego elementu listy
	T getByIndex(int index) {
		return this->myArray[index];
	}

	// C - ustawienie (podmiana) danych i-tego elementu tablicy
	void changeDataAtIndex(int index, T& value) {
		this->myArray[index] = value;
	}
	
	// D  -  czyszczenie listy tj. usunięcie wszystkich elementów
	void clearList() {
		this->size_now = 0;
	}

	// D2  -  czyszczenie listy tj. usunięcie wszystkich elementów --- ptr
	void clearList(bool x) {
		int temp = this->size_now;
		for (int i = 0; i < temp; i++) {
			delete this->myArray[i];
			this->size_now--;
		}
	}

	// E - zwrócenie napisowej reprezentacji tablicy
	string list_to_string() {
		ostringstream lts;
		for (int i = 0; i < this->size_now; i++) {
			lts << this->myArray[i] << endl;
		}
		return lts.str();
	}

	// F - sortowanie tablicy
	void bubbleSort() {
		for (int i = 0; i < this->size_now; i++) {
			for (int j = 0; j < this->size_now - 1; j++) {
				if (this->myArray[j] > this->myArray[j + 1]) {
					T temp = this->myArray[j];
					this->myArray[j] = this->myArray[j + 1];
					this->myArray[j + 1] = temp;
				}
			}
		}
	}
	
	// F2 - sortowanie tablicy --- ptr
	void bubbleSort(bool x) {
		for (int i = 0; i < this->size_now; i++) {
			for (int j = 0; j < this->size_now - 1; j++) {
				if (*(this->myArray[j]) > *(this->myArray[j + 1])) {
					T temp = this->myArray[j];
					this->myArray[j] = this->myArray[j + 1];
					this->myArray[j + 1] = temp;
				}
			}
		}
	}

	void expand() {
		this->size_max = this->size_max * 2;

		T* tempArray = new T[this->size_max];

		for (int i = 0; i < this->size_now; i++) {
			tempArray[i] = this->myArray[i];
		}

		delete[] this->myArray;
		this->myArray = tempArray;
	}

	int size() {
		return this->size_now;
	}

	int cap() {
		return this->size_max;
	}
	
};
