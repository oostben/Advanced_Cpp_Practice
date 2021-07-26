#include <iostream>

using namespace std;

//Argument Dependent lookup
//when compiler see a function it will search
// 1)Local
// 2)Global
// 3)space where argument type is defined


//namespaces must be defined in global or other namespace
namespace A {
    struct Shape {
        unsigned numSides; 
    };
    unsigned getNumSides(Shape s){ return s.numSides;}
}
// unsigned getNumSides(A::Shape s){ return s.numSides;} //wont work becuase there are two getNumSides, call is ambiguous


void part1(){
    A::Shape s1;
    cout << getNumSides(s1) << "\n"; // works because of koenig lookup or argument dependednt lookup
}

class B {
    public:
        struct Y {};
        static void f(Y input){
            cout << "calling B::f\n";
        }
};


void part2(){
    B::Y temp;
    // f(temp); //wont work the koenig lookup only works for namespace
}

namespace C {
    void getNumSides(A::Shape){ cout << "calling C's getNumSides()\n";}

    void j() {
        A::Shape s1;
        // getNumSides(s1); //ambiguous call, can't have same funtion name in both argument's namespace and current namespace
        //if its a class it will work, class member functions are more tightly boud than other funtions
        //member function from parent class also more tightly bound than koenig lookup
    }
}

void part3(){
    C::j();
}

namespace D{
    void g(int){cout << "calling D::g()\n";}

    namespace E {
        void g() { cout << "calling D::E::g()\n";}
        void j(){
            // g(8); // will not work D::g(int) is shadowed by D::E's g(), so it hides g(int)
            //either delete D::E::g(), or do this:
            using D::g;
            g(8);
        }
    }
}

void part4(){
    D::E::j();
}

int main(){
    part1();
    part2();
    part3();
    part4();
}

//with_namespaces:
//current scope +> next enclosed Scope => . . . => global scope

//To overide this sequence:
//1)quallifier or using declaration
//2)koenig lookup



//with classes:
//current class scope => parent scope => ... => global scope

//To overide this sequence:
//qualifier or using declaration

//name hiding occurs when a higher priority scope defines function with the same name
