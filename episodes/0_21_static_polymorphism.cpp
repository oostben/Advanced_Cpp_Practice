//Static Polymorphism

//Basically the idea here is rather than dealing with the dynamic lookup table at runtime to 
//resolve virtual functions create a templated class that generates a different version of
//the base class for every derrived class so that resolving the virtual functions is simply 
//static casting this to the derived class. See beloe.

#include <iostream>
using namespace std;
using namespace std::chrono;

//Before static Polymorphism --> takes 41 microseconds
//------------------------------------------------------------------------
class Shape {
    public:
        virtual int get_num_sides(){}
};

class Square: public Shape {
    public:
        Square(int sides=4): m_num_sides(sides) {}
        
        virtual int get_num_sides(){
            return m_num_sides;
        }
    private:
        int m_num_sides;
};

//------------------------------------------------------------------------
//After static Polymorphism --> takes 29 microseconds
//------------------------------------------------------------------------

//  template<typename T> class Shape {
//     public:
//         int get_num_sides(){ return static_cast<T*>(this)->get_num_sides(); }
        
// };

// class Square: public Shape<Square>{
//     public:
//         Square(int sides=4): m_num_sides(sides) {}
//         int get_num_sides(){ return m_num_sides;}
//     private:
//         int m_num_sides;
// };
//------------------------------------------------------------------------

int main() {
    auto start = high_resolution_clock::now();

    Square s1 = Square();
    std::cout << s1.get_num_sides() << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
}

