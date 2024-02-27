#include "Settings.h"
#include <cstring>

/* Valores padrão das configurações */
const float
    H_VIEW_LO = -6.500000,
    H_VIEW_HI = 6.500000,
    V_VIEW_LO = -3.500000,
    V_VIEW_HI = 3.500000;

const int
    FLOAT_PRECISION = 6,
    INTEGRAL_STEPS = 1000;

const bool
    DRAW_AXIS = true,
    ERASE_PLOT = true,
    CONNECT_DOTS = false;


Settings::Settings() {
    this->h_view_lo = H_VIEW_LO;
    this->h_view_hi = H_VIEW_HI;
    this->v_view_lo = V_VIEW_LO;
    this->v_view_hi = V_VIEW_HI;
    this->float_precision = FLOAT_PRECISION;
    this->integral_steps = INTEGRAL_STEPS;
    this->draw_axis = DRAW_AXIS;
    this->erase_plot = ERASE_PLOT;
    this->connect_dots = CONNECT_DOTS;

    std::cout << std::fixed;
    std::cout.precision(float_precision);
}

char* Settings::printSettings() {
    std::string temp = "";

    temp += "\nh_view_lo: " + std::to_string(this->h_view_lo);
    temp += "\nh_view_hi: " + std::to_string(this->h_view_hi);
    temp += "\nv_view_lo: " + std::to_string(this->v_view_lo);
    temp += "\nv_view_hi: " + std::to_string(this->v_view_hi);
    temp += "\nfloat precision: " + std::to_string(this->float_precision);
    temp += "\nintegral_steps: " + std::to_string(this->integral_steps);
    temp += "\n";
    temp += "\nDraw Axis: ";
    temp += ((this->draw_axis) ? "ON" : "OFF");
    temp += "\nErase Plot: ";
    temp += ((this->erase_plot) ? "ON" : "OFF");
    temp += "\nConnect Dots: ";
    temp += ((this->connect_dots) ? "ON" : "OFF");
    temp += "\n\n";

    char *settings = (char *) malloc(temp.length() + 1);

    memcpy(settings, temp.data(), temp.length());

    return settings;
}

void Settings::resetSettings() {
    this->h_view_lo = H_VIEW_LO;
    this->h_view_hi = H_VIEW_HI;
    this->v_view_lo = V_VIEW_LO;
    this->v_view_hi = V_VIEW_HI;
    this->float_precision = FLOAT_PRECISION;
    this->integral_steps = INTEGRAL_STEPS;
    this->draw_axis = DRAW_AXIS;
    this->erase_plot = ERASE_PLOT;
    this->connect_dots = CONNECT_DOTS;
}

void Settings::setHView(float new_lo, float new_hi) {
    this->h_view_lo = new_lo;
    this->h_view_hi = new_hi;
}

void Settings::setVView(float new_lo, float new_hi) {
    this->v_view_lo = new_lo;
    this->v_view_hi = new_hi;
}

void Settings::setAxis(bool value) {
    this->draw_axis = value;
}

void Settings::setErasePlot(bool value) {
    this->erase_plot = value;
}

void Settings::setIntegralSteps(int steps) {
    this->integral_steps = steps;
}

void Settings::setFloatPrecision(int precision) {
    this->float_precision = precision;
}

void Settings::setConnectDots(bool value) {
    this->connect_dots = value;
}

float Settings::getHViewLow() {
    return this->h_view_lo;
}

float Settings::getHViewHigh() {
    return this->h_view_hi;
}

float Settings::getVViewLow() {
    return this->v_view_lo;
}

float Settings::getVViewHigh() {
    return this->v_view_hi;
}

int Settings::getFloatPrecision() {
    return this->float_precision;
}

int Settings::getIntegralSteps() {
    return this->integral_steps;
}

bool Settings::getDrawAxis() {
    return this->draw_axis;
}

bool Settings::getErasePlot() {
    return this->erase_plot;
}

bool Settings::getConnectDots() {
    return this->connect_dots;
}
