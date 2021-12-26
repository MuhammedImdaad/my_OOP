#include <iostream>

class AbstractEmployee // if marked final no one can inherit from
{
public:
    virtual void askForPromotion(void) = 0;
    virtual ~AbstractEmployee(){};
};




class Employee : AbstractEmployee
{
private:
    std::string company;
    int age;

protected:
    std::string name;

public:
    Employee(std::string Name, std::string Company, int Age)
        : company(Company), age(Age), name(Name) //
          {
              // name = Name;
              // company = Company;
              // age = Age;
          };

    static void greetings() { std::cout << "good morning\n"; }
    void introduce()
    {
        std::cout << "my name is " << name << " , my age is " << age << " and I work for " << company << std::endl;
    }

    void setName(std::string name) { this->name = name; };
    std::string getName(void) { return name; };

    void setAge(int age)
    {
        if (age > 20 && age < 80)
            this->age = age;
        else
            std::cout << "input age is not valid\n";
    };
    int getAge(void) { return age; };

    void askForPromotion(void) override
    {
        if (age > 30)
            std::cout << "allow promotion\n";
        else
            std::cout << "do not allow promotion\n";
    };
    virtual void work() // if not virtual, the different objects wont be accessing the most derived function definition
    {
        std::cout << name << " working as a general employee\n";
    }
    virtual ~Employee(){};
}; // access modifier public, protected, private





class Developer : public Employee
{
public:
    std::string languages;
    Developer(std::string name, std::string company, int age,
              std::string program)
        : languages(program), Employee(name, company, age) // constructor initializer list
    {
        // languages = program;
    }
    void codefix(void)
    {
        std::cout << getName() << " fixed the bug, " << name << " is remarkable" << std::endl;
    }
    void work() override
    {
        std::cout << name << " working as a developer\n";
    }
};





class Teacher : public Employee
{
private:
    std::string subject;

public:
    Teacher(std::string name, std::string company, int age, std::string subject)
        : Employee(name, company, age)
    {
        this->subject = subject;
    }
    void work(std::string place)
    {
        std::cout << name << " working as a teacher in " << place << std::endl;
    }
    void work() override
    {
        std::cout << name << " working as a teacher\n";
    }
};





int main()
{
    Employee::greetings(); // static function
    Employee employee1("sarath", "youtube", 31);
    employee1.introduce();

    // encapsulation - binding the attributes and methods, protecting the attributes
    employee1.setName("jagath");
    employee1.setAge(19);
    std::cout << employee1.getName() << std::endl;

    // abstraction - hiding the complex side and abstract class
    employee1.askForPromotion();

    // inheritance - deriving features from a base or parent class
    Developer devop1("sudath", "amazon", 35, "C++");
    devop1.introduce();
    devop1.codefix();

    Teacher teacher("anna", "royal", 29, "science");
    // teacher.askForPromotion(); wont work if privately inherited

    // polymorphism
    employee1.work();
    devop1.work();
    // static/compileTime polymorphism
    teacher.work();
    teacher.work("primary section");
    // dynamic/runtime polymorphism
    // each class will have one instance of a virtual table and each object will have own virtual pointer
    Employee *d = &devop1; //upcasting
    d->work();
    Developer* dNew = dynamic_cast<Developer*>(d); //downcasting
    if (dNew) std::cout << "this employee is a developer\n";

    Employee *t = &teacher;
    t->work();
    Developer* tNew = dynamic_cast<Developer*>(t);
    if (tNew==NULL) std::cout << "this employee is not a developer\n";
}
