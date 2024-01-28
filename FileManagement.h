#ifndef FILEMANAGEMENT
#define FILEMANAGEMENT
#include "Basics.h"
const string CruisePath = "Cruise/";
const string UserPath = "Users/";
namespace fs = filesystem;
using namespace fs;

class FileManager
{
public:
    vector<int> getCruiseIds()
    {
        vector<int> res;
        if (!exists(CruisePath) || !is_directory(CruisePath))
        {
            cerr << "Error: Folder does not exist or is not a directory." << endl;
            return res;
        }
        for (const auto &entry : directory_iterator(CruisePath))
        {
            // Check if it is a regular file
            if (entry.is_regular_file())
            {
                string file_path = entry.path().filename().string();
                file_path = file_path.substr(0, file_path.size() - 4);
                // Open the file
                ifstream file(file_path);
                res.push_back(stoi(file_path));
            }
        }
        return res;
    }
    vector<int> getUserIds()
    {
        vector<int> res;
        if (!exists(UserPath) || !is_directory(UserPath))
        {
            cerr << "Error: Folder does not exist or is not a directory." << endl;
            return res;
        }
        for (const auto &entry : directory_iterator(UserPath))
        {
            // Check if it is a regular file
            if (entry.is_regular_file())
            {
                string file_path = entry.path().filename().string();
                file_path = file_path.substr(0, file_path.size() - 4);
                // Open the file
                ifstream file(file_path);
                res.push_back(stoi(file_path));
            }
        }
        return res;
    }
    Cruise getCruiseDetails(int id)
    {
        Cruise dummyRes;
        string targetFile = CruisePath;
        targetFile += to_string(id);
        targetFile += ".txt";
        if (!exists(CruisePath) || !is_directory(CruisePath))
        {
            cerr << "No such cruise exists!" << endl;
            return dummyRes;
        }
        // top
        ifstream file(targetFile);
        if (!file.is_open())
        {
            cerr << "Error opening the file." << std::endl;
            return dummyRes;
        }
        string line;
        vector<string> lines;
        while (getline(file, line))
        {
            // Process each line as a string
            lines.push_back(line);
        }
        file.close();
        string from;
        string to;
        string depTime;
        string arrTime;
        id = stoi(lines[0]);
        from = lines[1];
        depTime = lines[2];
        to = lines[3];
        arrTime = lines[4];
        dummyRes = Cruise(id, from, depTime, to, arrTime);
        istringstream iss(lines[5]);
        vector<int> BusinessClass;
        vector<int> EconomicClass;
        vector<int> seatingPlace;
        vector<bool> totalAllocation;
        string word;
        // Read each word from the stringstream
        while (iss >> word)
        {
            BusinessClass.push_back(stoi(word));
        }
        iss.str(lines[6]);
        iss.clear();
        while (iss >> word)
        {
            EconomicClass.push_back(stoi(word));
        }
        iss.str(lines[7]);
        iss.clear();
        while (iss >> word)
        {
            seatingPlace.push_back(stoi(word));
        }
        iss.str(lines[8]);
        iss.clear();
        while (iss >> word)
        {
            if (word[0] == 'T')
            {
                totalAllocation.push_back(true);
            }
            else
            {
                totalAllocation.push_back(false);
            }
        }
        Accomodations accom(BusinessClass, EconomicClass, seatingPlace, totalAllocation);
        dummyRes.setAccomodations(accom);
        WaitingList w;
        if (lines[9][0] != '0')
        {
            iss.str(lines[9]);
            iss.clear();
            bool flag = false;
            while (iss >> word)
            {
                if (!flag)
                {
                    flag = true;
                }
                else
                {
                    w.addBusinessWaitingList(stoi(word));
                }
            }
        }
        if (lines[10][0] != '0')
        {
            iss.str(lines[10]);
            iss.clear();
            bool flag = false;
            while (iss >> word)
            {
                if (!flag)
                {
                    flag = true;
                }
                else
                {
                    w.addEconomicWaitingList(stoi(word));
                }
            }
        }
        dummyRes.setWaitingList(w);
        return dummyRes;
    }
    // getUserDetails(int id)
    User getUserDetails(int id)
    {
        User result;
        string targetFile = UserPath;
        targetFile += to_string(id);
        targetFile += ".txt";
        if (!exists(CruisePath) || !is_directory(CruisePath))
        {
            cerr << "User does not exist!" << endl;
            return result;
        }
        // top
        ifstream file(targetFile);
        if (!file.is_open())
        {
            cerr << "Error opening the file." << std::endl;
            return result;
        }
        string line;
        vector<string> lines;
        while (getline(file, line))
        {
            // Process each line as a string
            lines.push_back(line);
        }
        file.close();
        string name = lines[0];
        int cruiseId = stoi(lines[1]);
        char category = lines[2][0];
        result = User(id, name, cruiseId, category);
        return result;
    }
    // updateuserDetails()
    void updateCruiseDetails(Cruise cur)
    {
        // Specify the file name
        const string filename = CruisePath + to_string(cur.getCruiseId()) + ".txt";
        // Open the file for writing
        ofstream outputFile(filename);
        // Check if the file is opened successfully
        if (!outputFile.is_open())
        {
            cerr << "Cruise is not found!" << endl;
            return;
        }
        // Write content to the file
        outputFile << cur.getCruiseId()<<endl;
        outputFile << cur.getDeptCity()<<endl;
        outputFile << cur.getDeptTime()<<endl;
        outputFile << cur.getArrivalCity()<<endl;
        outputFile << cur.getArrivalTime()<<endl;
        vector<int> BusinessClass = cur.getBusinessClassDetails();
        vector<int> EconomicClass = cur.getEconomicClassDetails();
        vector<int> seatingPlaces = cur.getSeatingAllocation();
        vector<bool> totalSeatsAllocation = cur.getTotalSeatsAllocation();
        for(int i: BusinessClass){
            outputFile<<i<<" ";
        }
        outputFile<<endl;
        for(int i: EconomicClass){
            outputFile<<i<<" ";
        }
        outputFile<<endl;
        for(int i: seatingPlaces){
            outputFile<<i<<" ";
        }
        outputFile<<endl;
        for(bool i: totalSeatsAllocation){
            if(i){
                outputFile<<"T"<<" ";
            }
            else{
                outputFile<<"F"<<" ";
            }
        }
        outputFile<<endl;
        outputFile<<cur.totalBusinessClassWaitingList()<<endl;
        outputFile<<cur.totalEconomicClassWaitingList();
        // TODO
        /**
         * Get the vectors from the class and modify it and upload it --Done
        */
        // Close the file
        outputFile.close();
        // cout << " user created successfully." << endl;

    }
    void cancelPassengerSchedule(int passengerId, int cruiseId){
        User cur = getUserDetails(passengerId);
        if(!cur.isUserValid()){
            cout<<"The provided user does not exist!"<<endl;
            linePrinter();
            return;
        }
        if(cur.getCruiseId() != cruiseId){
            if(cur.getCruiseId() == -1){
                cout<<"The passenger has no active cruise travels schedulded!"<<endl;
            }else{
                cout<<"The passenger has been schedulded in a different cruise ship! Operation cancelled!"<<endl;
            }
            linePrinter();
            return;
        }
        Cruise cruse = getCruiseDetails(cruiseId);
        int passengerSeat = cruse.getPassengerSeatNumber(passengerId);
        cruse.cancelSeatSchedule(passengerSeat);
        cur.setCruiseId(-1);
        cur.setClass('N');
        updateCruiseDetails(cruse);
        updatePassengerDetails(passengerId, cur);
        cout<<"Passenger schedule cancelled!"<<endl;
        linePrinter();
        
    }
    void updatePassengerDetails(int id, User cur){
        const string filename = UserPath + to_string(id) + ".txt";
        // Open the file for writing
        cout<<"Am i? "<<filename<<endl;
        ofstream outputFile(filename);
        // Check if the file is opened successfully
        if (!outputFile.is_open())
        {
            cerr << "Error opening the file." << endl;
            return;
        }
        // Write content to the file
        outputFile<<cur.getUserName()<<endl;
        outputFile<<cur.getCruiseId()<<endl;
        switch(cur.getSeatingClass()){
            case SeatingClass::BUSINESS:
                outputFile<<"B";
                break;
            case SeatingClass::ECONOMIC:
                outputFile<<"E";
            case SeatingClass::IDLE:
                outputFile<<"N";
        }
        
    }
    // createUser()
    void createUser(int id, string name)
    {
        // Specify the file name
        const string filename = UserPath + to_string(id) + ".txt";
        // Open the file for writing
        ofstream outputFile(filename);
        // Check if the file is opened successfully
        if (!outputFile.is_open())
        {
            cerr << "Error opening the file." << endl;
            return;
        }
        // Write content to the file
        outputFile << name << endl;
        outputFile << -1<<endl<<"N";
        // Close the file
        outputFile.close();
        cout << "New user created successfully." << endl;
    }
    void createUser(int id, string name, int cruiseId)
    {
        // Specify the file name
        const string filename = UserPath + to_string(id);
        // Open the file for writing
        ofstream outputFile(filename);
        // Check if the file is opened successfully
        if (!outputFile.is_open())
        {
            cerr << "Error opening the file." << endl;
            return;
        }
        // Write content to the file
        outputFile << name;
        outputFile << cruiseId;
        // Close the file
        outputFile.close();
        cout << "New user created successfully." << endl;
    }
    void showDetailsOfPassenger(int id){
        User user = getUserDetails(id);
        if(!user.isUserValid()){
            cout<<"User with given user id, does not exist!"<<endl;
            linePrinter();
            return;
        }
        Cruise cruise = getCruiseDetails(user.getCruiseId());
        linePrinter();
        cout<<"User Details:\nUser Name:"<<user.getUserName()<<endl;
        if(user.getCruiseId() == -1){
            cout<<"User have not schedulded a travel with Cruise!"<<endl;
            return;
        }
        cout<<"User Has Schedulded a cruise with cruise id: "<<user.getCruiseId()<<endl;
        cout<<"User's Seat Number: "<<cruise.getPassengerSeatNumber(id)<<endl;
        bool isEconomic = cruise.getEconomicSeatingStarting() <= cruise.getPassengerSeatNumber(id);
        cout<<"User's seating class: "<<((isEconomic)?"Economic":"Business")<<endl;
        cout<<"Seat Position:"<<endl<<endl;
        // vector<bool> seatArrangements = cruise.getTotalSeatsAllocation();
        vector<int> seatArrangements = cruise.getSeatingAllocation();
        int start = (isEconomic)?(cruise.getEconomicSeatingStarting()+1):1;
        int end = (isEconomic)?(seatArrangements.size()):(cruise.getEconomicSeatingStarting());
        for(int i=start;i<=end;i++){
            cout<<" "<<(i);
        }
        cout<<endl;
        for(int i=start;i<=end;i++){
            cout<<"+-";
        }
        cout<<"+"<<endl;
        for(int i=start;i<=end;i++){
            cout<<"|"<<((seatArrangements[i-1] == id)?"X":"-");
        }
        cout<<"|"<<endl;
        for(int i=start;i<=end;i++){
            cout<<"+-";
        }
        cout<<"+"<<endl;
    }
};
#endif