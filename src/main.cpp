#include <iostream>
#include <filesystem>
#include <algorithm>
#include <fstream>
#include <string>

#include "template_genorator.h"

std::string LOGO = R"(
________/\\\\\\\\\________________________________________/\\\\\\\\\\\\\_______/\\\\\\\\\\\\_
 _____/\\\////////________________________________________\/\\\/////////\\\___/\\\//////////__
  ___/\\\/________________/\\\__________/\\\_______________\/\\\_______\/\\\__/\\\_____________
   __/\\\_________________\/\\\_________\/\\\_______________\/\\\\\\\\\\\\\/__\/\\\____/\\\\\\\_
    _\/\\\______________/\\\\\\\\\\\__/\\\\\\\\\\\___________\/\\\/////////____\/\\\___\/////\\\_
     _\//\\\____________\/////\\\///__\/////\\\///____________\/\\\_____________\/\\\_______\/\\\_
      __\///\\\______________\/\\\_________\/\\\_______________\/\\\_____________\/\\\_______\/\\\_
       ____\////\\\\\\\\\_____\///__________\///________________\/\\\_____________\//\\\\\\\\\\\\/__
        _______\/////////________________________________________\///_______________\////////////____
)";

#define VERSION "0.5.0a"

#ifdef DEBUG
    std::string TITLE = "C++ Project Genrator\nDEBUG: v" + 
    std::string(VERSION) + " " + std::string(__TIME__) + " " + std::string(__DATE__);
#else
    std::string TITLE = "C++ Project Genrator\nRELEASE: v" + 
    std::string(VERSION) + " "  + std::string(__TIME__) + " " + std::string(__DATE__);
#endif

int main(int argc, char *argv[])
{
    std::cout << LOGO << std::endl;
    std::cout << TITLE << std::endl;

    std::cout << "Enter project name" << std::endl;
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Project Types [EXE, DLL]" << std::endl;
    std::string result;
    std::getline(std::cin, result);

    int type = result == "EXE" ? 0 : 1;

    std::cout << "C++ Version [89, 03, 11, 14, 17, 20]" << std::endl;
    std::string version;
    std::getline(std::cin, version);

    int cpp_version = std::stoi(version);

    std::cout << "Making project..." << std::endl;
    MakeProgramFiles(name, type, cpp_version);

    return EXIT_SUCCESS;
}