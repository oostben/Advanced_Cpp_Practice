#include <iostream>

using namespace std;

int part1(){
    //keyword using:
    //1) using directive: to bring all namespace members into current scope
    //example:
    using namespace std;

    //2) using declaration
        // a)bring one speific namespace meber into current scope
        // !!b)bring a member from a baseclass to current classes scope
        //example:

    {
        using std::cout;
        cout << "hello world" << endl;
    }
    return 0;
}

class Shape{
    public:
        void sayHi(){ cout << "hi from shape\n"; }
};

class Square: private Shape{
    public:
        void whoAreYou(){
            using namespace std;
            cout << "I'm Square\n";
        }
        void whoAreYouAgain(){
            using namespace std;
            cout << "I'm Square!\n";
        }
        using Shape::sayHi; // only one in class scope, and can't be using in other scope
        //using std::cout; // illegal in class scope
        // using namespace std; // illegal in class scope
};


//anonymous namespace: namespace without a name 
//everything in anoymous will be accesable in current file
//wont be able to be accessed from a differnet file

void g() {cout << "global\n";}
namespace {
    void g() {cout << "local\n";}
    void f() {
        cout << "f called\n";
        g(); // local version called
    }

    //effectivley the same as a global static void f()
    //however this has the additional benefit of namespace
}
//
void part2(){
    Shape sh1;
    Square sq1;
    sh1.sayHi();
    sq1.whoAreYou();
    sq1.whoAreYouAgain();
    sq1.sayHi();
}

//can also be used to ge to shadowed functions, (get around name hiding)
int main(){
    part1();
    part2();
    f();
}
