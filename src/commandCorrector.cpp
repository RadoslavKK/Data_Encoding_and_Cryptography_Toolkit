#include "commandCorrector.h"
#include <map>
#include <string>
#include <algorithm>

// Helper function to initialize the map in older C++
std::map<std::string, std::string> createCommandCorrections()
{
    std::map<std::string, std::string> map;

    // menu
    map["menu"] = "menu";
    map["meun"] = "menu";
    map["mneu"] = "menu";
    map["mnue"] = "menu";
    map["mennu"] = "menu";
    map["menuu"] = "menu";
    map["men"] = "menu";
    map["meu"] = "menu";

    // help
    map["help"] = "help";
    map["hepl"] = "help";
    map["hlep"] = "help";
    map["hlpe"] = "help";
    map["hellp"] = "help";
    map["hep"] = "help";
    map["elhp"] = "help";
    map["hell"] = "help";

    // all
    map["all"] = "all";
    map["al"] = "all";
    map["alL"] = "all";
    map["alll"] = "all";
    map["awl"] = "all";
    map["alol"] = "all";
    map["alll"] = "all";
    map["allll"] = "all";
    map["al"] = "all";
    map["ll"] = "all";
    map["alil"] = "all";
    map["allz"] = "all";
    map["al1"] = "all";
    map["a1l"] = "all";
    map["all1"] = "all";

    // exit
    map["exit"] = "exit";
    map["exitt"] = "exit";
    map["extt"] = "exit";
    map["exiit"] = "exit";
    map["exut"] = "exit";
    map["exti"] = "exit";
    map["exi"] = "exit";
    map["eexit"] = "exit";
    map["exir"] = "exit";
    map["exot"] = "exit";

    // out → exit
    map["out"] = "exit";

    // time
    map["time"] = "time";
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

    // version
    map["version"] = "version";
    map["verion"] = "version";
    map["versoin"] = "version";
    map["vesrion"] = "version";
    map["versin"] = "version";
    map["verison"] = "version";
    map["versio"] = "version";
    map["ver"] = "version";
    map["verson"] = "version";
    map["veersion"] = "version";

    // clear
    map["claer"] = "clear";
    map["cleer"] = "clear";
    map["cclear"] = "clear";
    map["clera"] = "clear";
    map["clearn"] = "clear";

    // clean → clear
    map["clean"] = "clear";
    map["claen"] = "clear";
    map["cleen"] = "clear";
    map["claan"] = "clear";
    map["clea"] = "clear";
    map["clan"] = "clear";
    map["clena"] = "clear";

    // cls → clear
    map["cls"] = "clear";
    map["clz"] = "clear";
    map["clx"] = "clear";
    map["cs"] = "clear";
    map["csl"] = "clear";
    map["clsx"] = "clear";
    map["clzz"] = "clear";

    // binary
    map["bniary"] = "binary";
    map["binaray"] = "binary";
    map["binray"] = "binary";
    map["bainry"] = "binary";
    map["bniar"] = "binary";
    map["bynnary"] = "binary";
    map["binry"] = "binary";
    map["binarry"] = "binary";
    map["binairy"] = "binary";
    map["bynary"] = "binary";

    // hex
    map["hex"] = "hex";
    map["hee"] = "hex";
    map["hexx"] = "hex";
    map["hex"] = "hex";
    map["hexs"] = "hex";
    map["hexa"] = "hex";
    map["hexz"] = "hex";
    map["hax"] = "hex";
    map["hxe"] = "hex";
    map["hx"] = "hex";
    map["hexx"] = "hex";
    map["hec"] = "hex";
    map["hexr"] = "hex";

    // encode62
    map["encode62"] = "encode62";
    map["encod62"] = "encode62";
    map["encode62s"] = "encode62";
    map["encod62"] = "encode62";
    map["encode6"] = "encode62";
    map["encod6"] = "encode62";
    map["encode62x"] = "encode62";
    map["encode62y"] = "encode62";
    map["encode62z"] = "encode62";

    // encode64
    map["encode64"] = "encode64";
    map["encod64"] = "encode64";
    map["encode64s"] = "encode64";
    map["encod64"] = "encode64";
    map["encode6"] = "encode64";
    map["encod6"] = "encode64";
    map["encode64x"] = "encode64";
    map["encode64y"] = "encode64";
    map["encode64z"] = "encode64";

    // decode64
    map["decode64"] = "decode64";
    map["decod64"] = "decode64";
    map["decode64s"] = "decode64";
    map["decod64"] = "decode64";
    map["decode6"] = "decode64";
    map["decod6"] = "decode64";
    map["decode64x"] = "decode64";
    map["decode64y"] = "decode64";
    map["decode64z"] = "decode64";

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