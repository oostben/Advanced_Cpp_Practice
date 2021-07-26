#include <iostream>
#include "cat.h"
#include "dog.h"
#include "singleton.h"

using namespace std;

void Dog::bark() {cout << "Dog bark" << m_name << endl;}

Dog::Dog(string name):m_name(name) {
    cout << "Constructing dog " << m_name << endl;
    // Singleton::getCat()->meow();

}