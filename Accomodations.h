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
        int getStartOfEconomicClass(){
            return BusinessClass.size();
        }
        int getPassengerSeatNumber(int passengerId){
            int res = -1;
            for(int i=0;i<seatingPlace.size();i++){
                if(seatingPlace[i] == passengerId){
                    return i;
                }
            }
            return res;
        }
        void cancelSeatSchedule(int seatNo){
            seatingPlace[seatNo] = -1;
            totalSeatsAllocation[seatNo] = false;
        }
        void bookSeatForCruise(int seatNumber, int userId){
            seatingPlace[seatNumber-1] = userId;
            totalSeatsAllocation[seatNumber - 1] = true;
        }
        vector<bool> getTotalSeatsAllocation(){return totalSeatsAllocation;}
        vector<int> getBusinessClass(){ return BusinessClass;}
        vector<int> getEconomicClass(){ return EconomicClass;}
        vector<int> getSeatingAllocation(){ return seatingPlace;}
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
        bool checkSeatAvailability(int seatNumber){
            if(seatNumber<1 || seatNumber >= totalSeatsAllocation.size()){
                return false;
            }
            return totalSeatsAllocation[seatNumber - 1];
        }
};
#endif