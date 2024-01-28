#include "Basics.h"

namespace fs = std::filesystem;

int main() {
    terminalWidth = getTerminalWidth();
    FileManager m;
    linePrinter();
    cout<<"Welcome to Cruise Ticket Booking System!"<<endl;
    linePrinter();
    cout<<"Available Cruise ships are with their ids:"<<endl;
    vector<int> ships = m.getCruiseIds();
    int index = 1;
    for(int ship: ships){
        cout<<(index++)<<". "<<ship<<endl;
    }
    linePrinter();
    while(1){
        cout<<"Enter 1 for Book a ticket and schedule a passenger,\nEnter 2 for cancel a schedule for a passenger,\nEnter 3 for displaying passenger status\nEnter 4 for displaying cruise status\nEnter 5 for show ids of all Cruise ships\nEnter 6 for exit"<<endl;
        linePrinter();
        cout<<"Your choice:";
        int choice;
        cin>>choice;
        linePrinter();
        switch(choice){
            case 1:
                bookShedule(m);
                break;
            case 2:
                cancelSheduleOfPassenger(m);
                break;
            case 3:
                showPassengerStatus(m);
                break;
            case 4:
            {
                cout<<"Enter the cruise id: ";
                int id;
                cin>>id;
                linePrinter();
                Cruise ship = m.getCruiseDetails(id);
                ship.display();
                break;
            }
            case 5:
                cout<<"Available Cruise ships are with their ids:"<<endl;
                for(int ship: ships){
                    cout<<ship<<endl;
                }
                break;
            case 6:
                cout<<"Thank you for using us!"<<endl;
                return 0;
            default:
            cout<<"Enter a correct choice!"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
