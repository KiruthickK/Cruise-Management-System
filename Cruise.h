#ifndef CRUISEDECLARATION
#define CRUISEDECLARATION
#include "Basics.h"

class Cruise{
    int id;
    string deptCity;
    string deptTime;
    string arrivalCity;
    string arrivalTime;
    Accomodations accomodations; 
    WaitingList waitingList; 
    bool isValid;
    public:
        Cruise(){isValid = false;}
        Cruise(int id, string deptCity, string deptTime, string arrivalCity, string arrivalTime){
            isValid = true;
            this->id = id;
            this->deptCity = deptCity;
            this->deptTime = deptTime;
            this->arrivalCity = arrivalCity;
            this->arrivalTime = arrivalTime;
        }
        void cancelSeatSchedule(int seatNumber){
            accomodations.cancelSeatSchedule(seatNumber);
        }
        void setAccomodations(Accomodations accom){
            this->accomodations = Accomodations(accom);
        }
        void setWaitingList(WaitingList waitingList){
            this->waitingList = WaitingList(waitingList);
        }
        int getPassengerSeatNumber(int passengerId){
            return accomodations.getPassengerSeatNumber(passengerId);
        }
        bool isThisCruiseAvailable(){return isValid;}
        void display(){
            if(!isValid){
                cout<<"The provided id is wrong!"<<endl;
                return;
            }
            cout<<"Cruise details:"<<endl;
            cout<<"id: "<<id<<endl;
            cout<<"deptCity: "<<deptCity<<endl;
            cout<<"deptTime: "<<deptTime<<endl;
            cout<<"arrivalCity: "<<arrivalCity<<endl;
            cout<<"arrivalTime: "<<arrivalTime<<endl;
            this->accomodations.display();
            this->waitingList.display();
        }
        void bookASeat(int seatNum, int userId){
            accomodations.bookSeatForCruise(seatNum, userId);
        }
        void displayAvailableSeats(){
            cout<<"Available seats information on the cruise with id: "<<cuserid<<endl;
            int startOfEconomicClass = accomodations.getStartOfEconomicClass();
            cout<<endl;
            cout<<"Note: A - available, B - Booked"<<endl;
            cout<<endl;
            int index = 0;
            for(bool status: accomodations.getTotalSeatsAllocation()){
                if(index == startOfEconomicClass){
                    cout<<endl<<"Economic Class:"<<endl;
                }
                cout<<"Seat Number: "+to_string(index + 1)<<(status?(" - B"): (" - A"))<<((index == startOfEconomicClass - 1)?". ":",");
                index++;
            }
        }
        int getEconomicSeatingStarting(){return accomodations.getStartOfEconomicClass();};
        bool checkSeatAvailability(int seatNumber){return accomodations.checkSeatAvailability(seatNumber);}
        int getCruiseId(){return id;}
        string getDeptCity(){return deptCity;}
        string getDeptTime(){return deptTime;}
        string getArrivalCity(){return arrivalCity;}
        string getArrivalTime(){return arrivalTime;}
        vector<int> getBusinessClassDetails(){return accomodations.getBusinessClass();}
        vector<int> getEconomicClassDetails(){return accomodations.getEconomicClass();}
        vector<bool> getTotalSeatsAllocation(){return accomodations.getTotalSeatsAllocation();}
        vector<int> getSeatingAllocation(){return accomodations.getSeatingAllocation();}
        int totalBusinessClassWaitingList(){return waitingList.totalBusinessClassWaitingList();}
        int totalEconomicClassWaitingList(){return waitingList.totalEconomicClassWaitingList();}
};
#endif