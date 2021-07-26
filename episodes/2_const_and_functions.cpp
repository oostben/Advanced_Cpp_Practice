#include <iostream>
using namespace std;
//note const function can only call other const functions to maintain constness
//note be careful about implicit conversion and constructions when returning const 
//modifies num elsewhere
int plusOnePassByRef (int & num) {
    num++;
    return num;
}

//use for smaller data types
int plusOnePassByval (int num) {
    num++;
    return num;
}

//save memory, no copy constructor called
//use whenever possible
int plusOnePassByConstRef (const int & num) {
    // num++;
    return num;
}

//useless:
int plusOnePassByConstval (const int num) {
    // num++;
    return num;
}

//compiler can't tell differece between these two:
// void duplicateForExample(const int num) {
//     int dummy = num;
// }
// void duplicateForExample(int num) {
//     int dummy = num;
// }

//return by reference
const double & retRef (int i) {
    return static_cast<double>(i);
}

class UnitSquare {
    public:
        int getArea() const {cout << "const\n"; return accessCounter;}
        int getArea() {cout << "nonconst\n"; accessCounter++; return accessCounter;}
    private:
        int accessCounter = 0;
};

int main() {
    int temp = 0;
    plusOnePassByRef(temp);
    cout << temp << endl;
    plusOnePassByval(temp);
    cout << temp << endl;
    plusOnePassByConstRef(temp);
    cout << temp << endl;
    plusOnePassByConstval(temp);
    cout << temp << endl;
    // duplicateForExample(temp);
    cout << temp << endl;
    double test1 = retRef(temp); // works but test1 s not const
    // double& test2 = retRef(temp); cannot conert doesn't work
    const double test3 = retRef(temp); // intended

    test1++;
    cout << test1 << endl;

    UnitSquare s1;
    const UnitSquare s2;
    s1.getArea();
    s2.getArea();
}

// Suppose that a function has the signature

// std::string GetString();
// and that it returns a new string by value. Now given the following code:

// // (a) Store the return value to a const reference.
// const std::string& my_string = GetString();

// // (b) Store the return value to a (const) value.
// const std::string my_string = GetString();

// (a) extends the life of the temporary object returned by GetString().

// (b) makes a new object. 