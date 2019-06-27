//
// Created by angelika on 26.06.19.
//

#ifndef UNTITLED1_ANIMAL_H
#define UNTITLED1_ANIMAL_H

#include <iostream>
#include <utility>

using namespace std;

class Animal {
protected:
    virtual void print(ostream &os) const {};
public:
    virtual void say() const = 0;
    virtual void move() = 0;
    virtual Animal * clone() const = 0;

    virtual ~Animal() {
        cout << " - the animal died" << endl;
    }

    friend std::ostream& operator<< (std::ostream &out, const Animal &animal) {
       animal.print(out);
        return out;
    }
};

class Mammal : public Animal {

};

class Bird : public Animal {

};

class Reptile : public Animal {

};

template <typename T>
class Creature: public T {
private:
    string name;
    int age;
public:
    Creature(string _name, int _age) : name(std::move(_name)), age(_age) {}

    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
};

class Lion : public Creature<Mammal> {
protected:
    void print(ostream &os) const override {
        os << this->getName() << " " << this->getAge();
    }
public:
    Lion(const string &name, int age) : Creature(name, age) {
        cout << "Lion " << name << " born" << endl;
    }

    ~Lion() override {
        cout << "there is no more Lion " << getName();
    }

    void say() const override {
        cout << getName() << " Meow" << endl;
    }

    void move() override {
        cout << getName() << " Run" << endl;
    }

    Lion * clone() const override {
        return new Lion(*this);
    }
};

class Dog : public Creature<Mammal> {
protected:
    void print(ostream &os) const override {
        os << this->getName() << " " << this->getAge();
    }
public:
    Dog(const string &name, int age) : Creature(name, age) {
        cout << "Dog " << name << " born" << endl;
    }

    ~Dog() override {
        cout << "there is no more Dog " << getName();
    }

    void say() const override {
        cout << getName() << " Woof" << endl;
    }

    void move() override {
        cout << getName() << " Walk" << endl;
    }

    Dog * clone() const override {
        return new Dog(*this);
    }
};

class Duck : public Creature<Bird> {
protected:
    void print(ostream &os) const override {
        os << this->getName() << " " << this->getAge();
    }
public:
    Duck(const string &name, int age) : Creature(name, age) {
        cout << "Duck " << name << " born" << endl;;
    }

    ~Duck() override {
        cout << "there is no more Duck " << getName();
    }

    void say() const override {
        cout << getName() << " Quack" << endl;
    }

    void move() override {
        cout << getName() << " Swim" << endl;
    }

    Duck * clone() const override {
        return new Duck(*this);
    }
};

class Snake : public Creature<Reptile> {
protected:
    void print(ostream &os) const override {
        os << this->getName() << " " << this->getAge();
    }
public:
    Snake(const string &name, int age) : Creature(name, age) {
        cout << "Snake " << name << " born" << endl;
    }

    ~Snake() override {
        cout << "there is no more Snake " << getName();
    }

    void say() const override {
        cout << getName() << " Shshh" << endl;
    }

    void move() override {
        cout << getName() << " Craw" << endl;
    }

    Snake * clone() const override {
        return new Snake(*this);
    }
};


#endif //UNTITLED1_ANIMAL_H
