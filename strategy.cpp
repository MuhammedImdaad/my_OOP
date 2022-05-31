#include <iostream>

using namespace std;

/*
In Strategy pattern, a class behavior or its algorithm can be changed at run time. This type of design pattern comes under behavior pattern.
Strategy is a behavioral design pattern that lets you define a family of algorithms, put each of them into a separate class, and make their objects interchangeable.

In Strategy pattern, we create objects which represent various strategies and a context object whose behavior varies as per its strategy object. The strategy object changes the executing algorithm of the context object.

The original class, called context, must have a field for storing a reference to one of the strategies. The context delegates the work to a linked strategy object instead of executing it on its own.

The context isn’t responsible for selecting an appropriate algorithm for the job. Instead, the client passes the desired strategy to the context. In fact, the context doesn’t know much about strategies. It works with all strategies through the same generic interface, which only exposes a single method for triggering the algorithm encapsulated within the selected strategy.

This way the context becomes independent of concrete strategies, so you can add new algorithms or modify existing ones without changing the code of the context or other strategies.
*/


class FlyBehaviour
{
public:
    virtual void fly() = 0;
    virtual ~FlyBehaviour(){};
};

class FlywithWings : public FlyBehaviour
{
public:
    virtual void fly() {cout << "I can fly with my wings\n";}
};

class FlyNoWay : public FlyBehaviour
{
public:
    virtual void fly() {cout << "I can not fly\n";}
};



class Duck
{
    protected:
    FlyBehaviour *flyBehaviour = NULL; //imitating interface in Java 

public:
    virtual void display() = 0;
    void swim() { cout << "swimming\n"; }
    void setFlyBehaviour(FlyBehaviour* newflyBehaviour)
    {
        delete flyBehaviour;
        flyBehaviour = newflyBehaviour;
    }
    void fly(){ flyBehaviour->fly();}
    virtual ~Duck(){};
};


class MallardDuck : public Duck
{
public:
    MallardDuck()
    {
        flyBehaviour = new FlywithWings;
    }
    virtual void display() { cout << "I am a mallard duck\n"; }
};


class ModelDuck : public Duck
{
    virtual void display() { cout << "I am a model duck\n"; }
};


class RubberdDuck : public Duck
{
    public:
    RubberdDuck()
    {
        flyBehaviour = new FlyNoWay;
    }
    virtual void display() { cout << "I am a rubber duck\n"; }
};


int main()
{
    //different types of ducks and different ways of flying are seperate entities
    // with pure inheritence, if fly behaviour needs to be changed all the derived duck classes need to be changed and sometimes the base class. with this setup only the relavent fly behavioural class need to be altered.

    Duck *mallard = new MallardDuck; //defaults with flying 
    mallard->display(); //pure virtual function
    mallard->fly(); //perform the flybehaviour
    mallard->swim(); //base class function
    mallard->setFlyBehaviour(new FlyNoWay); //change the flybehaviour in run time
    mallard->fly();
}
