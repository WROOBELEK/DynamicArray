// Person.h
#pragma once

#include <string>

#include "Misc.h"

using namespace std;

string namesArr[] = { "Adam", "Piotr", "Jakub", "Stefan", "Kacper", "Julian", "Jan", "Sebastian", "Janusz", "Maciej", "Marek" };

class Person {
public:
	string name;
	short int age;

    Person() {
        name = namesArr[randomNumber(0, 10)];
        age = randomNumber(1, 99);
    }

    friend ostream& operator << (ostream& os, const Person* prs) {
        os << prs->name << " " << prs->age << "\n";
        return os;
    }

    friend ostream& operator << (ostream& os, const Person& prs) {
        os << prs.name << " " << prs.age << "\n";
        return os;
    }
	
	bool operator > (const Person& prs) {
		return this->age > prs.age;
	}

    bool operator > (const Person* prs) {
        return this->age > prs->age;
    }

	bool operator < (const Person& prs) {
		return this->age < prs.age;
	}

    bool operator < (const Person* prs) {
        return this->age < prs->age;
    }
};
