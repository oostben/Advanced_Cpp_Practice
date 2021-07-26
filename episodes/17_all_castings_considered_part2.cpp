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
        void sayHi() const {cout << "hi" << endl;}

};

int main() {
    Shape* shape1 = new Shape("shape1");

    Square* square1 = dynamic_cast<Square*>(shape1); // return null, Shape contains no square pointer 
    //dyanamic cast could add to runtime

    // square1->getName();//fails
    if (square1) {
        square1->getName();
    }
    square1->sayHi();//actually works, why? sayHi() is interpreted as a static function
    cout << "shape1" << shape1 << endl; 
    cout << "square1" << square1 << endl;


    return 0;
}

//note in const functions the object pointed to by this (*this) becomes temporarily const
//can replicate mutable by const casting this ponter into normal class pointer

//static cast generates data, must because it casts away the constness of OBJECTS