#include <iostream>
#include "singleton.h"
#include "dog.h"
#include "cat.h"


// #include "dog.cpp"
// #include "..."

using namespace std;

//program has a 50 by 50 chance of crashing
int main(){
    cout << "main start\n";
    Singleton::getCat()->meow();
    return 0;
}