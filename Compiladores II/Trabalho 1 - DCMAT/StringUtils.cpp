#include "StringUtils.h"

#include <sstream>

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

std::string replaceSubStr(std::string original, std::string target, std::string replacement) {
    std::vector<std::string> splt = split(original, " ");
    std::stringstream ss;
    std::string str;
    for(int i = 0; i < splt.size(); i++) {
        if(splt[i].compare(target) == 0) {
            str = replacement;
        } else {
            str = splt[i];
        }
        if(i > 0) ss << " ";
        ss << str;
    }

    return ss.str();
}
