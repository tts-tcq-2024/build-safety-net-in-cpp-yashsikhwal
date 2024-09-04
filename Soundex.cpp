#include "Soundex.h"
#include <cctype>
#include <map>


char getSoundexCode(char c) 
{
    c = toupper(c);
    std::map<char, char> charToIntMap {
            {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
            {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
            {'D', '3'}, {'T', '3'},
            {'L', '4'},
            {'M', '5'}, {'N', '5'},
            {'R', '6'},
            {'A', '0'}, {'E', '0'}, {'I', '0'}, {'O', '0'}, {'U', '0'}, {'H', '0'}, {'W', '0'}, {'Y', '0'}
        };
    return charToIntMap[c];
}

// Adds 0 padding if length of soundex is less than 4
std::string addZeroPadding(std::string soundex)
{
    while (soundex.length() < 4)
        soundex += '0';
    return soundex;
}

// Appends code to soundex if code is not 0 and previous character is not repeating 
void appendSoundex(std::string& soundex, char& prevCode, char code)
{
    if (code != '0' && code != prevCode) 
    {
        soundex += code;
        prevCode = code;
    }
}

// Iterates name and appends the converted character to soundex until either soundex is of length 4 or name runs out of characters
void iterateName(std::string& soundex, std::string name)
{
    char prevCode = getSoundexCode(name[0]);
    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) 
    {
        char code = getSoundexCode(name[i]);
        appendSoundex(soundex, prevCode, code);
    }
}

std::string generateSoundex(const std::string& name) 
{
    if (name.empty()) 
        return "";

    std::string soundex(1, toupper(name[0]));

    iterateName(soundex, name);

    return addZeroPadding(soundex);
}
