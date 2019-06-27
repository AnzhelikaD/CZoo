//
// Created by angelika on 27.06.19.
//

#ifndef UNTITLED1_ZOOCREATION_H
#define UNTITLED1_ZOOCREATION_H

#include "Zoo.h"

class ZooCreator {
public:
    virtual ~ZooCreator(){}

    virtual Zoo* create() = 0;
};

class AnimalCreator {
public:
    virtual ~AnimalCreator(){}

    virtual Animal* create(string const & spec, string const & name, int age) = 0;
};

class SimpleAnimalCreator: public AnimalCreator {
public:
    Animal* create(string const & spec, string const & name, int age) override {
        if (spec == "Lion") {
            return new Lion(name, age);
        } else if (spec == "Dog") {
            return new Dog(name, age);
        } else if (spec == "Duck") {
            return new Duck(name, age);
        } else if (spec == "Snake") {
            return new Snake(name, age);
        }
    }
};

class StreamZooCreator : public ZooCreator {
    istream & in;
    AnimalCreator * animalCreator;
public:
    StreamZooCreator(istream & _in, AnimalCreator * _animalCreator) : in(_in), animalCreator(_animalCreator) {}

    Zoo* create() override {
        string type, name;
        int age;
        auto * zoo = new Zoo();
        while (in >> type >> name >> age) {
            auto animal = animalCreator->create(type, name, age);
            zoo->addAnimal(animal);
            delete animal;
        }
        return zoo;
    }
};

#endif //UNTITLED1_ZOOCREATION_H
