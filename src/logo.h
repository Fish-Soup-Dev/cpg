#define LOGO_H
#ifdef LOGO_H

#define VERSION "0.4.0"

#include <string>

namespace CPPG
{
    std::string logo = R"(
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

    #ifdef DEBUG
        std::string title = "C++ Project Genrator\nDEBUG: v" + 
        std::string(VERSION) + " " + std::string(__TIME__) + " " + std::string(__DATE__);
    #else
        std::string title = "C++ Project Genrator\nRELEASE: v" + 
        std::string(VERSION) + " "  + std::string(__TIME__) + " " + std::string(__DATE__);
    #endif
};

#endif