#ifndef SETTINGSOPTIONSMANAGER_H
#define SETTINGSOPTIONSMANAGER_H

#include "Settings.h"

class SettingsOptionsManager {
    public:
        SettingsOptionsManager();

        void setOption(char *opt);

        void setValues(char **vals);

        void applyOptionChanges(Settings *settings);

    private:
        char *option;
        char **values;
};

#endif