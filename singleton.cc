#include <iostream>

class Singleton
{
private:
    std::string name = "this is a singleton object";

    Singleton(int id) 
        : number(id)
    {
        std::cout << "created object\n";
    };

public:
int number;
    static Singleton *getInstance(int id)
    {
        static Singleton *s = new Singleton(id);
        return s;
    }

    void printName() { std::cout << name << std::endl << "instance ID : " <<number << std::endl; }

    void setName(std::string newName) { name = newName; }
};

int main()
{
    Singleton *s1 = Singleton::getInstance(1);
    s1->printName();
    s1->setName("this is the only singleton object");
    Singleton *s2 = Singleton::getInstance(2);
    s2->printName();
    return 0;
}