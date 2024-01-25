#include <iostream>
#include <fstream>

int main() {
    // Specify the file name
    const std::string filename = "Cruise/output.txt";
    // Open the file for writing
    std::ofstream outputFile(filename);

    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }
    // Write content to the file
    outputFile << "Hello, this is a line of text.\n";
    outputFile << "This is another line of text.\n";
    // Close the file
    outputFile.close();
    std::cout << "File has been written successfully." << std::endl;
    return 0;
}
