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
        bool isValidUser = false;
    public:
        User(int userId, string name, int cruiseId, TicketStatus status){
            this->userId = userId;
            this->name = name;
            this->cruiseId = cruiseId;
            this->seatNumber = seatNumber;
            this->status = status;
            isValidUser = true;
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
            isValidUser = true;
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
        bool isUserValid(){return isValidUser;}
        void setCruiseId(int id){
            this->cruiseId = -1;
        }
        void display(){
            cout<<endl;
            cout<<"NAme:<<"<<name<<endl<<endl<<endl;
        }
        bool isUserHasFreeFromPreviousScheduleOnCruises(){return cruiseId == -1;}
        int getCruiseId(){return cruiseId;}

};