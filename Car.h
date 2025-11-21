#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car {
private:
    string carID;
    string carModel;
    string carType;        // SUV, Sedan, MPV, Truck
    long dailyRate;        // Tarif harian
    bool available;        // Status ketersediaan
    string currentRenter;  // Nama penyewa saat ini

public:
    // Constructor
    Car();
    Car(string id, string model, string type, long rate);

    // Setter methods
    void setCarID(string id);
    void setCarModel(string model);
    void setCarType(string type);
    void setDailyRate(long rate);
    void setAvailable(bool status);
    void setCurrentRenter(string renter);

    // Getter methods
    string getCarID();
    string getCarModel();
    string getCarType();
    long getDailyRate();
    bool getAvailable();
    string getCurrentRenter();

    // Other methods
    void printCarInfo();
    void printCarStatus();

};

#endif
