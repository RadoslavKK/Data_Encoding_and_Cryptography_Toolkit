# 🔐 Encoding Toolkit++

A modular C++ utility for encoding, decoding, and data conversion tasks.  
Includes support for Base64/Base62 encoding and decoding.
Future Support for binary-to-hex/dec/oct conversion, key validation, and a custom URL shortener.

## 🛠️ Features

- ✅ Base64 & Base62 encoder/decoder with custom character sets  
- 📦 File reader & key validator modules  
- 🧪 Modular, extendable structure using header/source files  
- 🖥️ Clean terminal UI with a user-friendly command menu

## How to Run:

## 1. Set Base62 & Base64 Key Path in "main.cpp" on Lines 80 & 81

   File Names "base62Key.txt" & "base64Key.txt" located in "keys" Folder

   FilePathManager::getInstance().setBase64KeyPath(" < base64Key.txt File Path > ");
   FilePathManager::getInstance().setBase62KeyPath(" < base62Key.txt File Path > ");

## 2. Open a Terminal window.

## 3. Navigate to the project directory:
   cd EncodingToolkit++    // Change to the project directory.

## 4. Build the program:
   make                    // Compile the project and generate the executable.

## 5. Run the program:
   make run                // Execute the program.

## 6. Clean the build files:
   make clean              // Remove compiled files and clean up the project.
