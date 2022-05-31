#include <iostream>
using namespace std;

//Adapter is a structural design pattern that allows objects with incompatible interfaces to collaborate. You can create an adapter. This is a special object that converts the interface of one object so that another object can understand it.

class Client
{
    string name;
    int age;

public:
    Client(string name, int age) : name(name), age(age) {}
    virtual string getName() { return name; }
    virtual int getAge() { return age; }
    virtual ~Client(){};
};

class DifferentClient
{
    string name;

public:
    DifferentClient(string name) : name(name) {}
    string getName() { return name; }
};

// target won't support any new clients
class Target  
{
public:
    static void serverClient(Client *client)
    {
        cout << client->getName() << " is " << client->getAge() << " years old\n";
    }
};

// in order to make an interface which, the target can understand, adaptor wraps the adaptee(different client) and converts in into a client object
class Adaptor : public Client
{
public:
    Adaptor(DifferentClient *difClient, int age)
        : Client(difClient->getName(), age)
    {}
};

int main()
{
    Client *c1 = new Client("imdaad", 24);
    Target::serverClient(c1);

    DifferentClient *c2 = new DifferentClient("muhammed");
    Client *c3 = new Adaptor(c2, 50);
    Target::serverClient(c3);
}