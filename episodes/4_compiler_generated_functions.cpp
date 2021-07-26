
#include <iostream>
using namespace std;
//compiler silently generates for functions:
//-copy constructor
//-copy assignment operator
//-destructor
//-default constructor (only if no constructor defined)

class Shape1 {
    public:
        //compiler generated signatures:

        // Shape(const Shape & rhs) {} //member by member intialization
        // Shape & operator=(const Shape & rhs) {} // copy, oftem time be careful for shallow copies
        // Shape() {} // call base class default constructor; call members' default constructor
        // ~Shape(){}// call base class destructor; call members' destructors
        // int &m_num1; //doesn't work because default constructor will not be defined if there is an unitialized ref
        
        int temp = 4;
        int &m_num2 = temp; //default constructor works

        // const int m_num3; //default constructor wont generate, unitialized const
        const int m_num4 = 4; 

};

//compiles alone, doesn't if used
// doesn't have default constructor
// class Shape {
//     public:
//         Shape(string name) {
//             cout << "Shape constructed " << name << endl;
//         }
// };

// class Square {
//     Shape s;
// };

//doesn't compile no default constructor on base class
// class Shape {
//     public:
//         Shape(string name) {cout << "Shape constructed " << name << endl;}
// };
// class Square : public Shape{};

//compiles, expiliclty dedfined default constructor
class Shape {
    public:
        Shape() = default;
        Shape(string name) {cout << "Shape constructed " << name << endl;}
};
class Square : public Shape{};


//what hapens if compiler is unable to do its job
//what if one of the members is 
//const and refrence cannot be copied, only intialized

int main() {
    Shape1 s1 = Shape1();
    // Shape1 s1();
    Square s3 = Square();
}
