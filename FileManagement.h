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
    vector<string> getCruiseIds()
    {
        vector<string> res;
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
                res.push_back(file_path);
            }
        }
        return res;
    }
    vector<string> getUserIds()
    {
        vector<string> res;
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
                res.push_back(file_path);
            }
        }
        return res;
    }
};
#endif