#include "ChildAnimal.h"

Cat::Cat() : _name("unknown") {
    cout << "constructing Cat object "<< _name << endl ; 
}

Cat::Cat(string n, COLOR c) : _name(n), _color(c) {
    cout << "constructing Cat object "<< _name << " Color " << _color << endl ; 
}

Cat::~Cat() {
    cout << "destructing Cat object "<< _name << endl ; 
}

void Cat::speak() const {
    cout << "Meow"<< endl ;
}
        
void Cat::move() {
    cout << "Cat moves" << endl;
}

Lion::Lion() : _name("unknown") {
    cout << "constructing Lion object "<< _name << endl ; 
}

Lion::Lion(string n, COLOR c) : _name(n), _color(c) {
    cout << "constructing Lion object "<< _name << " Color " << _color << endl ; 
}

Lion::~Lion() {
    cout << "destructing Lion object "<< _name << endl ; 
}
        
void Lion::speak() const {
    cout << "Roar"<< endl ;
}

void Lion::move() {
    cout << "Lion moves" << endl;
}


Dog::Dog() : _name("unknown") {
    cout << "constructing Dog object "<< _name << endl ; 
}
        
Dog::Dog(string n, COLOR c, string o) : _name(n), _color(c), _owner(o) {
    cout << "constructing Dog object "<< _name << " Color " << _color << " Owner " << o << endl ; 
}
        
Dog::~Dog() {
    cout << "destructing Dog object "<< _name << endl ; 
}

void Dog::speak() const {
    cout << "Woof"<< endl ;
}

void Dog::move() {
    cout << "Dog moves" << endl;
}

int main(){return 0;}

// int main() {
//         //Animal a("animal", Brown);
//         //a.speak();

//         //Mammal m("mammal", Black);
//         //m.speak();

//         Dog d("dog", White, "Bob");
//         d.speak();
//         d.move();

//         cout << "Program exiting …. "<< endl ;


//     return 0;
// }