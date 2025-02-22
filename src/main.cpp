#include <iostream>
#include <filesystem>
#include <algorithm>
#include <fstream>
#include <string>

#include "template_genorator.h"

#define VERSION "0.5.3"

#ifdef DEBUG
    std::string TITLE = "C++ Project Genrator\nDEBUG: v" + 
    std::string(VERSION) + " " + std::string(__TIME__) + " " + std::string(__DATE__);
#else
    std::string TITLE = "C++ Project Genrator\nRELEASE: v" + 
    std::string(VERSION) + " "  + std::string(__TIME__) + " " + std::string(__DATE__);
#endif

int main(int argc, char *argv[])
{
    std::cout << TITLE << std::endl;

    std::cout << "Enter project name" << std::endl;
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Project Types [EXE, DLL]" << std::endl;
    std::string result;
    std::getline(std::cin, result);

    int type = result == "EXE" ? 0 : 1;

    std::cout << "Project Build Types [make, cpb]" << std::endl;
    std::string build;
    std::getline(std::cin, build);

    int bType = build == "make" ? 0 : 1;

    std::cout << "C++ Version [89, 03, 11, 14, 17, 20]" << std::endl;
    std::string version;
    std::getline(std::cin, version);

    int cpp_version = std::stoi(version);

    std::cout << "Making project..." << std::endl;
    MakeProgramFiles(name, type, bType, cpp_version);
    std::cout << "Project created" << std::endl;

    return EXIT_SUCCESS;
}