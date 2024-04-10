#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>


double calcSoma(const std::vector<double>& values) {
    double sum = 0;
    for (double val : values) {
        sum += val;
    }
    return sum;
}

double calcMedia(const std::vector<double>& values) {
    double sum = 0;
    for (double val : values) {
        sum += val;
    }
    return sum / values.size();
}

double calcMediana(const std::vector<double>& values) {
    std::vector<double> copy = values;
    std::sort(copy.begin(), copy.end());
    if (copy.size() % 2 == 0) {
        size_t mid = copy.size() / 2;
        return (copy[mid - 1] + copy[mid]) / 2.0;
    } else
        return copy[copy.size() / 2];
}

double calcModa(const std::vector<double>& values) {
    std::unordered_map<double, int> count;
    for (double val : values) {
        count[val]++;
    }
    int maxFreq = 0;
    double moda = 0;
    std::vector<double> v;

    for (const auto& pair : count) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            moda = pair.first;
            v.clear();
            v.push_back(moda);
        }
        else if (pair.second == maxFreq) {
            v.push_back(pair.first);
        }
    }
    moda = *std::max_element(v.begin(), v.end());

    return moda;
}

std::vector<double> calcDesvio(const std::vector<double>& values) {
    double media = calcMedia(values);
    std::vector<double> desvios;
    desvios.reserve(values.size());
    for (double val : values) {
        desvios.push_back(val - media);
    }
    return desvios;
}

double calcVariancia(const std::vector<double>& values) {
    double media = calcMedia(values);
    double soma = 0;
    for (double val : values) {
        soma += std::pow(val - media, 2);
    }
    return soma / values.size();
}

double calcVarianciaAmostral(const std::vector<double>& values) {
    double media = calcMedia(values);
    double soma = 0;
    for (double val : values) {
        soma += std::pow(val - media, 2);
    }
    return soma / (values.size() - 1);
}

double calcDesvioPadrao(const std::vector<double>& values) {
    return std::sqrt(calcVariancia(values));
}

#endif