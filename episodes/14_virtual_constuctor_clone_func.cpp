#include <iostream>
#include <vector>

using namespace std;

// using a clone function to replace copy constructor and assignment operator


//able to overide clone in base class even with a different return type (covariant return type), 
//allows an overidden virtual function to have a different return type as long as it's derived 
//from the base classes return type

class Shape{
    public:
    virtual Shape * clone() {
        return (new Shape(*this));
    }
    int shape_;
};

class Square: public Shape {
    virtual Square * clone() { 
        return (new Square(*this));
    }
    int square;

};

void foo(Shape* s) { //s is a square
    // Shape * s1 = new Shape(*s); //s1 is a shape, its not an identical to s, becuase we call the Shapes copy constructor
    Shape * s1 = s->clone();
}

int main() {
    Square sq;
    foo(&sq);
    return 0;
}
