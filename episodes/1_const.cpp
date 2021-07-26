//Const
#include <iostream>
using namespace std;

int main() {
    // const int i = 2; // i is a const int
    // // i = 3; won't work, i is const
    // // int temp = 3;
    // // int & ref = temp;
    // const int *j = &i; //j is a pointer to a const int, i is const, j is not
    // int const *o = &i; //same thing as above

    // cout << *j << endl; 
    // j++; 
    // j--;
    // cout << *j << endl; 
    // //*j++; fails, data is const
    // int k = 33;
    // int * const p2 = &k; // p2  is a const pointer to an int
    // cout << ++*p2 << endl;

    // const int * const p3 = &i; //both the data and pointer are const
    // //int * const p4 = &i; // fails, if rvalue is const, the pointer must point to const

    //-------------------------------------------
    //const casting section

    const int i = 4;
    const_cast<int&>(i)++; // casted away constness
    cout << i << endl;

    int j = 5;
    //static_cast<const int &>(j) // fails, casting to const
    int k = static_cast<const int &>(j);
    k++;
    const int l = static_cast<const int &>(j);
    // l++; // fails now casting to const
    cout << k << endl;

    //cast is hacky way of coding
    //cast can help
        //guard against inadvertent change of variable
        //self documenting
        //enables faster code, tighter code
        // data can be put into ROM

}
