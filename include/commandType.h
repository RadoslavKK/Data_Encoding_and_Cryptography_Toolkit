#ifndef COMMAND_TYPE_H
#define COMMAND_TYPE_H

#include <string>

enum CommandType
{
    CMD_MENU,
    CMD_HELP,
    CMD_ALL,
    CMD_EMPTY,
    CMD_TIME,
    CMD_EXIT,
    CMD_CLEAR,
    CMD_VERSION,
    CMD_ENCODE62,
    CMD_ENCODE64,
    CMD_DECODE64,
    CMD_BINARY,
    CMD_HEX,
    CMD_ISBINARY,
    CMD_TEST,
    CMD_UNKNOWN,
    CMD_KEYCOMPARE,
    CMD_GENERATE_RANDOM_KEY,
    CMD_GENERATE_BASE62_KEY,
    CMD_GENERATE_BASE64_KEY
};

// Maps User Command Input to  ENUM
CommandType getCommandType(const std::string &input);

#endif