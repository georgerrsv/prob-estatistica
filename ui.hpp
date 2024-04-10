#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <unistd.h>
#include "algorithm.hpp"

char mainLoop() {
    std::cout << "Deseja realizar outra operacao? (s/n): ";
    char op;
    std::cin >> op;
    std::cin.ignore();
    return op;
}

void display(const std::vector<double>& valores, char tipoDados) {
    std::cout << "Calculando para dados " << (tipoDados == 'a' || tipoDados == 'A' ? "amostrais..." : "populacionais...") << std::endl;

    std::cout << "Valores do vetor: [";
    for (size_t i = 0; i < valores.size(); i++) {
        std::cout << valores[i];
        if (i != valores.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;

    double soma = calcSoma(valores);
    double media = calcMedia(valores);
    double mediana = calcMediana(valores);
    double moda = calcModa(valores);
    double variancia = (tipoDados == 'a' || tipoDados == 'A' ? calcVarianciaAmostral(valores) : calcVariancia(valores));
    double desvioPadrao = std::sqrt(variancia);

    std::vector<double> desvios = calcDesvio(valores);
    
    std::cout << "Soma do vetor: " << std::fixed << std::setprecision(2) << soma << std::endl;
    std::cout << "Média: " << std::fixed << std::setprecision(2) << media << std::endl;
    std::cout << "Mediana: " << std::fixed << std::setprecision(2) << mediana << std::endl;
    std::cout << "Moda: " << std::fixed << std::setprecision(2) << moda << std::endl;
    std::cout << "Variância: " << std::fixed << std::setprecision(2) << variancia << std::endl;
    std::cout << "Desvio Padrão: " << std::fixed << std::setprecision(2) << desvioPadrao << std::endl;

    std::cout << "|----------------------------------|" << std::endl;
    std::cout << "|" << std::setw(10) << "Desvio" << std::setw(5) << "|" << std::setw(15) << "Variância" << std::setw(6) << "|" << std::endl;
    for (size_t i = 0; i < valores.size(); i++) {
        std::cout << "|" << std::setw(9) << desvios[i] << std::setw(6) << "|" << std::setw(12) << std::pow(desvios[i], 2) << std::setw(8) << "|" << std::endl;
    }
    std::cout << "|----------------------------------|" << std::endl;

    std::vector<double> copiaValores = valores;
    std::sort(copiaValores.begin(), copiaValores.end());

    std::cout << "Vetor ordenado: [";
    for (size_t i = 0; i < copiaValores.size(); i++) {
        std::cout << copiaValores[i];
        if (i != copiaValores.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;
}

#endif