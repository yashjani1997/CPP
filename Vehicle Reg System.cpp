#include<iostream>
#include<string>
using namespace std;

class Vehicle 
{
private:
    int vehiId;                   
    string manufacturer;
    string model;
    int year;
    static int tVehicle;      

public:
    Vehicle(int vID, string manu, string mod, int yr):
        vehiId(vID), manufacturer(manu), model(mod), year(yr)
    {
        tVehicle++;
    }

    ~Vehicle() 
    {
        tVehicle--;
    }

    static int getTotalVehicle() 
    {
        return tVehicle;
    }

    void getVdetails() 
    {
        cout<<"Vehicle ID: "<<vehiId<<endl;
        cout<<"Manufacturer: "<<manufacturer<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Year: "<<year<<endl;
    }

    void setVdetails(int vID, string manu, string mod, int yr) 
    {
        vehiId=vID;
        manufacturer=manu;
        model=mod;
        year=yr;
    }

    int getVid() 
    {
        return vehiId;
    }
};

int Vehicle::tVehicle=0;  

class Car : public Vehicle 
{
private:
    string fueltype;

public:
    Car(int vID, string manu, string mod, int yr, string fuel)
        : Vehicle(vID, manu, mod, yr), fueltype(fuel) {}

    void getVdetails() 
    {
        Vehicle::getVdetails();
        cout<<"Fuel type: "<<fueltype<<endl;
    }

    void setVdetails(int vID, string manu, string mod, int yr, string fuel) 
    {
        Vehicle::setVdetails(vID, manu, mod, yr);
        fueltype=fuel;
    }
};

class ElectricCar : public Car 
{
private:
    int batteryCap;

public:
    ElectricCar(int vID, string manu, string mod, int yr, string fuel, int battery)
        : Car(vID, manu, mod, yr, fuel), batteryCap(battery) {}

    void getVdetails() 
    {
        Car::getVdetails();
        cout<<"Battery Capacity: "<<batteryCap<<" KWH"<<endl;
    }

    void setVdetails(int vID, string manu, string mod, int yr, string fuel, int battery) 
    {
        Car::setVdetails(vID, manu, mod, yr, fuel);
        batteryCap=battery;
    }
};

class Aircraft 
{
private:
    int flightRange;

public:
    Aircraft(int range):flightRange(range) {}

    void getAdetails()
    {
        cout<<"Flight Range: "<<flightRange<<" miles"<<endl;
    }

    void setAdetails(int range) 
    {
        flightRange=range;
    }
};

class FlyingCar : public Car, public Aircraft 
{
private:
    int batteryCap;

public:
    FlyingCar(int vID, string manu, string mod, int yr, string fuel, int battery, int range)
        : Car(vID, manu, mod, yr, fuel), Aircraft(range), batteryCap(battery) {}

    void getVdetails() 
    {
        Car::getVdetails();
        Aircraft::getAdetails();
        cout<<"Battery Capacity: "<<batteryCap<<" KWH"<<endl;
    }

    void setVdetails(int vID, string manu, string mod, int yr, string fuel, int battery, int range)
    {
        Car::setVdetails(vID, manu, mod, yr, fuel);
        Aircraft::setAdetails(range);
        batteryCap=battery;
    }
};

class SportsCar : public ElectricCar 
{
private:
    int topSpeed;

public:
    SportsCar(int vID, string manu, string mod, int yr, string fuel, int battery, int speed):
        ElectricCar(vID, manu, mod, yr, fuel, battery), topSpeed(speed) {}

    void getVdetails() 
    {
        ElectricCar::getVdetails();
        cout<<"Top Speed: "<<topSpeed<<" MPH"<< endl;
    }

    void setVdetails(int vID, string manu, string mod, int yr, string fuel, int battery, int speed) 
    {
        ElectricCar::setVdetails(vID, manu, mod, yr, fuel, battery);
        topSpeed=speed;
    }
};

class Sedan : public Car 
{
public:
    Sedan(int vID, string manu, string mod, int yr, string fuel)
        : Car(vID, manu, mod, yr, fuel) {}

    void getVdetails() 
    {
        Car::getVdetails();
        cout <<"This is a Sedan."<<endl;
    }

