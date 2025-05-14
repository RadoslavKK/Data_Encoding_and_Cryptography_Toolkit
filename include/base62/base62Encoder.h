#ifndef BASE62_ENCODER_H
#define BASE62_ENCODER_H

#include <string>

// Encodes the given string into Base62 using the custom character set.
std::string base62Encoder(const std::string& data, const std::string& key);

#endif