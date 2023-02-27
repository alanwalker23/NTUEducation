#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
using namespace std;

enum COLOR { Green, Blue, White, Black, Brown } ;

class Animal {
    public :
        Animal();
        Animal(string n, COLOR c);
        virtual ~Animal();
        virtual void speak() const;
        virtual void move() = 0;
    private :
        string _name;
        COLOR _color ;
};


class Mammal: public Animal{
    public :
        Mammal();
        Mammal(string n, COLOR c);
        ~Mammal();
        virtual void eat() const;
        virtual void move() ;
    private :
        string _name;
        COLOR _color ;
};


#endif