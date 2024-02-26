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
    h_view_lo = H_VIEW_LO;
    h_view_hi = H_VIEW_HI;
    v_view_lo = V_VIEW_LO;
    v_view_hi = V_VIEW_HI;
    float_precision = FLOAT_PRECISION;
    integral_steps = INTEGRAL_STEPS;
    draw_axis = DRAW_AXIS;
    erase_plot = ERASE_PLOT;
    connect_dots = CONNECT_DOTS;

    std::cout << std::fixed;
    std::cout.precision(float_precision);
}

char* Settings::printSettings() {
    std::string temp {};

    temp += "\nh_view_lo: " + std::to_string(h_view_lo);
    temp += "\nh_view_hi: " + std::to_string(h_view_hi);
    temp += "\nv_view_lo: " + std::to_string(v_view_lo);
    temp += "\nv_view_hi: " + std::to_string(v_view_hi);
    temp += "\nfloat precision: " + std::to_string(float_precision);
    temp += "\nintegral_steps: " + std::to_string(integral_steps);
    temp += "\n";
    temp += "\nDraw Axis: ";
    temp += (draw_axis ? "ON" : "OFF");
    temp += "\nErase Plot: ";
    temp += (erase_plot ? "ON" : "OFF");
    temp += "\nConnect Dots: ";
    temp += (connect_dots ? "ON" : "OFF");
    temp += "\n\n";

    char *settings = (char *) malloc(temp.length() + 1);

    memcpy(settings, temp.data(), temp.length());

    return settings;
}

void Settings::resetSettings() {
    h_view_lo = H_VIEW_LO;
    h_view_hi = H_VIEW_HI;
    v_view_lo = V_VIEW_LO;
    v_view_hi = V_VIEW_HI;
    float_precision = FLOAT_PRECISION;
    integral_steps = INTEGRAL_STEPS;
    draw_axis = DRAW_AXIS;
    erase_plot = ERASE_PLOT;
    connect_dots = CONNECT_DOTS;
}

void Settings::setHView(float new_lo, float new_hi) {
    h_view_lo = new_lo;
    h_view_hi = new_hi;
}

void Settings::setVView(float new_lo, float new_hi) {
    v_view_lo = new_lo;
    v_view_hi = new_hi;
}

void Settings::setAxis(bool value) {
    draw_axis = value;
}

void Settings::setErasePlot(bool value) {
    erase_plot = value;
}

void Settings::setIntegralSteps(int steps) {
    integral_steps = steps;
}

void Settings::setFloatPrecision(int precision) {
    float_precision = precision;
}

void Settings::setConnectDots(bool value) {
    connect_dots = value;
}
