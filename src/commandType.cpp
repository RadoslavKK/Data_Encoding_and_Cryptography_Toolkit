#include "commandType.h"

CommandType getCommandType(const std::string& input)
{
    if(input == "")             return CMD_EMPTY;
    if (input == "menu")        return CMD_MENU;
    if (input == "help")        return CMD_HELP;
    if (input == "all")         return CMD_ALL;
    if(input == "time")         return CMD_TIME;
    if (input == "exit")        return CMD_EXIT;
    if (input == "clear")       return CMD_CLEAR;
    if (input == "version")     return CMD_VERSION;
    if (input == "encode62")    return CMD_ENCODE62;
    if (input == "encode64")    return CMD_ENCODE64;
    if (input == "decode64")    return CMD_DECODE64;
    if (input == "binary")      return CMD_BINARY;
    if (input == "hex")         return CMD_HEX;
    if (input == "test")        return CMD_TEST;

    return CMD_UNKNOWN;
}