#ifndef TRANSLITERATOR_H
#define TRANSLITERATOR_H

#include <string>

std::string transliterate(const std::string& text);
std::string readFile(const std::string& fileName);
void writeFile(const std::string& fileName, const std::string& text);

#endif
