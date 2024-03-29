#ifndef STIRNGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <vector>

std::vector<std::string> split(const std::string &str, const std::string &splitter);

std::string replaceSubStr(std::string original, std::string target, std::string replacement);

#endif