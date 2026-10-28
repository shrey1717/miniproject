#include <iostream>
#include <string>
using namespace std;

// ================= MEMBER 1 =================

// Base Class
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

    int getID() const
    {
        return id;
    }
};

// Derived Class Car
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

// Derived Class Bike
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

// ================= MEMBER 2 =================

// Customer Class
class Customer
{
private:
    int customerID;
    string customerName;

public:
    Customer(int id, string name)
        : customerID(id), customerName(name)
    {
    }

    void display() const
    {
        cout << "\nCustomer ID: " << customerID << endl;
        cout << "Customer Name: " << customerName << endl;
    }
};

// Rental Class
class Rental
{
private:
    int rentalDays;
    double pricePerDay;

public:
    Rental(int days, double price)
        : rentalDays(days), pricePerDay(price)
    {
    }

    double calculateBill() const
    {
        return rentalDays * pricePerDay;
    }

    void displayBill() const
    {
        cout << "\nRental Days: " << rentalDays << endl;
        cout << "Price Per Day: Rs. " << pricePerDay << endl;
        cout << "Total Bill: Rs. " << calculateBill() << endl;
    }
};

// ================= MEMBER 3 =================

int main()
{
    Vehicle* vehicles[10];

    // Creating vehicles
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

    int choice;

    do
    {
        cout << "\n===== VEHICLE RENTAL MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Display All Vehicles" << endl;
        cout << "2. Rent a Vehicle" << endl;
        cout << "3. Return a Vehicle" << endl;
        cout << "4. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        // Display Vehicles
        if (choice == 1)
        {
            cout << "\n===== VEHICLE DETAILS =====" << endl;

            for (int i = 0; i < 10; i++)
            {
                vehicles[i]->display();
            }
        }

        // Rent Vehicle
        else if (choice == 2)
        {
            int id, days, vehicleID;
            string name;
            int index = -1;

            cout << "\nEnter Customer ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Customer Name: ";
            getline(cin, name);

            cout << "Enter Vehicle ID: ";
            cin >> vehicleID;

            // Search Vehicle
            for (int i = 0; i < 10; i++)
            {
                if (vehicles[i]->getID() == vehicleID)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                cout << "Invalid Vehicle ID!" << endl;
            }

            else if (!vehicles[index]->isAvailable())
            {
                cout << "Vehicle is not available!" << endl;
            }

            else
            {
                cout << "Enter Rental Days: ";
                cin >> days;

                if (days <= 0)
                {
                    cout << "Invalid rental days!" << endl;
                }

                else
                {
                    Customer c1(id, name);

                    Rental r1(days, vehicles[index]->getPricePerDay());

                    vehicles[index]->setAvailable(false);

                    cout << "\n===== RENTAL RECEIPT =====" << endl;

                    c1.display();

                    cout << "\nVehicle Details:" << endl;
                    vehicles[index]->display();

                    r1.displayBill();

                    cout << "\nVehicle rented successfully!" << endl;
                }
            }
        }

        // Return Vehicle
        else if (choice == 3)
        {
            int vehicleID;
            int index = -1;

            cout << "\nEnter Vehicle ID to Return: ";
            cin >> vehicleID;

            // Search Vehicle
            for (int i = 0; i < 10; i++)
            {
                if (vehicles[i]->getID() == vehicleID)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                cout << "Invalid Vehicle ID!" << endl;
            }

            else if (vehicles[index]->isAvailable())
            {
                cout << "This vehicle is not currently rented!" << endl;
            }

            else
            {
                vehicles[index]->setAvailable(true);

                cout << "Vehicle returned successfully!" << endl;
            }
        }

        // Exit
        else if (choice == 4)
        {
            cout << "\nThank you for using our system!" << endl;
        }

        else
        {
            cout << "\nInvalid choice! Try again." << endl;
        }

    } while (choice != 4);

    // Free Dynamic Memory
    for (int i = 0; i < 10; i++)
    {
        delete vehicles[i];
    }

    return 0;
}
