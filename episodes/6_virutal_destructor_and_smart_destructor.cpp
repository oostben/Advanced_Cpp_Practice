#include <iostream>
using namespace std;

//using virtual destructors on polymorphic base classes

class Shape {
    public:
        virtual ~Shape(){ cout << "Shape destroyed " << endl;}
};

class Square : public Shape {
    public:
        ~Square(){ cout << "Square destroyed " << endl;}
};


//Same thing as virtual destructors but using using smart pointers
class Polygon {
    public:
        ~Polygon(){ cout << "Polygon destroyed " << endl;}
};
class Triangle : public Polygon {
    public:
        ~Triangle(){ cout << "Triangle destroyed " << endl;}
};


//factory design pattern
class ShapeFactory {
    public:
        static Shape * createSquare() {
            return (new Square());
        }

        static shared_ptr<Polygon> createTriangle() {
            return shared_ptr<Polygon>(new Triangle());
        }
};

//all classes in STL have no virtual destructor, so be careful when inheriting from them 
//--> use shared ptrs for this

int main() {
    Shape * s1 = ShapeFactory::createSquare();
    delete s1;

    shared_ptr<Polygon> s2 = ShapeFactory::createTriangle();

}
