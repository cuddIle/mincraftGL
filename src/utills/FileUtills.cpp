#include <FileUtills.h>

void FileUtills::writeFile(std::string filePath, std::string content) {
    std::ofstream file(filePath);
    file << content;
}

std::string FileUtills::readFile(std::string filePath) {

    std::ifstream myfile; 
    std::string content = "";
    
    myfile.open(filePath);

    if (!myfile.is_open()) {
        std::cout << "failed to open file: " << filePath << "\n";
        // TODO: throw an exeption
        return "";
    }
        
    myfile >> content; 
    return content;
}