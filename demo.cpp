#include <iostream>
#include "Basics.h"
int main() {
        // Specify the file name
        const string filename = "Demm";
        // Open the file for writing
        ofstream outputFile(filename);
        // Check if the file is opened successfully
        if (!outputFile.is_open())
        {
            cerr << "Error opening the file." << endl;
            return 0;
        }
        // Write content to the file
        outputFile << "nangfdyjme";
        outputFile << "cruiseId";
        // Close the file
        outputFile.close();
        cout << "New user created successfully." << endl;
    return 0;
}