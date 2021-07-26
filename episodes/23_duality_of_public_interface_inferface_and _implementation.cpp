#include <iostream>

using namespace std;

//duality of public inheritance

// -inheritance of interface
// -inheritance of implementation

// could inherit one, the other, or both

//111111111111111111111111111111111111
//Interface only:

//pure virtual (abstract)
// class Dog {
//     public:
//         virtual void bark() = 0;
// };

// //interface only
// class YellowDog: public Dog{
//     public:
//         virtual void bark() { cout << "I am a yellow dog\n";}
// };


//2222222222222222222222222222222
//Interface & Implementation:
// class Dog {
//     public:
//         virtual void bark() = 0;
//         void run() {cout < "I am running\n";}
// };

// class YellowDog: public Dog{
//     public:
//         virtual void bark() { cout << "I am a yellow dog\n";}
// };


//333333333333333333333333333333333333
//Interface & Implementation #2 giving child class option :
//now Yellow dog can choose to override the eat function, so it can inherit the implementation
// class Dog {
//     public:
//         virtual void bark() = 0;
//         void run() {cout < "I am running\n";}
//         virtual void eat() {cout << "I am eating\n";}
// };

// class YellowDog: public Dog{
//     public:
//         virtual void bark() { cout << "I am a yellow dog\n";}
// };


//non pure virtual function provides an iheritance of the interface as well as a default implementation

//44444444444444444444444444444444444444
//Implementation only (protected):
// class Dog {
//     public:
//         virtual void bark() = 0;
//         void run() {cout < "I am running\n";}
//         virtual void eat() {cout << "I am eating\n";}
//     protected:
//         sleep() {cout << "I am sleeping \n"}
// };

// class YellowDog: public Dog{
//     public:
//         virtual void bark() { cout << "I am a yellow dog\n";}
//         void iSleep() {
//             //yellow dog defines interface for sleep
//             sleep();
//         }
// };


int main(){
    
}