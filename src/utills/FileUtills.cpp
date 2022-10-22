#include <FileUtills.h>

void FileUtills::writeFile(std::string filePath, std::string content)
{
    std::ofstream myFile;

    myFile.open(filePath);
    if (!myFile.is_open())
    {
        std::cout << "failed to write into: " << filePath << "\n";
        // TODO: throw an exeption
        return;
    }

    myFile << content;
}

std::string FileUtills::readFile(std::string filePath)
{

    std::ifstream myFile;
    std::string content = "";

    myFile.open(filePath);

    if (!myFile.is_open())
    {
        std::cout << "failed to read file: " << filePath << "\n";
        // TODO: throw an exeption
        return "";
    }

    myFile >> content;
    return content;
}