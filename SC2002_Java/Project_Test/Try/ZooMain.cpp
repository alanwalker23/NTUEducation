#include <iostream>
#include <string>

#include "Animal.h"
#include "ChildAnimal.h"
using namespace std;

int main()
{
    Mammal **zoo = new Mammal *[3];
    zoo[0] = new Dog("dog", White, "Bob");
    zoo[1] = new Cat("cat", Blue);
    zoo[2] = new Lion("lion", Brown);

    int choice = 0;
    do
    {
        cout << "Select the animal to send to Zoo : " << endl;
        cout << "(1) Dog (2) Cat (3) Lion (4) Move all animals (5) Quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            zoo[0]->move();
            zoo[0]->speak();
            zoo[0]->eat();
            break;

        case 2:
            zoo[1]->move();
            zoo[1]->speak();
            zoo[1]->eat();
            break;

        case 3:
            zoo[2]->move();
            zoo[2]->speak();
            zoo[2]->eat();
            break;

        case 4:
            for (int i = 0; i < 3; i++)
            {
                zoo[i]->move();
                zoo[i]->speak();
                zoo[i]->eat();
            }
            break;

        default:
            break;
        }
    } while (choice < 5);

    for (int i = 0; i < 3; i++)
    {
        delete zoo[i];
    };

    delete[] zoo;

    cout << "Program exiting …. " << endl;

    return 0;
}