    void setVdetails(int vID, string manu, string mod, int yr, string fuel) 
    {
        Car::setVdetails(vID, manu, mod, yr, fuel);
    }
};

class SUV : public Car 
{
public:
    SUV(int vID, string manu, string mod, int yr, string fuel)
        : Car(vID, manu, mod, yr, fuel) {}

    void getVdetails() 
    {
        Car::getVdetails();
        cout<<"This is an SUV."<<endl;
    }

    void setVdetails(int vID, string manu, string mod, int yr, string fuel) 
    {
        Car::setVdetails(vID, manu, mod, yr, fuel);
    }
};

class VehicleReg 
{
private:
    Vehicle* vehicles[100];
    int tVehicle;

public:
    VehicleReg():tVehicle(0) {}

    void addVehicle(Vehicle* vehicle) 
    {
        if (tVehicle < 100) 
        {
            vehicles[tVehicle++]=vehicle;
        }
    }

    void displayV() 
    {
        for (int i=0;i<tVehicle;i++) 
        {
            vehicles[i]->getVdetails();
            cout<<endl;
        }
    }

    Vehicle* searchById(int id) 
    {
        for (int i=0;i<tVehicle;i++) 
        {
            if(vehicles[i]->getVid()==id) 
            {
                return vehicles[i];
            }
        }
        return nullptr;
    }

    int getTotalv() 
    {
        return tVehicle;
    }
};

int main() 
{
    VehicleReg reg;
    int choice;

    while(true) 
    {
        cout<<"Vehicle Register Menu:" << endl;
        cout<<"1. Add a Vehicle" << endl;
        cout<<"2. View all Vehicles" << endl;
        cout<<"3. Search Vehicle by ID" << endl;
        cout<<"4. Exit" << endl;
        cout<<"Enter Your Choice: ";
        cin>>choice;

        if(choice==1) 
        {
            int type;
            cout<<"Enter Vehicle type (1-Car, 2-ElectricCar, 3-FlyingCar, 4-SportsCar, 5-Sedan, 6-SUV): ";
            cin>>type;

            int vehiId, year;
            string manufacturer, model, fuel;
            cout<<"Enter Vehicle Details(ID, manufacturer, Model, Year, Fuel type): ";
            cin>>vehiId>>manufacturer>>model>>year>>fuel;

            if(type==1) 
            {
                reg.addVehicle(new Car(vehiId, manufacturer, model, year, fuel));
            } 
            else if(type==2) 
            {
                int batteryCap;
                cout<<"Enter Battery Capacity: ";
                cin>>batteryCap;
                reg.addVehicle(new ElectricCar(vehiId, manufacturer, model, year, fuel, batteryCap));
            } 
            else if(type==3) 
            {
                int batteryCap, flightRange;
                cout<<"Enter battery Capacity and flight range: ";
                cin>>batteryCap>>flightRange;
                reg.addVehicle(new FlyingCar(vehiId, manufacturer, model, year, fuel, batteryCap, flightRange));
            }
            else if(type==4) 
            {
                int topSpeed, batteryCap;
                cout<<"Enter topSpeed and battery Capacity: ";
                cin>>topSpeed>>batteryCap;
                reg.addVehicle(new SportsCar(vehiId, manufacturer, model, year, fuel, batteryCap, topSpeed));
            } 
            else if(type==5) 
            {
                reg.addVehicle(new Sedan(vehiId, manufacturer, model, year, fuel));
            }
            else if(type==6)
            {
                reg.addVehicle(new SUV(vehiId, manufacturer, model, year, fuel));
            }
        } 
        else if(choice==2)
        {
            reg.displayV();
        }
        else if(choice==3)
        {
            int id;
            cout<<"Enter Vehicle ID to Search: ";
            cin>>id;
            Vehicle* v=reg.searchById(id);
            if(v) 
            {
                v->getVdetails();
            }
            else
            {
                cout<<"Vehicle not found."<<endl;
            }
        } 
        else if(choice==4)
        {
            cout<<"Exiting Program."<<endl;
            break;
        } 
        else 
        {
            cout<<"Invalid Choice.Please try again."<<endl;
        }
    }
    return 0;
}
