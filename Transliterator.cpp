#include "Transliterator.h"
#include <fstream>
#include <sstream>
#include <unordered_map>

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

static const std::unordered_map<std::string, std::string>& getTable()
{
    static const std::unordered_map<std::string, std::string> table = {
        { "а", "a" }, { "А", "A" },
        { "б", "b" }, { "Б", "B" },
        { "в", "v" }, { "В", "V" },
        { "г", "h" }, { "Г", "H" },
        { "ґ", "g" }, { "Ґ", "G" },
        { "д", "d" }, { "Д", "D" },
        { "е", "e" }, { "Е", "E" },
        { "є", "ie" }, { "Є", "Ie" },
        { "ж", "zh" }, { "Ж", "Zh" },
        { "з", "z" }, { "З", "Z" },
        { "и", "y" }, { "И", "Y" },
        { "і", "i" }, { "І", "I" },
        { "ї", "i" }, { "Ї", "I" },
        { "й", "i" }, { "Й", "I" },
        { "к", "k" }, { "К", "K" },
        { "л", "l" }, { "Л", "L" },
        { "м", "m" }, { "М", "M" },
        { "н", "n" }, { "Н", "N" },
        { "о", "o" }, { "О", "O" },
        { "п", "p" }, { "П", "P" },
        { "р", "r" }, { "Р", "R" },
        { "с", "s" }, { "С", "S" },
        { "т", "t" }, { "Т", "T" },
        { "у", "u" }, { "У", "U" },
        { "ф", "f" }, { "Ф", "F" },
        { "х", "kh" }, { "Х", "Kh" },
        { "ц", "ts" }, { "Ц", "Ts" },
        { "ч", "ch" }, { "Ч", "Ch" },
        { "ш", "sh" }, { "Ш", "Sh" },
        { "щ", "shch" }, { "Щ", "Shch" },
        { "ь", "" },
        { "ю", "iu" }, { "Ю", "Iu" },
        { "я", "ia" }, { "Я", "Ia" },
        { "'", "" }
    };
    return table;
}

static int utf8CharLength(unsigned char firstByte)
{
    if ((firstByte & 0x80) == 0x00)
    {
        return 1;
    }
    if ((firstByte & 0xE0) == 0xC0)
    {
        return 2;
    }
    if ((firstByte & 0xF0) == 0xE0)
    {
        return 3;
    }
    return 4;
}

std::string transliterate(const std::string& text)
{
    const auto& table = getTable();
    std::string result;
    size_t i = 0;

    while (i < text.size())
    {
        int len = utf8CharLength((unsigned char)text[i]);
        std::string ch = text.substr(i, len);

        auto it = table.find(ch);
        if (it != table.end())
        {
            result += it->second;
        }
        else
        {
            result += ch;
        }

        i += len;
    }

    return result;
}
