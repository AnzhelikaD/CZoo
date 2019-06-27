#include <iostream>
#include <sstream>
#include "Animal.h"
#include "Zoo.h"
#include "ZooCreation.h"

int main() {
    Animal *lion1 = new Lion("Simba", 1);
    Animal *dog1 = new Dog("Balto", 5);

    Zoo zoo;

    zoo.addAnimal(lion1);
    zoo.addAnimal(dog1);
    zoo.addAnimal(new Snake("Nagini", 20));
    zoo.addAnimal(new Duck("Donald", 3));
    zoo.addAnimal(new Lion("Nala", 2));

    cout << *lion1 << endl;
    cout << *dog1 << endl;

    zoo.walk();

    SimpleAnimalCreator animalCreator;
    zoo.addAnimal(animalCreator.create("Duck", "Scrooge", 10));
    zoo.addAnimal(animalCreator.create("Dog", "Beethoven", 8));
    zoo.walk();

    istringstream iss("Dog Lady 1 Lion Scar 9 е");
    SimpleAnimalCreator sac;
    StreamZooCreator zc(iss, &sac);
    Zoo * z = zc.create();
    z->walk();
    delete z;
}