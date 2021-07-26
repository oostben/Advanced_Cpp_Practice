#include <iostream>
using namespace std;

//struct for small passive objects that carry public data and have no or few basic member functions
struct PersonStruct { // public by default
    string name;
    unsigned age;
};

//bigger active objects that carry private data, interfaced through public member functions
//complex data structure
class PersonClass { // private by default
    string name_;
    unsigned age_;

    public:
    unsigned age() const {return age_;} // getter

    void setAge(unsigned a){ // setter
    if (a > 200) {
        return;
    }
        age_ = a;
    }
};

int main() {
    PersonStruct p1;
    cout << p1.age << endl;

    PersonClass p2;
    cout << p2.age() << endl;
    p2.setAge(4);
    cout << p2.age() << endl;
    p2.setAge(201);
    cout << p2.age() << endl;


}
