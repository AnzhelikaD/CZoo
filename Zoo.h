//
// Created by angelika on 27.06.19.
//

#ifndef UNTITLED1_ZOO_H
#define UNTITLED1_ZOO_H

#include <vector>
#include "Animal.h"

using namespace std;

class Zoo {
private:
    vector<Animal*> animals;

public:
    Zoo(){}

    ~Zoo() {
        for (Animal * animal : animals) {
            delete animal;
        }
    }

    Zoo(const Zoo &zoo) = delete;
    Zoo &operator=(const Zoo &zoo) = delete;

    void addAnimal(Animal * animal) {
        animals.push_back(animal->clone());
    }

    void walk() {
        for (Animal * animal : animals) {
            animal->say();
            animal->move();
        }
    }
};

#endif //UNTITLED1_ZOO_H
