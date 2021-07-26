#include <iostream>

using namespace std;

//class name is part of the interface

//code reuse with inheritance
// class Shape {
//     ...
//     //common activites
// };

// class Triangle: public Shape {
//     ...
//     //call common actiities to preform more tasks
// };

// class Square: public Shape {
//     ...
//     //call common actiities to preform more tasks

// };

//code reuse with composition:
class ActivityManager {
    //define common activites
};

class Shape{};

class Triangle: public Shape{
    ActivityManager* pActivityMananger_;
};

class Square: public Shape{
    ActivityManager* pActivityMananger_;
};

//code reuse > inheritance vvvvvv

// 1)less code coupling betweeen reused code and reuser of code
//     a) child class automatically inherits all parent class's public members
//     b) child class can access parent's unprotected members
//          -inheritance breaks encapsulation
//          -firends breaks encapsulation

//2) Dynamic binding:
//  a)inheritance is buound at compile time 
//  b)composition can be bound at either compile time or at run time

//3) flexible code construct
    
