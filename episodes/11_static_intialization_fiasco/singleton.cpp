#include "singleton.h"
#include "dog.h"
#include "cat.h"

Dog* Singleton::pd = 0;
Cat* Singleton::pc = 0;

Dog* Singleton::getDog(){
    if (!pd){
        pd = new Dog("Gunner"); //Initialize upon first usage idiom
    }
    return pd;
}

Cat* Singleton::getCat(){
    if (!pc){
        pc = new Cat("Smokey");
    }
    return pc;
}

Singleton::~Singleton() {
    if (pd) delete pd;
    if (pc) delete pc;

    pd = 0;
    pc = 0;

}