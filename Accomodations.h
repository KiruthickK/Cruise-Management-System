#ifndef ACCOMODATIONSDECLARATION
#define ACCOMODATIONSDECLARATION
#include "Basics.h"

class Accomodations{
    vector<int> BusinessClass;
    vector<int> EconomicClass;
    vector<int> seatingPlace;
    vector<bool> totalSeatsAllocation;
    public:
        Accomodations(){}
        Accomodations(vector<int> BusinessClass, vector<int> EconomicClass, vector<int> seatingPlace, vector<bool> totalSeatsAllocation){
            this->totalSeatsAllocation = totalSeatsAllocation;
            this->BusinessClass = BusinessClass;
            this->EconomicClass = EconomicClass;
            this->seatingPlace = seatingPlace;
        }
        Accomodations(Accomodations &accom){
            this->totalSeatsAllocation = accom.totalSeatsAllocation;
            this->BusinessClass = accom.BusinessClass;
            this->EconomicClass = accom.EconomicClass;
            this->seatingPlace = accom.seatingPlace;
        }
        void display(){
            cout<<"Business seat details: ";
            for(int i: BusinessClass)cout<<i<<" ";
            cout<<endl;
            cout<<"Economic seat details: ";
            for(int i: EconomicClass)cout<<i<<" ";
            cout<<endl;
            cout<<"seating details: ";
            for(int i: seatingPlace)cout<<i<<" ";
            cout<<endl;
            cout<<"Seat Allocation details: ";
            for(bool i: totalSeatsAllocation)cout<<i<<" ";
            cout<<endl;
        }
};
#endif