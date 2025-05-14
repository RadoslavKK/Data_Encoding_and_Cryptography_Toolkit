#ifndef BASE64_DECODER_H
#define BASE64_DECODER_H

#include <string>

// Decodes a Base64-encoded string using the custom character set.
std::string base64Decoder(const std::string& data, const std::string& key);

#endif // BASE64_DECODER_H
