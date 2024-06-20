#include "Param.h"

class Vehicle {
private:
    int carID;
    string plate;
    string vehicleType;
public:
    Vehicle(string plate,string vehicleType):carID(vehicleID++),plate(plate),vehicleType(vehicleType) {
        lastPlate = plate;
    }

    int getCarID() {
        return this->carID;
    }

    void setPlate(string newPlate) {
        this->plate = newPlate;
    }
    
    string getPlate() {
        return this->plate;
    }

    void setVehicleType(string vehicleType) {
        this->vehicleType = vehicleType;
    }

    string getVehicleType() {
        return this->vehicleType;
    }
};

class ParkingSpot {
private:
    int spotID;
    bool isOccuped;
    string spotType;
public:
    ParkingSpot(string type) :spotType(type),isOccuped(false),spotID(parkingID++) {}

    int getSpotID() {
        return this->spotID;
    }
    
    void setOccupe(bool newOccupe) {
        this->isOccuped = newOccupe;
    }

    bool getOccupe() {
        return this->isOccuped;
    }

    void setSpotType(string spotType) {
        this->spotType = spotType;
    }
    
    string getSpotType() {
        return this->spotType;
    }
    
};

class ParkingTicket {
protected:
    int ticketID;
    int vehicleID;
    int spotID;
    double hourRate = 100;
    time_t entryTime;
    time_t exitTime;
public:
    ParkingTicket(int carID,int parkingID):ticketID(ticketParkingID++),vehicleID(carID)
        ,spotID(parkingID),entryTime(time(nullptr)){}
    
    int getTicketID() {
        return this->ticketID;
    }
    
    void setEntryTime(time_t newTime) {
        this->entryTime = newTime;
    }

    time_t getEntryTime() {
        return this->entryTime;
    }

    void setExitTime(time_t newTime) {
        this->exitTime = newTime;
    }

    time_t getExitTime() {
        return this->exitTime;
    }

    double calculatePrice() {
        double result = difftime(this->exitTime, this->entryTime);
        result = result*hourRate;
        return result;
    }
};

class ParkingLot {
private:
    vector <ParkingSpot*> spots;
    vector <Vehicle*> vechicles;
    vector <ParkingTicket*> tickets;
public:
    ~ParkingLot()
    {
        for (auto v : vechicles) {
            delete v;
        }

        for (auto s : spots) {
            delete s;
        }

        for (auto t : tickets) {
            delete t;
        }
    }
    
    void addCar(Vehicle* vehicle) {
        vechicles.push_back(vehicle);

        int newSpotID = 0;
        for (auto spot : spots) {
            if (spot->getOccupe()==false) {
                spot->setOccupe(true);
                newSpotID = spot->getSpotID();
                break;
            }
        }
        
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
}