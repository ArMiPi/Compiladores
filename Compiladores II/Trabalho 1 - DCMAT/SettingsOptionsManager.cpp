#include "SettingsOptionsManager.h"

#include <string>
#include <cstring>

SettingsOptionsManager::SettingsOptionsManager() {
    option = NULL;
    values = NULL;
}

void SettingsOptionsManager::setOption(char *opt) {
    if(option) {
        free(option);
    }
    option = opt;
}

void SettingsOptionsManager::setValues(char **vals) {
    if(values) {
        for(int i = 0; values[i]; i++) {
            free(values[i]);
        }
        free(values);
    }

    values = vals;
}

void SettingsOptionsManager::applyOptionChanges(Settings *settings) {
    std::string name = std::string(option);
    
    if(name.compare("h_view") == 0) {
        float low = std::stof(std::string(values[0]));
        float high = std::stof(std::string(values[1]));

        settings->setHView(low, high);
    } else if(name.compare("v_view") == 0) {
        float low = std::stof(std::string(values[0]));
        float high = std::stof(std::string(values[1]));

        settings->setVView(low, high);
    } else if(name.compare("axis") == 0) {
        std::string value = std::string(values[0]);
        bool val = (value.compare("on") == 0) ? true : false;

        settings->setAxis(val);
    } else if(name.compare("erase_plot") == 0) {
        std::string value = std::string(values[0]);
        bool val = (value.compare("on") == 0) ? true : false;

        settings->setErasePlot(val);
    } else if(name.compare("integral_steps") == 0) {
        int steps = std::stoi(std::string(values[0]));

        settings->setIntegralSteps(steps);
    } else if(name.compare("float_precision") == 0) {
        int precision = std::stoi(std::string(values[0]));

        settings->setFloatPrecision(precision);
    } else if(name.compare("connect_dots") == 0) {
        std::string value = std::string(values[0]);
        bool val = (value.compare("on") == 0) ? true : false;

        settings->setConnectDots(val);
    }
}
