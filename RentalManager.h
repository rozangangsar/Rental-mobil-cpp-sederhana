#ifndef RENTALMANAGER_H
#define RENTALMANAGER_H

#include "Car.h"
#include "Renter.h"
#include <vector>
#include <string>
using namespace std;

class RentalManager {
private:
    vector<Car> cars;
    vector<Renter> renters;

public:
    // Constructor
    RentalManager();

    // Car management
    void addCar(string id, string model, string type, long rate);
    void editCar(string carID, string model, string type, long rate);
    void deleteCar(string carID);
    void viewAllCars();
    void viewAvailableCars();
    Car* findCar(string carID);

    // Renter management
    void addRenter(string id, string name, string phone, string address);
    void editRenter(string renterID, string name, string phone, string address);
    void deleteRenter(string renterID);
    void viewAllRenters();
    Renter* findRenter(string renterID);

    // Rental transaction
    void rentCar(string renterID, string carID, int days, long dailyRate);
    void returnCar(string carID);
    void viewRentalHistory();

    // Search and filter
    void searchCarByType(string type);
    void checkCarAvailability(string carID);

    // File I/O
    void loadFromFile(string filename);
    void saveToFile(string filename);

};

#endif
