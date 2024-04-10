#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unistd.h>
#include "algorithm.hpp"
#include "ui.hpp"

int main() {

    while (true) {
        std::locale::global(std::locale(""));
        std::string line;
        std::cout << "Digite os valores separados por espaço: ";
        std::getline(std::cin, line);

        std::stringstream ss(line);

        std::vector<double> valores;

        double valor;

        while (ss >> valor) {
            valores.push_back(valor);

            if (ss.peek() == ' ') {
                ss.ignore();
            }
        }

        char tipoDados;
        std::cout << "Os dados sao amostrais (a) ou populacionais (p)? (a/p): ";
        std::cin >> tipoDados;
        std::cin.ignore();

        if (tipoDados != 'a' && tipoDados != 'A' && tipoDados != 'p' && tipoDados != 'P') {
            std::cerr << "Opcao invalida!" << std::endl;
            continue;
        }

        display(valores, tipoDados);

        char op = mainLoop();

        if (op == 'n' || op == 'N') {
            std::cout << "Encerrando..." << std::endl;
            sleep(1);
            break;
        }
    }

    return 0;
}