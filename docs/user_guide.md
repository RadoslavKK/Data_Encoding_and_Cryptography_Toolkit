### ____________________________ How to Run the Program. ____________________________

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