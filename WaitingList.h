#ifndef WAITINGLISTDECLARATION
#define WAITINGLISTDECLARATION
#include "Basics.h"

class WaitingList{
    private:
        queue<int> BusinessPassengers;
        queue<int> EconomicPassengers;

    public:
        WaitingList(){}
        WaitingList(WaitingList &list){
            this->BusinessPassengers = BusinessPassengers;
            this->EconomicPassengers = EconomicPassengers;
        }
        void addBusinessWaitingList(int passengerId){
            BusinessPassengers.push(passengerId);
        }
        void addEconomicWaitingList(int passengerId){
            EconomicPassengers.push(passengerId);
        }
        int getFirstWaitingPassengerBusinessClass(){
            int res = BusinessPassengers.front();
            BusinessPassengers.pop();
            return res;
        }
        int getFirstWaitingPassengerEconomicClass(){
            int res = EconomicPassengers.front();
            EconomicPassengers.pop();
            return res;
        }
        void display(){
            cout<<"Waiting list details:"<<EconomicPassengers.size()<<" -> eco waiting and "<<BusinessPassengers.size()<<" -> busi waiting"<<endl;
        }
};
#endif