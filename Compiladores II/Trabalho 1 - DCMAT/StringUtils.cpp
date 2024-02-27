#include "StringUtils.h"

std::vector<std::string> split(const std::string &str, const std::string &splitter) {
    std::vector<std::string> result;
    size_t start = 0, end;

    while ((end = str.find(splitter, start)) != std::string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + splitter.size();
    }

    result.push_back(str.substr(start));
    return result;
}
