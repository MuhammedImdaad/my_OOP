#include <iostream>
using namespace std;

/*
Decorator is a structural design pattern that lets you attach new behaviors to objects by placing these objects inside special wrapper objects that contain the behaviors.
the decorator pattern is a design pattern that allows behavior to be added to an individual object, dynamically, without affecting the behavior of other objects from the same class.
“Wrapper” is the alternative nickname for the Decorator pattern that clearly expresses the main idea of the pattern.
*/

class FoodItem
{
public:
    virtual string description() = 0;
    virtual double cost() = 0;
    virtual ~FoodItem(){};
};

class ThinPizza : public FoodItem
{
public:
    string description()
    {
        return "thin pizza";
    }
    double cost() { return 499.99; }
};

class CrustPizza : public FoodItem
{
public:
    string description()
    {
        return "crust pizza";
    }
    double cost() { return 1099.99; }
};

class Topping : public FoodItem // isn't a concrete class, an abstract class to various toppings. But since it's a topping it has wrapped main dish to server
{
protected:
FoodItem *wrappedItem;
public:
    virtual ~Topping(){};
    
};

class Olive : public Topping 
{
public:
    Olive(FoodItem *wrapper)
    {
        wrappedItem = wrapper;
    };

    string description()
    {
        return wrappedItem->description() + ", olive ";
    }
    double cost() { return wrappedItem->cost() + 30.99; }
};

class Cheese : public Topping
{
public:
    Cheese(FoodItem *wrapper) { wrappedItem = wrapper; };

    string description()
    {
        return wrappedItem->description() + ", cheese";
    }
    double cost() { return wrappedItem->cost() + 10.99; }
};

int main()
{
    FoodItem *item1 = new ThinPizza;
    item1 = new Cheese(item1); // wraps pizza
    item1 = new Cheese(item1); // wraps cheese
    item1 = new Olive(item1);  // wraps cheese

    // when these functions are called, it gets executed as a recursive call because each item has its corresponding wrapped item
    cout << "DESC: " << item1->description() << " COST: " << item1->cost() << endl;

    FoodItem *item2 = new CrustPizza;

    cout << "DESC: " << item2->description() << " COST: " << item2->cost() << endl;
}