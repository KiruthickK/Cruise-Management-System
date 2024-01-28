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
                linePrinter();
                return;
            }
            cout<<"Cruise details:"<<endl;
            cout<<"id\t\t: "<<id<<endl;
            cout<<"Depature city\t: "<<deptCity<<endl;
            cout<<"Depature time\t: "<<deptTime<<endl;
            cout<<"Arrival City\t: "<<arrivalCity<<endl;
            cout<<"Arrival Time\t: "<<arrivalTime<<endl;
            singleLinePrinter();
            this->accomodations.display();
            singleLinePrinter();
            this->waitingList.display();
            linePrinter();
        }
        void bookASeat(int seatNum, int userId){
            accomodations.bookSeatForCruise(seatNum, userId);
        }
        void displayAvailableSeats(){
            linePrinter();
            cout<<"Cruise id: "<<cuserid<<endl;
            int startOfEconomicClass = accomodations.getStartOfEconomicClass();
            cout<<"Business Class Seating Information:"<<endl<<endl;
            cout<<"  1";
            for(int i=1;i<=accomodations.getStartOfEconomicClass();i++){
                if(i == 1)continue;
                cout<<((i<10)?"   ":"  ")<<(i);
            }
            cout<<endl;
            for(int i=1;i<=accomodations.getStartOfEconomicClass();i++){
                cout<<"+-+-";
            }
            cout<<"+"<<endl;
            vector<bool> seatArrangements = accomodations.getTotalSeatsAllocation();
            for(int i=1,j=0;i<=accomodations.getStartOfEconomicClass();i++){
                cout<<"| "<<(seatArrangements[j++]?"B":"-")<<" ";
            }
            cout<<"|"<<endl;
            for(int i=1;i<=accomodations.getStartOfEconomicClass();i++){
                cout<<"+-+-";
            }
            cout<<"+"<<endl;
            linePrinter();
            cout<<endl<<"Economic class seating information:"<<endl<<endl;
            cout<<" "<<(((accomodations.getStartOfEconomicClass()+1)>9)?"":" ")<<(accomodations.getStartOfEconomicClass()+1);
            for(int i=accomodations.getStartOfEconomicClass()+1;i<=seatArrangements.size();i++){
                if(i == accomodations.getStartOfEconomicClass()+1)continue;
                cout<<((i<10)?"   ":"  ")<<(i);
            }
            cout<<endl;
            for(int i=1;i<=accomodations.getStartOfEconomicClass();i++){
                cout<<"+-+-";
            }
            cout<<"+"<<endl;
            for(int i=accomodations.getStartOfEconomicClass();i<seatArrangements.size();i++){
                cout<<"| "<<(seatArrangements[i]?"B":"-")<<" ";
            }
            cout<<"|"<<endl;
            for(int i=1;i<=accomodations.getStartOfEconomicClass();i++){
                cout<<"+-+-";
            }
            cout<<"+"<<endl;
            linePrinter();
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