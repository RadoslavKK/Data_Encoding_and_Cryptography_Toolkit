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

    // test62 enocde/decode Base62
    map["test62"] = "test62";
    map["test62"] = "test62";
    map["ttst62"] = "test62";
    map["tst62"] = "test62";
    map["tet62"] = "test62";

    // test64 enocde/decode Base64
    map["test64"] = "test64";
    map["test64"] = "test64";
    map["ttst64"] = "test64";
    map["tst64"] = "test64";
    map["tet64"] = "test64";

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

    // keycompare
    map["keycompare"] = "keycompare";
    map["comparekey"] = "keycompare";
    map["key compare"] = "keycompare";
    map["compare key"] = "keycompare";
    map["keycompare"] = "keycompare";
    map["comparekey"] = "keycompare";
    map["keycomapre"] = "keycompare";
    map["keycopmare"] = "keycompare";
    map["keycompaer"] = "keycompare";
    map["kyecompare"] = "keycompare";
    map["kyecomapre"] = "keycompare";
    map["keycmopare"] = "keycompare";
    map["kepcompare"] = "keycompare";
    map["compareky"] = "keycompare";
    map["compaerkey"] = "keycompare";
    map["comaprekey"] = "keycompare";
    map["comaparekey"] = "keycompare";
    map["keycmpr"] = "keycompare";
    map["keycmp"] = "keycompare";
    map["cmpkey"] = "keycompare";
    map["keycmpare"] = "keycompare";
    map["cmparekey"] = "keycompare";
    map["keycmprkey"] = "keycompare";
    map["keycompares"] = "keycompare";
    map["comparekeys"] = "keycompare";
    map["key compares"] = "keycompare";
    map["compare keys"] = "keycompare";
    map["keycomapres"] = "keycompare";
    map["comparekeys"] = "keycompare";
    map["keycomapres"] = "keycompare";
    map["keycopmares"] = "keycompare";
    map["keycompaers"] = "keycompare";
    map["kyecompares"] = "keycompare";
    map["kyecomapres"] = "keycompare";
    map["keycmopares"] = "keycompare";
    map["kepcompares"] = "keycompare";
    map["comparekys"] = "keycompare";
    map["compaerkeys"] = "keycompare";
    map["comaprekeys"] = "keycompare";
    map["comaparekeys"] = "keycompare";
    map["keycmprs"] = "keycompare";
    map["keycmps"] = "keycompare";
    map["cmpkeys"] = "keycompare";
    map["keycmpares"] = "keycompare";
    map["cmparekeys"] = "keycompare";
    map["keycmprkeys"] = "keycompare";

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
    map["encode62"] = "encode62";
    map["encod62"] = "encode62";
    map["encdoe62"] = "encode62";
    map["enc62"] = "encode62";
    map["62encode"] = "encode62";
    map["62 encode"] = "encode62";
    map["encode 62"] = "encode62";
    map["en62"] = "encode62";
    map["enccode62"] = "encode62";
    map["encide62"] = "encode62";
    map["enocde62"] = "encode62";

    // decode62
    map["decode62"] = "decode62";
    map["decod62"] = "decode62";
    map["decode6"] = "decode62";
    map["decod6"] = "decode62";
    map["decode62s"] = "decode62";
    map["decode62x"] = "decode62";
    map["decode62y"] = "decode62";
    map["decode62z"] = "decode62";
    map["decdoe62"] = "decode62";
    map["deocde62"] = "decode62";
    map["dec62"] = "decode62";
    map["62decode"] = "decode62";
    map["62 decode"] = "decode62";
    map["decode 62"] = "decode62";
    map["de62"] = "decode62";
    map["deccode62"] = "decode62";
    map["decide62"] = "decode62";
    map["denocde62"] = "decode62";
    map["docede62"] = "decode62";
    map["dedoce62"] = "decode62";

    // encode64
    map["encode64"] = "encode64";
    map["64encode"] = "encode64";
    map["64 encode"] = "encode64";
    map["encod64"] = "encode64";
    map["encode 64"] = "encode64";
    map["encod 64"] = "encode64";
    map["encode64s"] = "encode64";
    map["encod64"] = "encode64";
    map["encode6"] = "encode64";
    map["encod6"] = "encode64";
    map["encode64x"] = "encode64";
    map["encode64y"] = "encode64";
    map["encode64z"] = "encode64";
    map["encode64"] = "encode64";
    map["encod64"] = "encode64";
    map["encdoe64"] = "encode64";
    map["enc64"] = "encode64";
    map["64encode"] = "encode64";
    map["64 encode"] = "encode64";
    map["encode 64"] = "encode64";
    map["en64"] = "encode64";
    map["endcode64"] = "encode64";
    map["enccode64"] = "encode64";
    map["encide64"] = "encode64";
    map["encdoe64"] = "encode64";
    map["enocde64"] = "encode64";

    // decode64
    map["decode64"] = "decode64";
    map["decode 64"] = "decode64";
    map["decod64"] = "decode64";
    map["decode64s"] = "decode64";
    map["decod64"] = "decode64";
    map["decode6"] = "decode64";
    map["decod6"] = "decode64";
    map["decode64x"] = "decode64";
    map["decode64y"] = "decode64";
    map["decode64z"] = "decode64";
    map["decode64"] = "decode64";
    map["decod64"] = "decode64";
    map["decdoe64"] = "decode64";
    map["dec64"] = "decode64";
    map["64decode"] = "decode64";
    map["64 decode"] = "decode64";
    map["decode 64"] = "decode64";
    map["dec64"] = "decode64";
    map["decocde64"] = "decode64";
    map["decide64"] = "decode64";
    map["deocde64"] = "decode64";
    map["decoed64"] = "decode64";

    // sha256
    map["sha256"] = "sha256";
    map["sha 256"] = "sha256";
    map["sh256"] = "sha256";
    map["shas256"] = "sha256";
    map["sha2256"] = "sha256";
    map["sha265"] = "sha256";
    map["sha25"] = "sha256";
    map["shaa256"] = "sha256";
    map["shaa 256"] = "sha256";
    map["sha256x"] = "sha256";
    map["sha256y"] = "sha256";
    map["sha256z"] = "sha256";
    map["sh256a"] = "sha256";
    map["shaz256"] = "sha256";
    map["shsa256"] = "sha256";
    map["has256"] = "sha256";
    map["hsa256"] = "sha256";
    map["sa256"] = "sha256";
    map["sah256"] = "sha256";
    map["shah256"] = "sha256";
    map["sh256h"] = "sha256";
    map["sha2 56"] = "sha256";
    map["sha-256"] = "sha256";
    map["sh-a256"] = "sha256";
    map["sha_256"] = "sha256";
    map["sh_a256"] = "sha256";

    // randomkey
    map["randomkey"] = "randomkey";
    map["random key"] = "randomkey";
    map["randkey"] = "randomkey";
    map["rand key"] = "randomkey";
    map["rndkey"] = "randomkey";
    map["rnd key"] = "randomkey";
    map["rkey"] = "randomkey";
    map["keyrandom"] = "randomkey";
    map["key random"] = "randomkey";
    map["randomk"] = "randomkey";
    map["randoomkey"] = "randomkey";
    map["randomekey"] = "randomkey";
    map["randomky"] = "randomkey";
    map["randomke"] = "randomkey";
    map["rendomkey"] = "randomkey";
    map["ramdomkey"] = "randomkey";
    map["radnomkey"] = "randomkey";
    map["rnadomkey"] = "randomkey";
    map["randmkey"] = "randomkey";
    map["ranomkey"] = "randomkey";
    map["ranodmkey"] = "randomkey";
    map["rndmkey"] = "randomkey";
    map["randkeygen"] = "randomkey";
    map["randomkgen"] = "randomkey";
    map["randkey64"] = "randomkey";
    map["randomkey64"] = "randomkey";

    // randomkey62
    map["randomkey62"] = "randomkey62";
    map["random key 62"] = "randomkey62";
    map["randkey62"] = "randomkey62";
    map["rand key 62"] = "randomkey62";
    map["rndkey62"] = "randomkey62";
    map["rnd key 62"] = "randomkey62";
    map["rkey62"] = "randomkey62";
    map["keyrandom62"] = "randomkey62";
    map["key random 62"] = "randomkey62";
    map["randomk62"] = "randomkey62";
    map["randoomkey62"] = "randomkey62";
    map["randomekey62"] = "randomkey62";
    map["randomky62"] = "randomkey62";
    map["randomke62"] = "randomkey62";
    map["rendomkey62"] = "randomkey62";
    map["ramdomkey62"] = "randomkey62";
    map["radnomkey62"] = "randomkey62";
    map["rnadomkey62"] = "randomkey62";
    map["randmkey62"] = "randomkey62";
    map["ranomkey62"] = "randomkey62";
    map["ranodmkey62"] = "randomkey62";
    map["rndmkey62"] = "randomkey62";
    map["randkeygen62"] = "randomkey62";
    map["randomkgen62"] = "randomkey62";
    map["randkey6264"] = "randomkey62";
    map["randomkey6264"] = "randomkey62";

    // randomkey64
    map["randomkey64"] = "randomkey64";
    map["random key 64"] = "randomkey64";
    map["randkey64"] = "randomkey64";
    map["rand key 64"] = "randomkey64";
    map["rndkey64"] = "randomkey64";
    map["rnd key 64"] = "randomkey64";
    map["rkey64"] = "randomkey64";
    map["keyrandom64"] = "randomkey64";
    map["key random 64"] = "randomkey64";
    map["randomk64"] = "randomkey64";
    map["randoomkey64"] = "randomkey64";
    map["randomekey64"] = "randomkey64";
    map["randomky64"] = "randomkey64";
    map["randomke64"] = "randomkey64";
    map["rendomkey64"] = "randomkey64";
    map["ramdomkey64"] = "randomkey64";
    map["radnomkey64"] = "randomkey64";
    map["rnadomkey64"] = "randomkey64";
    map["randmkey64"] = "randomkey64";
    map["ranomkey64"] = "randomkey64";
    map["ranodmkey64"] = "randomkey64";
    map["rndmkey64"] = "randomkey64";
    map["randkeygen64"] = "randomkey64";
    map["randomkgen64"] = "randomkey64";
    map["randkey6464"] = "randomkey64";
    map["randomkey6464"] = "randomkey64";

    // cursor
    map["cursor"] = "cursor";
    map["cur sor"] = "cursor";
    map["crusor"] = "cursor";
    map["curser"] = "cursor";
    map["kursur"] = "cursor";
    map["kursor"] = "cursor";
    map["corsur"] = "cursor";
    map["curzor"] = "cursor";
    map["corsor"] = "cursor";
    map["coursor"] = "cursor";
    map["curor"] = "cursor";
    map["cursr"] = "cursor";
    map["cusor"] = "cursor";
    map["cursur"] = "cursor";
    map["curzor64"] = "cursor"; // in case of misused suffix
    map["cursor64"] = "cursor";
    map["cursorgen"] = "cursor";
    map["cursor generator"] = "cursor";
    map["cursorgen"] = "cursor";
    map["cur sor gen"] = "cursor";

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