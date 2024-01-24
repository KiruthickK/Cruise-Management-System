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
};
#endif