#include <iostream>
#include <filesystem>
#include <algorithm>
#include <fstream>
#include <string>
#include <unistd.h>

#include "template_genorator.h"
#include "color.hpp"

#define VERSION "0.5.8"

void genorate()
{
    std::cout << color(Blue) << "?" << color(Defult) << " Project Name >> ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << color(Gray) << "Options [exe, dll]" << color(Defult) << std::endl;
    std::cout << color(Blue) << "?" << color(Defult) << " Project Type >> ";
    std::string result;
    std::getline(std::cin, result);

    int type = result == "exe" ? 0 : 1;

    std::cout << color(Gray) << "Options [make, cpb]" << color(Defult) << std::endl;
    std::cout << color(Blue) << "?" << color(Defult) << " Project Build Type >> ";
    std::string build;
    std::getline(std::cin, build);

    int bType = build == "make" ? 0 : 1;

    std::cout << color(Gray) << "Options [89, 03, 11, 14, 17, 20]" << color(Defult) << std::endl;
    std::cout << color(Blue) << "?" << color(Defult) << " Project C++ Version >> ";
    std::string version;
    std::getline(std::cin, version);

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
    while ((opt = getopt(argc, argv, "vg")) != -1)
    {
        switch (opt)
        {
            case 'v':
                std::cout << VERSION << std::endl;
                break;
            case 'g':
                genorate();
                break;
            default:
                std::cerr << color(Red) << "Unknown option" << color(Defult) << std::endl;
                return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}