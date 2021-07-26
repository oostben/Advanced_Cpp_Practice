#include <iostream>
using namespace std;
#include <mutex>

std::mutex mtx; 

void nonRAII() {
    mtx.lock();
    // . . . do a bunch of stuff holding the lock

    //problem arises if this code throws an exception
    //then what?
    //lock is locked forever

    mtx.unlock();
}

//RAII section

class Lock {
    private:
    std::mutex *m_mutex;
    
    public:
    //remember to make sure the resource manager class cannot be copied, or else destructor will run twice
    Lock(Lock& rhs) = delete;
    //or you can use smart pointers to manage scope
    // shared pointer can also take a custom deleter to aid this process:
    //template<class Other, class D> shared_ptr(Other * ptr, D deleter)

    explicit Lock(std::mutex * mutex) {

        m_mutex = mutex;
        m_mutex->lock();
        cout << "lock accquired" << endl;

    }   
    ~Lock(){
        m_mutex->unlock();
        cout << "lock released" << endl;
    }
};

// class Lock2{
//     private:
//     shared_ptr<std::mutex> m_pMutex;
//     public:
//     explicit Lock(std::mutex * pm):m_pMutex(pm, m_pMutex->unlock) {
//         pm->lock;
//     }
// }

void RAII() {

    //do stuff before locking
    {
        Lock temp(& mtx);
        //lock is held in this scope
        // do stuff with lock held
        cout << "lock held" <<endl;
        //lock goes out of scope
    }
    //do stuff after locking
    cout << "so other stuff\n";
}

class Shape{
    int temp = 3;
};

void smartPointerRAIIExample(){
    std::shared_ptr<Shape> sp (new Shape());
    std::shared_ptr<Shape> ptr2 (sp);
    std::shared_ptr<Shape> ptr3 (sp);
}

int main() {
    nonRAII();
    RAII();
    smartPointerRAIIExample();
    return 0;
}


//be careful with smart pointers in function arguments
// dont combine the creation of smart pointer with any other statement
class Dog;
class Trick;
void train(shared_ptr<Dog> pd, Trick dogtrick);
Trick getTrick();

int main2(){
    train(shared_ptr<Dog> pd(new Dog), getTrick());
    //what could happen above is the order is undefined
    // a new dog could get created, then the getTrick() could run and throw
    // an exception and then we would have a memory leak
}


