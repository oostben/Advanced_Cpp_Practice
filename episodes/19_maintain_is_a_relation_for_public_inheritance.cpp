#include <iostream>

using namespace std;

//Summary:
    // problem here: same object react differently with same api
    // lesson never overide nonvirtual function

    // default arguments bound at runtime, be careful when using default argument with virtual functions

    //virtual class wont search base class for a function if theres alread a virtual on in it even if it has different arguments (see bark)
    //force inheritance of shadowed funtions (same function name different arguments)



//Public inheritance => "is-a relation"
//a derived class should be able to do everything thatthe base class can do

class Bird {};


class FlyableBird: public Bird {
    public:
        void fly() {
            cout << "flying\n" << endl;
        }
};

class Penguin: public FlyableBird {};

// //example 2 -----------------------------------------------------------------
// //polymorphism: different classes with the same interface will act differently

// class Dog {
//     public:
//         void bark(){
//             cout << "dog bark" << endl;
//         }
// };

// class Lab: public Dog{
//     public:
//         void bark(){
//             cout << "lab bark" << endl;
//         } 
// };

// int main() {
//     //problem here: same object react differently with same api
//     //lesson never overide nonvirtual function
//     Lab* lab1p = new Lab();
//     lab1p->bark();
//     Dog* dog1p = lab1p;
//     dog1p->bark();


//     return 0;
// }

//example 3 -----------------------------------------------------------------
// default arguments bound at runtime, be careful when using default argument with virtual functions

// class Shape {
//     public:
//         virtual void printNumSides(int numSides = -1) {
//             cout << "NumSides = " << numSides<< endl;
//         }
// };

// class Square :public Shape {
//     public:
//         virtual void printNumSides(int numSides = 4) {
//             cout << "NumSides = " << numSides<< endl;
//         }
// };

// int main() {
//     //problem here: default arguments bound at runtime, avoid using them with virtual functions
//     Square* ptrSquare = new Square();
//     ptrSquare->printNumSides();
//     Shape * ptrShape = ptrSquare;
//     ptrShape->printNumSides();

//     //output:
//     // NumSides = 4
//     // NumSides = -1

//     return 0;
// }


//example 4 -----------------------------------------------------------------
//virtual class wont search base class for a function if theres alread a virtual on in it even if it has different arguments (see bark)

class Shape {
    public:
        void printNumSides(string numSides) {
            cout << "NumSides = " << numSides<< endl;
        }
        virtual void printNumSides(int numSides = -1) {
            cout << "NumSides = " << numSides<< endl;
        }
};

class Square :public Shape {
    public:
        using Shape::printNumSides;
        virtual void printNumSides(int numSides = 4) {
            cout << "NumSides = " << numSides<< endl;
        }
};

int main() {
    Square* ptrSquare = new Square();
    ptrSquare->printNumSides("-2"); // wont work, sees the virtual printNumSides in Square, doesn't keep searching
    //must add using Shape::printNumSides; to Shape class to get it to find that function
    return 0;
}