#include "commandType.h"

CommandType getCommandType(const std::string& input)
{
    if (input == "menu")        return CMD_MENU;
    if (input == "help")        return CMD_HELP;
    if (input == "all")         return CMD_ALL;
    if (input == "exit")        return CMD_EXIT;
    if (input == "clear")       return CMD_CLEAR;
    if (input == "version")     return CMD_VERSION;
    if (input == "encode62")    return CMD_ENCODE62;
    if (input == "encode64")    return CMD_ENCODE64;
    if (input == "decode64")    return CMD_DECODE64;
    if (input == "binary")      return CMD_BINARY;
   // if (input == "isbinary")    return CMD_ISBINARY; // Add soon.
    if (input == "test")        return CMD_TEST;

    return CMD_UNKNOWN;
}