#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>

class Settings {
    public:
        Settings();

        /**
         * Mostra o conteúdo das variáveis internas do programa
        */
        char* printSettings();

        /**
         * Restaura os valores padrão das variáveis internas do programa
        */
        void resetSettings();

        /**
         * Seta os parâmetros de visualização horizontal do eixo X para a geração de 
         * gráficos de funções
        */
        void setHView(float new_lo, float new_hi);

        /**
         * Seta os parâmetros de visualização horizontal do eixo Y para a geração de 
         * gráficos de funções
        */
        void setVView(float new_lo, float new_hi);

        /**
         * Faz com que os eixos X e Y sejam desenhados ao se plotar um gráfico de função
        */
        void setAxis(bool value);

        /**
         * Faz com ao se plotar um novo gráfico o anterior não seja apagado, se 
         * constituindo em uma forma de se visualizar mais de uma função ao mesmo tempo
        */
        void setErasePlot(bool value);

        /**
        * Ajusta a quantidade de passos a serem utilizados ao se calcular o valor 
        * numérico de uma integral utilizando-se a Soma de Riemann
        */
        void setIntegralSteps(int steps);

        /**
        * Ajusta a quantidade de casas decimais que são impressas em valores em ponto 
        * flutuante. 
        * Os valores válidos são inteiros que vão de 0 até 8
        */
        void setFloatPrecision(int precision);

        /**
        * A variável interna Connect Dots se refere a plotagem de gráficos. 
        * Quando um gráfico é plotado, é necessário ligar cada dois “pixels” consecutivos 
        * por uma reta, caso contrário o gráfico pode se apresentar com regiões 
        * descontínuas. 
        * Essa variável interna determina se essa ligação através de retas é realizada ou 
        * não. 
        * Em geral, se utiliza o Algorito de Bresenham para se traçar tais retas.
        */
        void setConnectDots(bool value);

    private:
        float h_view_lo;
        float h_view_hi;
        float v_view_lo;
        float v_view_hi;
        int float_precision;
        int integral_steps;
        bool draw_axis;
        bool erase_plot;
        bool connect_dots;
};

#endif