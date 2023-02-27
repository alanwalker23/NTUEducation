#include <iostream>
#include <string>
#include "Animal.h"
using namespace std;

Animal::Animal() : _name("unknown") {
    cout << "constructing Animal object "<< _name << endl ;
}
        
Animal::Animal(string n, COLOR c) : _name(n), _color(c) {
    cout << "constructing Animal object "<< _name << " Color " << _color << endl ; 
}

Animal::~Animal() {
    cout << "destructing Animal object "<< _name << endl ; 
}
        
void Animal::speak() const {
    cout << "Animal speaks "<< endl ; 
}


Mammal::Mammal() : _name("unknown") {
    cout << "constructing Mammal object "<< _name << endl ; 
}

Mammal::Mammal(string n, COLOR c) : _name(n), _color(c) {
    cout << "constructing Mammal object "<< _name << " Color " << _color << endl ; 
}
        
Mammal::~Mammal() {
    cout << "destructing Mammal object "<< _name << endl ; 
}
        
void Mammal::eat() const {
    cout << "Mammal eats" << endl;
}

void Mammal::move() {
    cout << "Mammal moves" << endl;
}

int main(){return 0;}




//cd C:\Users\mavis\OneDrive\Desktop\ntu\Year 2 Sem 1\SC2002\SC2002 Labs\Lab 5
