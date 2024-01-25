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
        int totalBusinessClassWaitingList(){return BusinessPassengers.size();}
        int totalEconomicClassWaitingList(){return EconomicPassengers.size();}
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
        bool isPassengerInWaitingList(int id, bool isBusinessClass){
            stack<int> temp;
            bool res = false;
            if(isBusinessClass){
                while(!BusinessPassengers.empty()){
                    if(id == BusinessPassengers.front()) res = true;
                    temp.push(BusinessPassengers.front());
                    BusinessPassengers.pop();
                }
                while(!temp.empty()){
                    BusinessPassengers.push(temp.top());
                    temp.pop();
                }

            }else{
                while(!EconomicPassengers.empty()){
                    if(id == EconomicPassengers.front()) res = true;
                    temp.push(BusinessPassengers.front());
                    EconomicPassengers.pop();
                }
                while(!temp.empty()){
                    EconomicPassengers.push(temp.top());
                    temp.pop();
                }
            }
            return res;
        }
        void display(){
            cout<<"Waiting list details:"<<EconomicPassengers.size()<<" -> eco waiting and "<<BusinessPassengers.size()<<" -> busi waiting"<<endl;
        }
};
#endif