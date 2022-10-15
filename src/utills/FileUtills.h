#pragma once

#include <iostream>
#include <string>
#include <fstream>

namespace FileUtills
{
    void writeFile(std::string filePath, std::string content);
    std::string readFile(std::string filePath);
}

