#include "commandCorrector.h"
#include <map>
#include <string>
#include <algorithm>

// Helper function to initialize the map in older C++
std::map<std::string, std::string> createCommandCorrections()
{
    std::map<std::string, std::string> map;

    // menu
    map["meun"] = "menu";
    map["mneu"] = "menu";
    map["mnue"] = "menu";
    map["mennu"] = "menu";
    map["menuu"] = "menu";
    map["men"] = "menu";
    map["meu"] = "menu";

    // exit
    map["exiit"] = "exit";
    map["exut"] = "exit";
    map["exti"] = "exit";
    map["exi"] = "exit";
    map["eexit"] = "exit";
    map["exir"] = "exit";
    map["exot"] = "exit";

    // version
    map["verion"] = "version";
    map["versoin"] = "version";
    map["vesrion"] = "version";
    map["versin"] = "version";
    map["verison"] = "version";
    map["versio"] = "version";
    map["ver"] = "version";
    map["verson"] = "version";
    map["veersion"] = "version";

    // help
    map["hepl"] = "help";
    map["hlep"] = "help";
    map["hlpe"] = "help";
    map["hellp"] = "help";
    map["hep"] = "help";
    map["elhp"] = "help";
    map["hell"] = "help";

    // time
    map["tiem"] = "time";
    map["tme"] = "time";
    map["tmie"] = "time";
    map["tim"] = "time";
    map["timee"] = "time";

    // date → time
    map["date"] = "time";
    map["daet"] = "time";
    map["dtae"] = "time";
    map["dte"] = "time";
    map["datee"] = "time";
    map["datt"] = "time";
    map["dat"] = "time";

    // clean → clear
    map["clean"] = "clear";
    map["claen"] = "clear";
    map["cleen"] = "clear";
    map["claan"] = "clear";
    map["clea"] = "clear";
    map["clan"] = "clear";
    map["clena"] = "clear";
    map["cleean"] = "clear";

    // clear (also reinforce common mistypes)
    map["claer"] = "clear";
    map["cleer"] = "clear";
    map["cclear"] = "clear";
    map["clera"] = "clear";
    map["clearn"] = "clear";

    // cls → clear
    map["cls"] = "clear";
    map["clz"] = "clear";
    map["clx"] = "clear";
    map["cs"] = "clear";
    map["csl"] = "clear";
    map["clsx"] = "clear";
    map["clzz"] = "clear";

    return map;
}

std::string correctCommand(const std::string &command)
{
    static const std::map<std::string, std::string> commandCorrections = createCommandCorrections();

    std::string lower = command;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    std::map<std::string, std::string>::const_iterator it = commandCorrections.find(lower);
    if (it != commandCorrections.end())
    {
        return it->second;
    }

    return command;
}