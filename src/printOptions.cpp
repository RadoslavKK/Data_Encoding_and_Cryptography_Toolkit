#include "printOptions.h"
#include <iostream>

void printMenu()
{
  std::cout << "\n|================================ Main Menu ================================|\n"
            << "|                                                                           |\n"
            << "| menu         -> Menu                                                      |\n"
            << "| help         -> Detailed help guide with explanations.                    |\n"
            << "| all          -> List all Command Alternatives                             |\n"
            << "| time         -> Time & Date.                                              |\n"
            << "| encode62     -> Base62 Encode a String                                    |\n"
            << "| encode64     -> Base64 Encode a String                                    |\n"
            << "| decode64     -> Base64 Decode a String                                    |\n"
            << "| sha256       -> Generate SHA-256 hash of a string                         |\n"
            << "| keycomapre   -> Compare two keys for equality                             |\n"
            << "| randomkey    -> Generate a secure random key                              |\n"
            << "| randomkey62  -> Generate a secure random key using Base62 encoding        |\n"
            << "| randomkey64  -> Generate a secure random key using Base64 encoding        |\n"
            << "| binary       -> Convert Binary to DEC, HEX, or OCT                        |\n"
            << "| clear        -> Clear the terminal screen                                 |\n"
            << "| test         -> Run Base64 encoding test                                  |\n"
            << "| cursor       -> Change the menu cursor '>>> '                             |\n"
            << "| version      -> Show Encoding Toolkit++ version number                    |\n"
            << "| exit         -> Exit the program                                          |\n"
            << "|                                                                           |\n"
            << "|===========================================================================|\n\n";
}

void printHelp()
{
  std::cout << "\n|=========================== Help & Usage Guide ============================|\n"
            << "|                                                                           |\n"
            << "| menu       -> Display the main menu with all primary commands.            |\n"
            << "| help       -> Show this detailed help guide with explanations.            |\n"
            << "|                                                                           |\n"
            << "| encode62   -> Encode a plain text string using Base62 encoding.           |\n"
            << "|              Example: 'hello' => 'T8dgcjRGuYUueWht'                       |\n"
            << "|                                                                           |\n"
            << "| encode64   -> Encode a plain text string using Base64 encoding.           |\n"
            << "|              Example: 'hello' => 'aGVsbG8='                               |\n"
            << "|                                                                           |\n"
            << "| decode64   -> Decode a Base64-encoded string back to its original form.   |\n"
            << "|              Example: 'aGVsbG8=' => 'hello'                               |\n"
            << "|                                                                           |\n"
            << "| sha256     -> Generate a SHA-256 cryptographic hash of input text.        |\n"
            << "|              Example: 'hello' => '2cf24dba5fb0a30e26e83b2ac5b9e29e...'    |\n"
            << "|                                                                           |\n"
            << "| keycomapre -> Compare two user-input keys to check if they are equal.     |\n"
            << "|              Whitespace-sensitive. Useful for validating user input.      |\n"
            << "|                                                                           |\n"
            << "| randomkey  -> Generate a secure random key for use in encryption.         |\n"
            << "|              Example: 'randomkey' => 'aBc123XyZ7!k9D0...'                 |\n"
            << "|                                                                           |\n"
            << "| randomkey62 -> Generate a secure random key using Base62 encoding.        |\n"
            << "|              Example: 'randomkey62' => 'Lk3GxH1PNa4xHq9T7z8V'             |\n"
            << "|                                                                           |\n"
            << "| randomkey64 -> Generate a secure random key using Base64 encoding.        |\n"
            << "|              Example: 'randomkey64' => 'YTIyNDcxMjk0b2lXdTY3LkA9'         |\n"
            << "|                                                                           |\n"
            << "| binary     -> Convert binary numbers to decimal, hexadecimal, or octal.   |\n"
            << "|              Example: '0b1010' => DEC: 10, HEX: A, OCT: 12                |\n"
            << "|                                                                           |\n"
            // << "| isbinary   -> Check whether a string is a valid binary sequence.          |\n"
            // << "|              Accepts '0b' or 'ob' prefixes (e.g., 0b1101).                |\n"
            // << "|                                                                           |\n"
            << "| cursor     -> Change the cursor used in the menu                          |\n"
            << "|               Example: '>>> ' => 'C:\\ '                                   |\n"
            << "|                                                                           |\n"
            << "| clear      -> Clears the screen. Also accepts: 'cls', 'clean', etc.       |\n"       
            << "| test       -> Run a Base64 encode/decode test to validate functionality.  |\n"
            << "| version    -> Print the version number of Encoding Toolkit++.             |\n"
            << "| exit       -> Exit the program safely.                                    |\n"
            << "|                                                                           |\n"
            << "| Notes:                                                                    |\n"
            << "| - Commands are case-insensitive and support common misspellings.          |\n"
            << "| - Use 'all' to view every recognized command and alias.                   |\n"
            << "|                                                                           |\n"
            << "|===========================================================================|\n\n";
}

