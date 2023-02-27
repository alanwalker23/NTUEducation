#ifndef CHILDANIMAL_H
#define CHILDANIMAL_H

#include "Animal.h"
using namespace std;

class Cat: public Mammal{
    public :
        Cat();
        Cat(string n, COLOR c);
        ~Cat();
        void speak() const;
        void move();
    private :
        string _name;
        COLOR _color ;

};

class Lion: public Mammal{
    public :
        Lion();
        Lion(string n, COLOR c);
        ~Lion();
        void speak() const;
        void move() ;
    private :
        string _name;
        COLOR _color ;

};

class Dog: public Mammal{
    public :
        Dog();
        Dog(string n, COLOR c, string o);
        ~Dog();
        void speak() const;
        void move() ;
    private :
        string _owner;
        string _name;
        COLOR _color ;

};


#endif