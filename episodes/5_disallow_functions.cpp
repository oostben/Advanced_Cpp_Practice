#include <iostream>
using namespace std;

class OpenFile {
    public:
        OpenFile(string FileName) { 
            cout << FileName << " open" <<endl; 
        }
        //delete copy constructor so that you cant write two files at once
        // OpenFile(OpenFile& rhs) = delete;

        //public interface to destruct object

        void destroyMe(){delete this;}
    private:
        OpenFile(OpenFile& rhs); //old way to remove copy constructor
        OpenFile & operator=(OpenFile& rhs); //remove assignemnt operator
        //can disallow any fucntion in here

        //private destructor
        //will fail becuase destructor is private
        //cannot be destroyed by anyone but friends and self
        ~OpenFile() {cout << "openfile destructed" << endl;}
        //!!private destructor classes can only be stored on heap not stack
        //can be used in embeded program that have small stack to preevent stack overflow with private destructor

};
int main() {
    // OpenFile f; wont compile default is overidden
    // OpenFile f1("file1");
    // OpenFile f2(f1); // messey, two files writing to the same fuction.
    OpenFile* f3 = new OpenFile("file3");
    f3->destroyMe();
    //still calls destructor twice even after it was deleted once

}
