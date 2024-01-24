#include "FileManagement.h"
#include "Cruise.h"
#include "Basics.h"

void bookShedule(FileManager m){
    int id;
    cout<<"Enter the passenger id:";
    string name;
    vector<int> users = m.getUserIds();
    for(int user: users){
        if(user == id){
                
            return;
        }
    }
    cout<<"Created a new user with id ( "<<id<<" )"<<endl;
    cout<<"Enter the user name:";
}
