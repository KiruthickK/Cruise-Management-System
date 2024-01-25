#ifndef FILEMANAGEMENT
#define FILEMANAGEMENT
#include "Basics.h"
#include "Cruise.h"
#include "User.h"
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
            cerr << "Error: Folder does not exist or is not a directory." << endl;
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
            cerr << "Error: Folder does not exist or is not a directory." << endl;
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
        result = User(id, name, cruiseId);
        return result;
    }
    // updateuserDetails()
    void updateCruiseDetails(Cruise cur)
    {

    }
    void updateSheduleOnCruiseForPassenger(int id){
        
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
    // createCruise()
};
#endif