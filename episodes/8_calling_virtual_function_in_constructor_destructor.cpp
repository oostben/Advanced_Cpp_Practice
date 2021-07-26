#include <iostream>
using namespace std;

//virtualness inherited

class Shape {
    public:
        Shape() { 
            cout << "Shape constructed" << endl; 
            // printNumSides(); // at this point the Square is not constructed yet so it calls Shape's getNumSides
            // avoid calling a virtual fucntion in the constructor, only doing the minimal needed to get object
            // setup
        }

        ~Shape() { 
            cout << "Shape destructed" << endl; 
            // printNumSides();
            //same goes for destructor. at this point the square's getNNumSides is already 
            //destructed, so it calls its own version of it
        }


        virtual int getNumSides() { return -1; } // if this function is not virtual -1,if it is 4
        void printNumSides(){ cout << getNumSides() << endl; }
};

class Square : public Shape {
    public:
        Square() { cout << "Square constructed" << endl; }
        
        //virtualness inherited, good idea to always specify that its inherited virtual
        //dynamic binding
        virtual int getNumSides() { return 4; }

        ~Square() {
            cout << "square destructed" << endl;
        }
};

int main() {
    Square s1;
    s1.printNumSides();
}