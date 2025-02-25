#include <iostream>
#include <filesystem>
#include <algorithm>
#include <fstream>
#include <string>
#include <unistd.h>

#include "template_genorator.h"
#include "color.hpp"

#define VERSION "0.7.3"

void genorate()
{
    std::cout << color(Blue) << "?" << color(Defult) << " Project Name >> ";
    std::string name;
    std::getline(std::cin, name);

    if (name.empty())
    {
        std::cout << color(Red) << "Error no name given" << color(Defult) << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << color(Gray) << "Types [exe, dll, lib]" << color(Defult) << std::endl;
    std::cout << color(Blue) << "?" << color(Defult) << " Project Type >> ";
    std::string result;
    std::getline(std::cin, result);

    if (result.empty())
    {
        std::cout << color(Red) << "Error no type given" << color(Defult) << std::endl;
        exit(EXIT_FAILURE);
    }

    int type;

    if (result == "exe")
        type = 0;
    else if (result == "dll")
        type = 1;
    else    
        type = 2;
    
    std::cout << color(Gray) << "Build systems [make, cpb]" << color(Defult) << std::endl;
    std::cout << color(Blue) << "?" << color(Defult) << " Project Build Type >> ";
    std::string build;
    std::getline(std::cin, build);

    if (build.empty())
    {
        std::cout << color(Red) << "Error no build type given" << color(Defult) << std::endl;
        exit(EXIT_FAILURE);
    }

    int bType = build == "make" ? 0 : 1;

    std::cout << color(Gray) << "Options [89, 03, 11, 14, 17, 20]" << color(Defult) << std::endl;
    std::cout << color(Blue) << "?" << color(Defult) << " Project C++ Version >> ";
    std::string version;
    std::getline(std::cin, version);

    if (version.empty())
    {
        std::cout << color(Red) << "Error no version given" << color(Defult) << std::endl;
        exit(EXIT_FAILURE);
    }

    int cpp_version = std::stoi(version);

    MakeProgramFiles(name, type, bType, cpp_version);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << color(Red) << "No options slected" << color(Defult) << std::endl;
        return EXIT_FAILURE;
    }

    int opt;
    while ((opt = getopt(argc, argv, "vgh")) != -1)
    {
        switch (opt)
        {
            case 'h':
                std::cout << " -v for version \n -g to make project \n -h for help" << std::endl;
                break;
            case 'v':
                std::cout << VERSION << std::endl;
                break;
            case 'g':
                genorate();
                break;
            default:
                std::cerr << color(Red) << "Unknown option. Try -h" << color(Defult) << std::endl;
                return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}