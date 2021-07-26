class Dog;
class Cat;

class Singleton{
    private:
        
        static Dog* pd;
        static Cat* pc;
    public:
        ~Singleton();
        static Dog* getDog();
        static Cat* getCat();
};