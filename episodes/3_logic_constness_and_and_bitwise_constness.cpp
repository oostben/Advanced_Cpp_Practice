#include <iostream>
using namespace std;
#include <vector>

class Array{
    private:
        vector<int> m_bigArray;
        size_t m_accessCounter;
        mutable size_t m_accessCounterMutable;
    public:
        //const function read only no issues, pass by value out
        int getItemReadOnlyBitwiseVal(int index) const{
            return m_bigArray[index];
        }

        //fails -> cant return a ref out of a const function
        // int& getItemReadOnlyBitwise(int index) const{
        //     return bigArray[index];
        // }

        //const function read only no issues, pass by const ref out
        const int& getItemReadOnlyBitwiseRef(int index) const{
            return m_bigArray[index];
        }
        
        //increment access with non const function
        int getItemNonConst(int index) {
            m_accessCounter++;
            return m_bigArray[index];
        }
        
        //how it should be done with mutale and logical constness maintatined
        int getItem(int index)const{
            m_accessCounterMutable++;
            return m_bigArray[index];
        }

        //work around for logical constness
        int getItem2(int index) const{
            const_cast<Array*>(this)->m_accessCounter++;
            return m_bigArray[index];
        }

        //logical constness
        void printAccess()const {cout << m_accessCounter << " " << m_accessCounterMutable << endl;}

        void addITem(int item) {
            m_bigArray.push_back(item);
        }
};

int main(){
    Array arr = Array();
    arr.addITem(5);
    arr.getItemNonConst(0);
    arr.getItem(0);
    arr.getItem2(0);
    arr.printAccess();

}