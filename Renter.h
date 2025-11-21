#ifndef RENTER_H
#define RENTER_H

#include <string>
using namespace std;

class Renter {
private:
    string renterID;
    string renterName;
    string phoneNumber;
    string address;
    string rentalCar;      // ID mobil yang disewa
    int rentalDays;        // Jumlah hari sewa
    long totalCost;        // Total biaya

public:
    // Constructor
    Renter();
    Renter(string id, string name, string phone, string addr);

    // Setter methods
    void setRenterID(string id);
    void setRenterName(string name);
    void setPhoneNumber(string phone);
    void setAddress(string addr);
    void setRentalCar(string carID);
    void setRentalDays(int days);
    void setTotalCost(long cost);

    // Getter methods
    string getRenterID();
    string getRenterName();
    string getPhoneNumber();
    string getAddress();
    string getRentalCar();
    int getRentalDays();
    long getTotalCost();

    // Other methods
    void printRenterInfo();
    void printRentalDetails();

};

#endif
