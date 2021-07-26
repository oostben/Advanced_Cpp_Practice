#include <iostream>
#include <vector>

using namespace std;

class Person {
    public:
        Person(string name) {
            // personName_.reset(new string(name));
            personName_ = new string(name);
        }
        friend void swap(Person & first, Person & second) {
            std::swap(first.personName_,second.personName_);
        }

        Person(const Person& other) {
            personName_ = new string(*other.personName_);
        }
        Person & operator= (Person other){
            swap(*this,other);
            return *this;
        }


        ~Person() {
            // delete personName_;
        }
        void printName() {
            cout << *personName_ << endl;
        }
    private:
        // delete the copy constructor and copy assignemnt operator

        // Person(const Person& other);
        // Person & operator=(const Person &other); 
        
        //rarely a case where you need them

        //could also use pointers in main

        //could also define a clone function so that it's more explicit
        //Person*clone() {
        //     return (new Person(*(personName_))))
        // }


        // shared_ptr<string> personName_;
        string *personName_;
};

int main() {
    vector<Person> people;

    people.push_back(Person("George")); //bad, just pushed a copy of george onto the vector, now doouble delete

    //George is constructed
    //copy of george is copies into vector (shallow copy)
    //George is destroyed
    people.back().printName();
    
    cout << "bye\n";

    return 0;
}
