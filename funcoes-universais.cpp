#include <iostream>
#include <string>
#include <random>
using namespace std;

void espaco(int tamanho = 2) {
    for (int i = 0; i < tamanho; ++i) cout << endl;
}

void imprimirPorcentagem(string titulo, int completado, int total, char char_completado = '#', char char_vazio = '-', string apos = "", bool mostrar_valores = true) {
    if (mostrar_valores) {
        cout << titulo << " [" << string(completado, char_completado) << string(total - completado, char_vazio) << "] (" << completado << "/" << total << ")" << apos << endl;
    } else {
        cout << titulo << " [" << string(completado, char_completado) << string(total - completado, char_vazio) << "] " << apos << endl;
    }
}

void imprimirTitulo(string titulo, int espacamento_lateral = 4, char decoracao = '=') {
    cout << string(titulo.length() + espacamento_lateral * 2, decoracao) << endl;
    cout << string(espacamento_lateral - 1, decoracao) << " " << titulo << " " << string(espacamento_lateral - 1, decoracao) << endl;
    cout << string(titulo.length() + espacamento_lateral * 2, decoracao) << endl;
}

int rolarDado(int lados) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, lados);
    return distrib(gen);
}                            // não fazia ideia de como fazer o RNG no C++ então isso foi tirado do google mesmo KKKKKKKKKKKK
