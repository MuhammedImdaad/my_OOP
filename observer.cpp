#include <iostream>
#include <vector>

using namespace std;

/*Observer is a behavioral design pattern that lets you define a subscription mechanism to notify multiple objects about any events that happen to the object they’re observing.
That’s why it’s crucial that all subscribers implement the same interface and that the publisher communicates with them only via that interface. This interface should declare the notification method along with a set of parameters that the publisher can use to pass some contextual data along with the notification.
*/
class Observer
{
    public:
    virtual void update(double)=0;
    virtual ~Observer(){};
};

class WeatherStation
{
    double temperature;
    double windSpeed;
    double pressure;

    vector<Observer*> observers;

    public:
    void notifyObservers()
    {
        for(auto observer: observers)
        {
            observer->update(temperature);
        }
    }
    void setTemp(double temperature)
    {
        this->temperature = temperature;
        notifyObservers();
    }
    void addObserver(Observer* observer){ observers.push_back(observer);}


};


class UserInterface : public Observer
{
    double temperature;
    double windSpeed;
    double pressure;  

    public:

    void update(double temperature)
    {
        this->temperature = temperature;
        display();
    }
    void display()
    {
        cout << "display Temp : " << temperature << endl;
    }
};

class Logger : public Observer
{
    double temperature;
    double windSpeed;
    double pressure;

    public:
    void update(double temperature)
        {
        this->temperature = temperature;
        log();
    }
    void log()
    {
        cout << "log Temp : " << temperature << endl;
    }

};

int main()
{
    WeatherStation weatherStation;
    Observer* userInterface = new UserInterface;
    Observer* logger = new Logger;

    // add observers
    weatherStation.addObserver(userInterface);
    weatherStation.addObserver(logger);

    // update the station and notify observers
    weatherStation.setTemp(30.3);

}
