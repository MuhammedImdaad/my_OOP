#include <iostream>
using namespace std;

/*
Factory Method is a creational design pattern that provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created.
A Factory Pattern or Factory Method Pattern says that just define an interface or abstract class for creating an object but let the subclasses decide which class to instantiate. In other words, subclasses are responsible to create the instance of the class.
*/

class Pizza
{
protected:
public:
    Pizza() { cout << "created pizza\n"; }
    string name;
    virtual ~Pizza() { cout << "consumed pizza\n"; };
};

class NWCheesePizza : public Pizza
{
public:
    NWCheesePizza() { name = "newyork cheese pizza"; }
};

class NWChickenPizza : public Pizza
{
public:
    NWChickenPizza() { name = "newyork chicken pizza"; }
};

class CHCheesePizza : public Pizza
{
public:
    CHCheesePizza() { name = "chicago cheese pizza"; }
};

class CHChickenPizza : public Pizza
{
public:
    CHChickenPizza() { name = "chicago Chicken pizza"; }
};

class PizzaStore
{
private:
    Pizza *pizza;

protected:
    virtual Pizza *createPizza(string type) = 0; //pure virtual function

public:
    void orderPizza(string type)
    {
        pizza = createPizza(type); //since this method will only be called by a subclass since the base class is an abstract class, due to polymorphism this will always revert back to the most derived creatPizza method which is in it's derived class. hence subclass is responsible for pizza creation
        cout << "ordered " << pizza->name << endl;
    };

    virtual ~PizzaStore() { delete pizza; };
};

class NewyorkStore : public PizzaStore
{
    Pizza *createPizza(string type)
    {
        Pizza *pizza;

        if (type == "cheese")
            pizza = new NWCheesePizza();

        else if (type == "chichen")
            pizza = new NWChickenPizza();

        return pizza;
    }
};

class ChicagoStore : public PizzaStore
{
    Pizza *createPizza(string type)
    {
        Pizza *pizza;
        if (type == "cheese")
            pizza = new CHCheesePizza();
        else if (type == "chicken")
            pizza = new CHChickenPizza();

        return pizza;
    }
};

int main()
{
    PizzaStore *order1 = new NewyorkStore;
    order1->orderPizza("cheese");
    delete order1;

    PizzaStore *order2 = new ChicagoStore;
    order2->orderPizza("chicken");
    delete order2;
}