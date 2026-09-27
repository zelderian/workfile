#include "TextFilter.h"
#include <iostream>

int main()
{
    std::string sourceText = "This is a stupid example text with some bad idiot words inside.";
    writeFile("source.txt", sourceText);

    std::string forbiddenWordsContent = "stupid\nbad\nidiot";
    writeFile("forbidden.txt", forbiddenWordsContent);

    std::set<std::string> forbiddenWords = loadForbiddenWords("forbidden.txt");
    std::string text = readFile("source.txt");
    std::string cleanedText = filterText(text, forbiddenWords);

    writeFile("cleaned.txt", cleanedText);

    std::cout << "Оригінальний текст:" << std::endl << text << std::endl << std::endl;
    std::cout << "Очищений текст:" << std::endl << cleanedText << std::endl;

    return 0;
}
