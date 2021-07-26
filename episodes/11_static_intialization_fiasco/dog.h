#include <iostream>
// #include "dog.cpp"

using namespace std;

class Dog {
    public:
        void bark();
        Dog(string name);
    private:
        string m_name;
};
