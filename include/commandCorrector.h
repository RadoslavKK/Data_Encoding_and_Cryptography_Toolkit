#ifndef COMMAND_CORRECTOR_H
#define COMMAND_CORRECTOR_H

#include <string>

// Returns the corrected version of the command if found,
// otherwise returns the original input (unchanged).
std::string correctCommand(const std::string& command);

#endif // COMMAND_CORRECTOR_H
