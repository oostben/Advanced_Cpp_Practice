#include <iostream>
#include "cat.h"
#include "dog.h"
#include "singleton.h"


using namespace std;

extern Dog d;
void Cat::meow() {cout << "Cat meow" << m_name << endl;}

Cat::Cat(string name):m_name(name) {
    cout << "Constructing cat " << m_name << endl; 
    Singleton::getDog()->bark();
}