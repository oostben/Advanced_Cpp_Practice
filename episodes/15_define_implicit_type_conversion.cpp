#include <iostream>

using namespace std;

void foo(int i) {
    cout << i << endl;
}

class Base{};
class Derived1: public Base{};
class Derived2: protected Base{};

//Implicit user defined type conversion
// Defined inside class (user defined)
// There are 2 methods to define implocot user defined type conversion
// Method 1: Use constructor that can accept a single parameter.
//     -convert other types of object in you class 
// Method 2:Use the type conversion fucntion 
//     -Convert an object of your class sinto other types

class Dog {
    public:
        // Dog(string name):name_(name){} // Implicit NOT explicit
        //if you want to only define a constructor and no implicit type convversion,
        // always put "explicit" befire the constructor to avoid inadvertent type conversion.
        //also be careful with default arugments, if you have all default arguments except one it will still convert

        explicit Dog(string name):name_(name){} // explicit must be called with ()

        //define type conversion function for string
        operator string() const {return name_;} // implicit conversoin defined for string
        
        //overload the <<
        friend std::ostream& operator<< (std::ostream& stream, const Dog& d){
            stream <<  d.getName() << endl; return stream;
        }

        string getName() const {return name_;}

    private:
        string name_;
};

//avoid defining two-way implicit type conversion

int main() {
    //Catagory A: Implicit Standard Type conversion
    char c = 'A';
    int i = c; // intergral promotion
    cout << i << endl;
    int j = 'z' - 'a';
    cout << j << endl;
    
    char * ch = 0; //int -> NULL
    // cout << *ch;

    foo(c);

    Base * p1 = new Derived1();
    // Base * p2 = new Derived2(); //fails Base is protected in Derived2

    string tempName = "Flip";
    // Dog flip = tempName; //implict type conversion
    Dog flip = Dog(tempName); //explicit type conversion

    cout << flip << endl;
    string flipsName = flip;
    cout << flipsName << endl;
    return 0;
}

// class Base { };

// class Derived1 : public Base { };
// class Derived2 : public Base { };

// class MostDerived : public Derived1, Derived2 { };

// int main()
// {
//    Base* b = new MostDerived(); // won't work (but you could hint compiler
//                                 // which path to use for finding Base
// }
