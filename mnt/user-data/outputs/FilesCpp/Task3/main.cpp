#include "Transliterator.h"
#include <iostream>

int main()
{
    std::string sourceText = "Привіт, як справи? Це тестовий текст українською мовою.";
    writeFile("source_ua.txt", sourceText);

    std::string text = readFile("source_ua.txt");
    std::string result = transliterate(text);

    writeFile("result_en.txt", result);

    std::cout << "Оригінал:" << std::endl << text << std::endl << std::endl;
    std::cout << "Транслітерація:" << std::endl << result << std::endl;

    return 0;
}