void printAllCommands()
{
  // Output in a table
  std::cout << "\n|============================= Command Mappings ================================|\n";
  std::cout << "| Type                | Incorrect Input            | Correct Command            |\n";
  std::cout << "|---------------------|----------------------------|----------------------------|\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Menu Mappings
  std::cout << "| Menu                | menu, meun, mneu, mnue,    | menu                       |\n";
  std::cout << "|                     | menn, menuu, men, meu      |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Help Mappings
  std::cout << "| Help                | help, hepl, hlep, hlpe,    | help                       |\n";
  std::cout << "|                     | hellp, hep, elhp, hell     |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing All Mappings
  std::cout << "| All                 | all, al, alL, alll,        | all                        |\n";
  std::cout << "|                     | awl, alol, all1, a1l,      |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Test Mappings
  std::cout << "| Test                | test, ttst, tst, tet       | test                       |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Exit Mappings
  std::cout << "| Exit                | exit, exitt, ext, exiit,   | exit                       |\n";
  std::cout << "|                     | exut, exi, eexit, exir,    |                            |\n";
  std::cout << "|                     | exot, out                  |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Time Mappings
  std::cout << "| Time                | time, tiem, tme, tmie,     | time                       |\n";
  std::cout << "|                     | tim, timee                 |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Date Mappings (mapped to Time)
  std::cout << "| Date                | date, daet, dtae, dte,     | time                       |\n";
  std::cout << "|                     | datee, datt, dat           |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Version Mappings
  std::cout << "| Version             | version, verion, versoin,  | version                    |\n";
  std::cout << "|                     | vesrion, versin, verison,  |                            |\n";
  std::cout << "|                     | versio, ver, verson,       |                            |\n";
  std::cout << "|                     | veersion                   |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Clear Mappings
  std::cout << "| Clear               | claer, cleer, cclear,      | clear                      |\n";
  std::cout << "|                     | clera, clearn, clean       |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Clean Mappings (mapped to Clear)
  std::cout << "| Clean               | clean, claen, cleen, claan | clear                      |\n";
  std::cout << "|                     | clea, clan, clena          |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing CLS Mappings (mapped to Clear)
  std::cout << "| CLS                 | cls, clz, clx, cs, csl,    | clear                      |\n";
  std::cout << "|                     | clsx, clzz                 |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Binary Mappings
  std::cout << "| Binary              | bniary, binaray, binray,   | binary                     |\n";
  std::cout << "|                     | bainry, bniar, bynnary,    |                            |\n";
  std::cout << "|                     | binry, binarry, binairy    |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Hex Mappings
  std::cout << "| Hex                 | hex, hee, hexx, hexs,      | hex                        |\n";
  std::cout << "|                     | hexa, hexz, hax, hxe, hx   |                            |\n";
  std::cout << "|                     | hexx, hec, hexr            |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Keycompare Mappings
  std::cout << "| Key Compare         | keycompare, comparekey,    | keycompare                 |\n";
  std::cout << "|                     | key compare, compare key,  |                            |\n";
  std::cout << "|                     | keycomapre, keycopmare,    |                            |\n";
  std::cout << "|                     | keycompaer, kyecompare,    |                            |\n";
  std::cout << "|                     | kyecomapre, keycmopare,    |                            |\n";
  std::cout << "|                     | kepcompare, compareky,     |                            |\n";
  std::cout << "|                     | compaerkey, comaprekey,    |                            |\n";
  std::cout << "|                     | comaparekey, keycmpr,      |                            |\n";
  std::cout << "|                     | cmpkey, keycmpare,         |                            |\n";
  std::cout << "|                     | keycmprkey, keycompares,   |                            |\n";
  std::cout << "|                     | comparekeys, key compares, |                            |\n";
  std::cout << "|                     | compare keys, keycomapres, |                            |\n";
  std::cout << "|                     | comparekeys, keycopmares,  |                            |\n";
  std::cout << "|                     | keycompaers, kyecompares   |                            |\n";
  std::cout << "|                     | kyecomapres, keycmopares,  |                            |\n";
  std::cout << "|                     | kepcompares, comparekys,   |                            |\n";
  std::cout << "|                     | compaerkeys, comaprekeys,  |                            |\n";
  std::cout << "|                     | comaparekeys, keycmpares,  |                            |\n";
  std::cout << "|                     | keycmps, cmpkeys, keycmprs |                            |\n";
  std::cout << "|                     | cmparekeys, keycmprkeys,   |                            |\n";
  std::cout << "|                     | cmparekey, keycmp          |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing RandomKey Mappings
  std::cout << "| Random Key          | randomkey, random key,     | randomkey                  |\n";
  std::cout << "|                     | randkey, rand key,         |                            |\n";
  std::cout << "|                     | rndkey, rnd key,           |                            |\n";
  std::cout << "|                     | rkey, keyrandom,           |                            |\n";
  std::cout << "|                     | key random, randomk,       |                            |\n";
  std::cout << "|                     | randoomkey, randomekey,    |                            |\n";
  std::cout << "|                     | randomky, randomke,        |                            |\n";
  std::cout << "|                     | rendomkey, ramdomkey,      |                            |\n";
  std::cout << "|                     | radnomkey, rnadomkey,      |                            |\n";
  std::cout << "|                     | randmkey, ranomkey,        |                            |\n";
  std::cout << "|                     | ranodmkey, rndmkey,        |                            |\n";
  std::cout << "|                     | randkeygen, randomkgen,    |                            |\n";
  std::cout << "|                     | randkey64, randomkey64,    |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing RandomKey62 Mappings
  std::cout << "| Random Key 62       | randomkey62, random key 62,| randomkey62                |\n";
  std::cout << "|                     | randkey62, rand key 62,    |                            |\n";
  std::cout << "|                     | rndkey62, rnd key 62,      |                            |\n";
  std::cout << "|                     | rkey62, keyrandom62,       |                            |\n";
  std::cout << "|                     | key random 62, randomk62,  |                            |\n";
  std::cout << "|                     | randoomkey62, randomekey62,|                            |\n";
  std::cout << "|                     | randomky62, randomke62,    |                            |\n";
  std::cout << "|                     | rendomkey62, ramdomkey62,  |                            |\n";
  std::cout << "|                     | radnomkey62, rnadomkey62,  |                            |\n";
  std::cout << "|                     | randmkey62, ranomkey62,    |                            |\n";
  std::cout << "|                     | ranodmkey62, rndmkey62,    |                            |\n";
  std::cout << "|                     | randkeygen62, randomkgen62,|                            |\n";
  std::cout << "|                     | randkey6264, randomkey6264,|                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing RandomKey64 Mappings
  std::cout << "| Random Key 64       | randomkey64, random key 64,| randomkey64                |\n";
  std::cout << "|                     | randkey64, rand key 64,    |                            |\n";
  std::cout << "|                     | rndkey64, rnd key 64,      |                            |\n";
  std::cout << "|                     | rkey64, keyrandom64,       |                            |\n";
  std::cout << "|                     | key random 64, randomk64,  |                            |\n";
  std::cout << "|                     | randoomkey64, randomekey64,|                            |\n";
  std::cout << "|                     | randomky64, randomke64,    |                            |\n";
  std::cout << "|                     | rendomkey64, ramdomkey64,  |                            |\n";
  std::cout << "|                     | radnomkey64, rnadomkey64,  |                            |\n";
  std::cout << "|                     | randmkey64, ranomkey64,    |                            |\n";
  std::cout << "|                     | ranodmkey64, rndmkey64,    |                            |\n";
  std::cout << "|                     | randkeygen64, randomkgen64,|                            |\n";
  std::cout << "|                     | randkey6464, randomkey6464,|                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Encode62 Mappings
  std::cout << "| Encode62            | encode62, encod62,         | encode62                   |\n";
  std::cout << "|                     | encode62s, encod62,        |                            |\n";
  std::cout << "|                     | encode6, encod6, encode62x |                            |\n";
  std::cout << "|                     | encode62y, encode62z,      |                            |\n";
  std::cout << "|                     | encode62, encod62, encdoe62|                            |\n";
  std::cout << "|                     | enc62, 62encode, encode 62 |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Encode64 Mappings
  std::cout << "| Encode64            | encode64, 64encode,        | encode64                   |\n";
  std::cout << "|                     | encode 64, encod64,        |                            |\n";
  std::cout << "|                     | encode64s, encod64,        |                            |\n";
  std::cout << "|                     | encode6, encod6, encode64x |                            |\n";
  std::cout << "|                     | encode64y, encode64z       |                            |\n";
  std::cout << "|                     | encode64, encod64, encdoe64|                            |\n";
  std::cout << "|                     | enc64, 64encode, 64 encode |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  // Printing Decode64 Mappings
  std::cout << "| Decode64            | decode64, decode 64,       | decode64                   |\n";
  std::cout << "|                     | decod64, decode64s,        |                            |\n";
  std::cout << "|                     | decod64, decode6, decod6   |                            |\n";
  std::cout << "|                     | decode64x, decode64y,      |                            |\n";
  std::cout << "|                     | decode64, decod64, decdoe64|                            |\n";
  std::cout << "|                     | dec64, 64decode, 64 decode |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  std::cout << "| SHA256              | sha256, sha 256, sh256,    | sha256                     |\n";
  std::cout << "|                     | shas256, sha2256, sha265,  |                            |\n";
  std::cout << "|                     | sha25, shaa256, shaa 256,  |                            |\n";
  std::cout << "|                     | sha256x, sha256y, sha256z, |                            |\n";
  std::cout << "|                     | sh256a, shaz256, shsa256,  |                            |\n";
  std::cout << "|                     | has256, hsa256, sa256,     |                            |\n";
  std::cout << "|                     | sah256                     |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  std::cout << "| CURSOR              | cursor, cur sor, crusor,   | cursor                     |\n";
  std::cout << "|                     | curser, kursur, kursor,    |                            |\n";
  std::cout << "|                     | corsur, curzor, corsor,    |                            |\n";
  std::cout << "|                     | coursor, curor, cursr,     |                            |\n";
  std::cout << "|                     | cusor, cursur, curzor64,   |                            |\n";
  std::cout << "|                     | cursor64, cursorgen,       |                            |\n";
  std::cout << "|                     | cursor generator           |                            |\n";
  std::cout << "|                     |                            |                            |\n";

  std::cout << "|===============================================================================|\n"
            << std::endl;
}