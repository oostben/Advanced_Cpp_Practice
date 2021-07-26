#include <iostream>
using namespace std;

//this section covers how to stop a class from self assignment in overloaded = operator

//looks silly:
// Shape s;
// s = s;

//doesn't look so silly:
// shapes[i] = shapes[j];// when i==j

class Sides{
    public:
        int m_numSides;
};

class Shape {
    public:
        Sides * m_sides = new Sides();
        Shape& operator=(const Shape& other) {
            if (this == &rhs) {
                return *this
            }
            Sides *original_m_sides = m_sides
            m_sides = new Sides(*other.m_sides); // problem if this throws an exception, so we store a copy
            delete m_sides;

            //could also pass the job onto Sides:
            // *m_sides = *other.m_sides;

            return *this;
        }
        ~Shape(){
            delete m_sides;
        }
};
int main() {
    Shape shape1;
    Shape shape2;
    shape1 = shape2;
    cout << "finished" << endl;
 }