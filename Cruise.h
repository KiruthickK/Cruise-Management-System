#ifndef CRUISEDECLARATION
#define CRUISEDECLARATION
#include "Basics.h"
#include "Accomodations.h"
#include "WaitingList.h"

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
        void setAccomodations(Accomodations accom){
            this->accomodations = Accomodations(accom);
        }
        void setWaitingList(WaitingList waitingList){
            this->waitingList = WaitingList(waitingList);
        }
        bool isThisCruiseAvailable(){return isValid;}
        void display(){
            cout<<"Cruise details:"<<endl;
            cout<<"id: "<<id<<endl;
            cout<<"deptCity: "<<deptCity<<endl;
            cout<<"deptTime: "<<deptTime<<endl;
            cout<<"arrivalCity: "<<arrivalCity<<endl;
            cout<<"arrivalTime: "<<arrivalTime<<endl;
            this->accomodations.display();
            this->waitingList.display();
        }
};
#endif