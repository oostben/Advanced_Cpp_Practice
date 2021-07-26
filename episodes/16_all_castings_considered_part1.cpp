#include <iostream>

using namespace std;

class Shape {
    public:
        Shape() = default;
        Shape(string name ) {
            name_ = name;
        }
        string name_;
        virtual string getName() const{return ("shape " + name_);}
};


class Square: public Shape{
    public:
        Square(string name){
            name_ = name;
        }
        virtual string getName() const{return ("square " + name_);}

};

int main() {
    //static cast
    int i = 9;
    float f = static_cast<float>(i);
    Shape s1 = static_cast<Shape>("Flip"); // type conversion needs to be defined
    Shape * s2 =static_cast<Shape*>(new Square("s2"));


    //dynamic cast
    Shape* square = new Square("square3");
    Square* temp = dynamic_cast<Square*>(square);

    Shape* shape = new Shape("square3");
    Square* temp4 = dynamic_cast<Square*>(shape); //returns null

    Square* temp2 = new Square("square4");
    Shape* temp3 = dynamic_cast<Shape*>(temp2);

    //coverts pointer/reference from one type to a related type (downcast), must have at leas one virual function
    //run-time check. If succeed temp == square; if fail temp = 0

    //const cast
    //only works on pointer/reference
    //only works on SAME type
    //cast away constnes sof object
    //cast away constness of object being pointed to

    //reinterpret_cast only used on pointers ot cast to different types
    //types can be unrelated, lots of room to make mistakes
    long p = 12312312;
    Shape* s4 = reinterpret_cast<Shape*> (p);

    //c-style casting
    short a = 2000;
    int k = (int)a;
    int j = int(a);
    //mixture of all casts above except dynamic casting
    //c++ style generates less usage error, more narrowly specified
    //and runtime check capability
    return 0;
}
