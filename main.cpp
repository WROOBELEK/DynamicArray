// main.cpp
#include <iostream>
#include <iomanip>
#include <ctime>

#include "DynamicArray.hpp"

using namespace std;

void test_1() {
    // TEST Lista 1
    DynamicArray<Person>* da1 = new DynamicArray<Person>();
	
    const size_t n = 10000;

    Person test1[n];

    clock_t time1 = clock();
	
    double max_time_per_element = 0.0;
	
    for (size_t i = 0; i < n; i++) {
        clock_t time1_el = clock();
        da1->addData(test1[i]);
        clock_t time2_el = clock();
		double time_per_element = (double)(time2_el - time1_el) / CLOCKS_PER_SEC;
        if (time_per_element > max_time_per_element) {
            max_time_per_element = time_per_element;
            cout << "Odnotowano nowy najgorszy czas dodania pojedynczego elementu na indeksie " << i << ". Czas: " << max_time_per_element << " s" << endl;
        }
    }
	
    clock_t time2 = clock();

    double time = (double)(time2 - time1) / CLOCKS_PER_SEC;

    cout << fixed;
    cout << setprecision(5);
    cout << "Czas dodawania " << n << " elementow: " << time << "s" << endl;
    cout << "Czas dodawania jednego elementu: " << (time / n)*1000 << " ms" << endl;
	
    da1->clearList();
	delete da1;
}

void test_2() {
    // TEST Lista 2
    DynamicArray<Person*>* da2 = new DynamicArray<Person*>();

    const size_t n = 1000000;

    clock_t time1 = clock();

    double max_time_per_element = 0.0;

    for (size_t i = 0; i < n; i++) {
        clock_t time1_el = clock();
        da2->addData(new Person());
        clock_t time2_el = clock();
        double time_per_element = (double)(time2_el - time1_el) / CLOCKS_PER_SEC;
        if (time_per_element > max_time_per_element) {
            max_time_per_element = time_per_element;
            cout << "Odnotowano nowy najgorszy czas dodania pojedynczego elementu na indeksie " << i << ". Czas: " << max_time_per_element << " s" << endl;
        }
    }

    clock_t time2 = clock();

    double time = (double)(time2 - time1) / CLOCKS_PER_SEC;

    cout << fixed;
    cout << setprecision(5);
    cout << "Czas dodawania " << n << " elementow: " << time << " s" << endl;
    cout << "Czas dodawania jednego elementu: " << (time / n)*1000 << " ms" << endl;

    da2->clearList(true);
    delete da2;
}



void main_test() {
    DynamicArray<Person>* da1 = new DynamicArray<Person>();
    DynamicArray<Person*>* da2 = new DynamicArray<Person*>();
	
    char option;
    bool quit = false;

    do {
        cout << "==============================" << endl;
        cout << "1: Dodaj od konca" << endl; // A
        cout << "2: Wyswietl dane i-tego elementu" << endl; // B
        cout << "3: Zmien dane i-tego elementu" << endl; // C
        cout << "4: Sortuj liste" << endl; // F
        cout << "0: Wyczysc liste" << endl; // D
        cout << "P: Wyswietl liste" << endl; // E
        cout << "X: Wyjdz" << endl;
        cout << "==============================" << endl;
        cout << ">> ";
        cin >> option;
        //
        switch (option) {
        case '1':
        {
            Person temp1[10];
            for (int i = 0; i < 5; i++) {
                da1->addData(temp1[i]);
            }

            for (int i = 0; i < 5; i++) {
                da2->addData(new Person());
            }
            break;
        }

        case '2': 
        {
            cout << da1->getByIndex(0);
            cout << da2->getByIndex(0);
            break;
        }

        case '3':
        {
            Person temp1;
            temp1.name = "TestName_1";
            temp1.age = 51;
			
            Person* temp2 = new Person();
            temp2->name = "TestName_2";
            temp2->age = 52;

			da1->changeDataAtIndex(2, temp1);
            da2->changeDataAtIndex(2, temp2);
            break;
        }

        case '4':
        {
            da1->bubbleSort();
            da2->bubbleSort(true);
            break;
        }

        case '0':
        {
			da1->clearList();
            da2->clearList(true);
            break;
        }

        case 'p': case 'P':
        {
            colors('r'); cout << da1->list_to_string(); colors('x'); cout << "#####" << endl; 
            colors('b'); cout << da2->list_to_string(); colors('x'); cout << endl;
            break;
        }

        case 'x': case 'X':
        {
            quit = true;
            break;
        }

        default:
            cout << "Zla opcja" << endl;
            break;
        }

    } while (!quit);

    cout << "Zakonczono program. Zamykanie.";
}

int main() {
    
    colors('m');
    test_1();
    cout << endl;
    cout << setprecision(3);
    colors('c');
    test_2();
    colors('x');
    
    //main_test();
    return 0;
}
