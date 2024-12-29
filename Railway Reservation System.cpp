#include <iostream>
#include <cstring>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    
    static int trainCount;

public:
    
    Train() 
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
    }

    
    Train(int number,const char* name,const char* src,const char* dest,const char* time) {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    
    ~Train()
    {
        trainCount--;
    }

    
    int getTrainNumber() const
    {
        return trainNumber;
    }
    void setTrainNumber(int number)
    {
        trainNumber = number; 
    }
	
    const char* getTrainName() const 
    {
        return trainName;
    }
    void setTrainName(const char* name) 
    {
        strcpy(trainName, name);
    }

    const char* getSource() const
    {
        return source;
        }
    void setSource(const char* src)
    {
        strcpy(source, src);
    }

    const char* getDestination() const
    {
        return destination; 
    }
    void setDestination(const char* dest)
    { strcpy(destination, dest); }

    const char* getTrainTime() const
    {
        return trainTime;
    }
    void setTrainTime(const char* time)
    {
        strcpy(trainTime, time); 
    }

    static int getTrainCount()
    {
        return trainCount;
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();  
        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);
        cout << "Enter Source: ";
        cin.getline(source, 50);
        cout << "Enter Destination: ";
        cin.getline(destination, 50);
        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails() const {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }
};


int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;  
    
public:
    RailwaySystem()
    {
        totalTrains = 0;
    }
    void addTrain()
    {
    	
        if (totalTrains<100)
        {
            cout<<"Add New Train Recor"<<endl;
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        }
        else
        {
            cout<<"Train Records are full"<<endl;
        }
    }
    
    void displayAllTrains()
    {
        if(totalTrains==0)
        {
            cout<<"No Train Record found"<<endl;
        }
        else
        {
            for(int i=0;i<totalTrains;i++)
            {
                cout<<"Train"<<i+1<<"details"<<endl;
                trains[i].displayTrainDetails();
            }
        }
    }
    void searchTrainByNumber(int number)
    {
        for(int i=0;i<totalTrains;i++)
        {
            if(trains[i].getTrainNumber()==number)
            {
                cout<<"Train found: "<<endl;
                trains[i].displayTrainDetails();
            
                return;
            }
        }
        cout<<"Train Number"<<number<<"Not Found"<<endl;
    }
    
    
};

int main() {
        RailwaySystem railwaySystem;
        int choice;
        int searchNumber;


        railwaySystem.addTrain();
        railwaySystem.addTrain();
        railwaySystem.addTrain();
		railwaySystem.addTrain();

    do {
        cout << "------Railway Reservation System------"<<endl;
        cout << "1. Add New Train"<<endl;
        cout << "2. Display All Trains"<<endl;
        cout << "3. Search Train by Number"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                railwaySystem.addTrain();
                break;
            case 2:
                railwaySystem.displayAllTrains();
                break;
            case 3:
                cout << "Enter Train Number to search: ";
                cin >> searchNumber;
                railwaySystem.searchTrainByNumber(searchNumber);
                break;
            case 4:
                cout << "Exiting program.";
                break;
            default:
                cout << "Invalid choice, please try again."<<endl;
        }
    } while (choice != 4);

    return 0;
}
