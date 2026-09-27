#include "TextFilter.h"
#include <fstream>
#include <sstream>
#include <cctype>

std::set<std::string> loadForbiddenWords(const std::string& fileName)
{
    std::set<std::string> words;
    std::ifstream file(fileName);
    std::string word;
    while (file >> word)
    {
        for (auto& c : word)
        {
            c = (char)tolower((unsigned char)c);
        }
        words.insert(word);
    }
    return words;
}

std::string readFile(const std::string& fileName)
{
    std::ifstream file(fileName);
    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void writeFile(const std::string& fileName, const std::string& text)
{
    std::ofstream file(fileName);
    file << text;
}

static std::string toLowerClean(const std::string& word)
{
    std::string clean;
    for (char c : word)
    {
        if (isalpha((unsigned char)c))
        {
            clean += (char)tolower((unsigned char)c);
        }
    }
    return clean;
}

std::string filterText(const std::string& text, const std::set<std::string>& forbiddenWords)
{
    std::istringstream stream(text);
    std::ostringstream result;
    std::string word;
    bool first = true;

    while (stream >> word)
    {
        std::string clean = toLowerClean(word);
        if (forbiddenWords.find(clean) == forbiddenWords.end())
        {
            if (!first)
            {
                result << " ";
            }
            result << word;
            first = false;
        }
    }

    return result.str();
}
