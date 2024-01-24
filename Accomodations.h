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
};
#endif