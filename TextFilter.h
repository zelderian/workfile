#ifndef TEXTFILTER_H
#define TEXTFILTER_H

#include <string>
#include <set>

std::set<std::string> loadForbiddenWords(const std::string& fileName);
std::string filterText(const std::string& text, const std::set<std::string>& forbiddenWords);
std::string readFile(const std::string& fileName);
void writeFile(const std::string& fileName, const std::string& text);

#endif
