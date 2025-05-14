#ifndef BASE62_DECODER_H
#define BASE62_DECODER_H

#include <string>

// Encodes the given string into Base62 using the custom character set.
std::string base62Decoder(const std::string& data, const std::string& key);

#endif