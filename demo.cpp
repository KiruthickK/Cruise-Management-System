#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

int main() {
    std::string folder_path = "Cruise/";

    // Check if the folder exists
    if (!fs::exists(folder_path) || !fs::is_directory(folder_path)) {
        std::cerr << "Error: Folder does not exist or is not a directory." << std::endl;
        return 1;
    }

    // Iterate through the files in the folder
    for (const auto& entry : fs::directory_iterator(folder_path)) {
        // Check if it is a regular file
        if (entry.is_regular_file()) {
            std::string file_path = entry.path().string();

            // Open the file
            std::ifstream file(file_path);
            
            // Check if the file is opened successfully
            if (file.is_open()) {
                std::cout << "Reading file: " << file_path << std::endl;

                // Read the content of the file
                std::string line;
                while (std::getline(file, line)) {
                    // Process each line as needed
                    std::cout << line << std::endl;
                }

                // Close the file
                file.close();
            } else {
                std::cerr << "Error: Unable to open file " << file_path << std::endl;
            }
        }
    }

    return 0;
}
