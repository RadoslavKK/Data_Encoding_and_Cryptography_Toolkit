#ifndef BASE64_ENCODER_H
#define BASE64_ENCODER_H

#include <string>

// Encodes the given string into Base64 using the custom character set.
std::string base64Encoder(const std::string& data, const std::string& key);

#endif
