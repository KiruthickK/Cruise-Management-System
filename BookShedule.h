#include "FileManagement.h"
#include "Cruise.h"
#include "Basics.h"

void bookShedule(FileManager m){
    int id;
    CaseOfEnterUserIdAgain:
    cout<<"Enter the passenger id:";
    cin>>id;
    string name;
    vector<int> users = m.getUserIds();
    vector<int> cruises = m.getCruiseIds();
    for(int user: users){
        if(user == id){
            User user = m.getUserDetails(id);
            CaseWhenCruiseIdIsWrong:
            cout<<"Enter the Cruise(id) you want to shedule:";
            cin>>id;
            for(int cruise: cruises){
                if(cruise == id){
                    Cruise cur = m.getCruiseDetails(cruise);
                    if(user.isUserHasFreeFromPreviousScheduleOnCruises()){
                        cout<<"Please enter an available seat to book your schedule"<<endl;
                        cur.displayAvailableSeats();
                    }else{
                        cout<<"Sorry this user has active schedule on a Cruise!\nCruise Details:"<<endl;
                        Cruise userBookedCruise = m.getCruiseDetails(user.getCruiseId());
                        userBookedCruise.display();
                    }
                    return;
                }
            }
            cout<<"You may have entered a wrong cruise id, if you want to retry enter 1\nFor exit enter any other number than 1\n";
            id = -1;
            cin>>id;
            if(id == 1){
                goto CaseWhenCruiseIdIsWrong;
            }
            return;
        }
    }
    CaseOfWrongOption:
    cout<<"No previous users found with the id ( "<<id<<" )"<<endl;
    cout<<"Creating new user\nEnter 1 for proceed and create new user\nEnter 2 for try again with existing user id\nEnter 3 for cancel the operation\nYour choice:";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            break;
        case 2:
            goto CaseOfEnterUserIdAgain;
        case 3:
            return;
        default:
            cout<<"Enter a valid choice!"<<endl;
            goto CaseOfWrongOption;

    }
    cout<<"Enter your username: ";
    cin>>name;
    m.createUser(id, name);
    CaseWhenCruiseIdIsWrong2:
    cout<<"Enter the Cruise Id:";
    cin>>id;
    for(int cruise: cruises){
        if(id == cruise){
            Cruise cur = m.getCruiseDetails(cruise);
            return;
        }
    }
    cout<<"Cruise with Entered Cruise Id not found! Please try again!"<<endl;
    goto CaseWhenCruiseIdIsWrong2;

}
