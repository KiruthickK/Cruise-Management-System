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
        cout<<"Enter 'S' for Book a ticket and schedule a passenger,\nEnter 'C' for cancel a schedule for a passenger,\nEnter 'P' for displaying passenger status\nEnter 'F' for displaying cruise status\nEnter 'A' for show ids of all Cruise ships\nEnter 'E' for exit"<<endl;
        linePrinter();
        cout<<"Your choice:";
        char choice;
        cin>>choice;
        linePrinter();
        switch(choice){
            case 'S':
                bookShedule(m);
                break;
            case 'C':
                cancelSheduleOfPassenger(m);
                break;
            case 'P':
                showPassengerStatus(m);
                break;
            case 'F':
            {
                cout<<"Enter the cruise id: ";
                int id;
                cin>>id;
                linePrinter();
                Cruise ship = m.getCruiseDetails(id);
                ship.display();
                break;
            }
            case 'A':
                linePrinter();
                cout<<"Available Cruise ships are with their ids:"<<endl;
                index = 1;
                for(int ship: ships){
                    cout<<(index++)<<". "<<ship<<endl;
                }
                linePrinter();
                break;
            case 'E':
                cout<<"Thank you for using us!"<<endl;
                linePrinter();
                return 0;
            default:
            cout<<"Enter a correct choice!"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
