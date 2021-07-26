#include <iostream>

using namespace std;

class Base{
    public:
        void f_public(){cout << "f_public is called." << endl;}
    protected:
        void f_protected(){cout << "f_public is called." << endl;}
    private:
        void f_pivate(){cout << "f_public is called." << endl;}
};

//none of the derived classes can access anything private in Base

class Derived_private : private Base {
    public:
        void f() {
            f_public(); //private now, cannot be inherited at all nor called from outside, nor inherited
            f_protected(); //private now, cannot be inherited at all nor called from outside, nor inherited
            f_pivate(); //private now, cannot be inherited at all nor called from outside, nor inherited
        }
};
//private inherits the public and private members of Base as private

class Derived_protected : protected Base{
    public:
        // using Base::f_public;
        void f() {
            f_public(); // ok inherits all public functions as protected however this is now a potected function so it will now be inherited as a protected
            //also it cannot be called from outside of this class now
            f_protected(); //ok inherits all protected functions as protected, but cannot be called from outside the class except for friends
            f_pivate(); //error doesn't inherit access to private members
        }
};
//potected inherits the public and protected members of Base as protected

class Derived_public : public Base{
    public:
        void f() {
            f_public(); // ok inherits all public functions
            f_protected(); //ok inherits all protected functions as protected, can't be called from outside of the class, except for friends
            f_pivate(); //error doesn't inherit access to private members
        }
};
//public inherits the public members of Base as public and the and protected members of Base as protected

//casting rules
//1)anyone can cast a Derived_public* to Base*. Derived_public is a special kind of Base
//2)Derived_private's members and friedns can cast Derived_private* to Base*
//3)Derived_protected's members, firends, and children can cast a Derived_potected* to B*

// only public inheritance can be considered an is-a relationship.

int main() {
    Derived_public d1();
    d1.f_public(); //ok inherits publics

    Derived_protected d2;
    d2.f_public(); // bad, protected derived class inherits public functions from base as protected

    Base * pBase = &d1; // ok anyone can cast a Derived_public* to Base*
    pBase = &d2; //error only potected derived classes self and children can cast Derived_protected* to Base*
    // ^^ could add using Base::f_public inside of public section of Derived_protected
    return 0;
}

//public inheritance: is-a relation eg: Derived_public is a kind of Base
//private inheritance: similar to a has-a relationship

class Ring {
    public:
        void twinkle() {...}
};

class Dog {
    Ring ring_;
    public:
        void twinkle(){
            ring_.twinkle(); //call forwarding, demonstrating a composition code structure
        }
};

//however this could also be done with private inheritance

class Dog_priv_example: private Ring {
    public:
    using Ring::twinkle;
};

//to bring a different objects into your own you have to either call forward or use private inheritance with declaration
//composition is prefered

//except if Ring has a virtual function that we would like to overide in Dog