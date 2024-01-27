#include "Basics.h"
// #include "FileManagement.h"
class User{
    private:
        int userId;
        string name;
        int cruiseId;
        int seatNumber;
        SeatingClass classType;
        TicketStatus status;
    public:
        User(int userId, string name, int cruiseId, TicketStatus status){
            this->userId = userId;
            this->name = name;
            this->cruiseId = cruiseId;
            this->seatNumber = seatNumber;
            this->status = status;
        }
        User(int userId, string name, int cruiseId, char isBusinessClass){
            this->userId = userId;
            if(isBusinessClass == 'B'){
                this->classType = SeatingClass::BUSINESS;
            }else if(isBusinessClass == 'E'){
                this->classType = SeatingClass::ECONOMIC;
            }else{
                this->classType = SeatingClass::IDLE;
            }
            this->name = name;
            this->cruiseId = cruiseId;
            this->seatNumber = seatNumber;
            this->status = status;
        }
        User(){}
        void bookSeats(int cruiseId, SeatingClass classType){
            this->cruiseId = cruiseId;
            this->classType = classType;
        }
        string getUserName(){return name;}
        int getCruiseNumber(){return cruiseId;}
        SeatingClass getSeatingClass(){ return classType;}
        void setClass(char isBusinessClass){
            if(isBusinessClass == 'B'){
                this->classType = SeatingClass::BUSINESS;
            }else if(isBusinessClass == 'E'){
                this->classType = SeatingClass::ECONOMIC;
            }else{
                this->classType = SeatingClass::IDLE;
            }
        }
        void setCruiseId(int id){
            this->cruiseId = -1;
        }

        bool isUserHasFreeFromPreviousScheduleOnCruises(){return cruiseId == -1;}
        int getCruiseId(){return cruiseId;}

};