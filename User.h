#include "Basics.h"
// #include "FileManagement.h"
enum class TicketStatus{
    BOOKED,
    IDLE,
    WAITINGLIST
};
class User{
    private:
        int userId;
        string name;
        int cruiseId;
        int seatNumber;
        TicketStatus status;
    public:
        User(int userId, string name, int cruiseId, TicketStatus status){
            this->userId = userId;
            this->name = name;
            this->cruiseId = cruiseId;
            this->seatNumber = seatNumber;
            this->status = status;
        }

};