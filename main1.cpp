#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    int id;
    string name;
    double pricePerDay;
    bool available;

public:
    Vehicle(int i, string n, double price)
        : id(i), name(n), pricePerDay(price), available(true)
    {
    }

    virtual void display()
    {
        cout << id << " - " << name
             << " - Rs. " << pricePerDay << "/day";
        cout << (available ? " - Available" : " - Rented") << endl;
    }

    virtual ~Vehicle()
    {
    }

    double getPricePerDay() const
    {
        return pricePerDay;
    }

    bool isAvailable() const
    {
        return available;
    }

    void setAvailable(bool value)
    {
        available = value;
    }
};

class Car : public Vehicle
{
public:
    Car(int id, string name, double price)
        : Vehicle(id, name, price)
    {
    }

    void display() override
    {
        cout << "Car: ";
        Vehicle::display();
    }
};

class Bike : public Vehicle
{
public:
    Bike(int id, string name, double price)
        : Vehicle(id, name, price)
    {
    }

    void display() override
    {
        cout << "Bike: ";
        Vehicle::display();
    }
};

int main()
{
    Vehicle* vehicles[10];

    vehicles[0] = new Car(101, "Maruti Swift", 1500);
    vehicles[1] = new Car(102, "Hyundai Creta", 2500);
    vehicles[2] = new Car(103, "Tata Nexon", 2200);
    vehicles[3] = new Car(104, "Mahindra Thar", 3500);
    vehicles[4] = new Car(105, "Toyota Innova", 4000);
    vehicles[5] = new Car(106, "Honda City", 2800);
    vehicles[6] = new Car(107, "Kia Seltos", 3000);

    vehicles[7] = new Bike(201, "Honda Activa", 500);
    vehicles[8] = new Bike(202, "Royal Enfield", 1200);
    vehicles[9] = new Bike(203, "TVS Apache", 800);

    cout << "===== VEHICLE RENTAL MANAGEMENT SYSTEM =====" << endl;
    cout << "\nVehicle Details:\n" << endl;

    for (int i = 0; i < 10; i++)
    {
        vehicles[i]->display();
    }

    cout << "\n===== AVAILABILITY CHECK =====" << endl;

    if (vehicles[0]->isAvailable())
    {
        cout << "Maruti Swift is available." << endl;
    }
    else
    {
        cout << "Maruti Swift is not available." << endl;
    }

    cout << "\n===== RENTING A VEHICLE =====" << endl;

    vehicles[0]->setAvailable(false);

    cout << "Maruti Swift has been rented." << endl;
    vehicles[0]->display();

    cout << "\nDaily rental price: Rs. "
         << vehicles[0]->getPricePerDay() << endl;

    for (int i = 0; i < 10; i++)
    {
        delete vehicles[i];
    }

    return 0;
}