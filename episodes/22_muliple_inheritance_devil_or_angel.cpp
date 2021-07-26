#include <iostream>

using namespace std;

// example 1: 
// class InputFile {
//     public:
//         void read();
//         void open();
//     private:
//         // void open();
// };

// class OutputFile {
//     public:
//         void write();
//         void open();
// };

// class IOFile:public InputFile, public OutputFile {

// };

// int main() {
//     // this will not compile because the IOFile has two open functions
//     IOFile f;
//     f.open()
//     //even if the open() function is private in one of the classes it will still fail
//     //this is because before the compiler looks at the accessability of a function 
//     //it tries to determine the best function to call, so it still fails even if 
//     //one of the open() functions is private because it still looks at both and sees a duplicate
    
//     //to actually call one of the open functions you need to call like this:
//     f.OutputFile::open()

// }

//example 2:

// class File {
//     public:
//         string name;
//         void open();
// };

// class InputFile: public File{

// };

// class OutputFile: public File{
    
// };

// class IOFile :public InputFile, public OutputFile{
    //diamond shaped hierarchy problem
    //both input and output can refer to the same open()
    // NOT problem is that both input and output file inherit different instances of open
    //
    // IOFIle f;
    // f.open()

    //also has two different instances of name
    // f.InputFile::name = "file1"
    // f.OutputFile::name = "file1"

    //C++ has a solution to this called virtual inheritance:
    //class OutputFile : virtual public File { ...}
    //class InputFile : virtual public File { ...}
    //we are telling the compiler that we only need one instance of name and open()


    //virtual inheritance introduces a new problem: construction:
    // File(string fname);
    //each child must explicitly construct the derived class in their consturctors:
    // IOFIle(string fname): OutputFile(fname), InputFile(fname) {}
    // OutputFile(string fname): File(fname) // now we are intializing two different instances of file
    // InputFile(string fname): File(fname) 

    //c++ defines a rule to handle this: the initializaton of the VIRTUAL base class is the responsibility of the most derived class
    // if ewe do this: IOFIle(string fname): OutputFile(fname), InputFile(fname) File(fname){} then the calls to contruct virtual File in OutputFile and InputFile will be ignored.
    //this is not inuitive
// };

// example 3: how to actually do it
class File {
    protected:
    File(string fname) :name_(fname){}
        string name_;
        void open();
};

class InputFile: virtual public File{
    protected:
        InputFile(string fname):File(fname) {}
};

class OutputFile: virtual public File{
    protected:
        OutputFile(string fname):File(fname) {}

};

class IOFile :public InputFile, public OutputFile{
    public:
        IOFile(string fname): OutputFile(fname), InputFile(fname), File(fname){};
};

int main(){
    IOFile f("tempFile");

}

//Pure abstract classes --> a class that has one or more pute virtual functions are
//      -no data
//     -no concrete functions

// example:
// class OutputFile {
//     public:
//         void write() = 0;
//         void open() = 0;
// }