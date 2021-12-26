
#include <iostream>
using namespace std;


/* solving diamond problem using virtual inheritence*/
class Person
{
public:
    Person(int x) { cout << "Person::Person(int ) called" << endl; }
    Person() { cout << "Person::Person() called" << endl; }
};

class Faculty : virtual public Person
{
public:
    Faculty(int x) : Person(x)
    {
        cout << "Faculty::Faculty(int ) called" << endl;
    }
};

class Student : virtual public Person
{
public:
    Student(int x) : Person(x)
    {
        cout << "Student::Student(int ) called" << endl;
    }
};

class TA : public Faculty, public Student
{
public:
    TA(int x) : Student(x), Faculty(x)
    { // add Person(x) if you want to explicitly call the parameterized constructor
        cout << "TA::TA(int ) called" << endl;
    }
};


//multiple inheritance with conflicting signatures
class A
{
    int idA;

public:
    void setId(int i) { idA = i; }
    int getId() { return idA; }

    virtual void foo() = 0;
};

class B
{
    int idB;

public:
    void setId(int i) { idB = i; }
    int getId() { return idB; }

    virtual void foo2() = 0;
};

class AB : public A, private B
{
public:
    void foo() override {}
    void foo2() override {}

    //    using A::getId;
};



int main()
{
    // TA ta1(30);
    AB ab;
    ab.A::setId(10);
    cout << ab.A::getId();
    return 0;
}