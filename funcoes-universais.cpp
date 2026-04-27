#include <iostream>
#include <string>
using namespace std;

void espaco(int tamanho = 2) {
    for (int i = 0; i < tamanho; ++i) cout << endl;
}

void imprimirPorcentagem(string titulo, int completado, int total, char char_completado = '#', char char_vazio = '-', string apos = "", bool mostrar_valores = true) {
    cout << titulo << " [" << string(completado, char_completado) << string(total - completado, char_vazio) << "] (" << completado << "/" << total << ")" << apos << endl;
}

void imprimirTitulo(string titulo, int espacamento_lateral = 4, char decoracao = '=') {
    cout << string(titulo.length() + espacamento_lateral * 2, decoracao) << endl;
    cout << string(espacamento_lateral - 1, decoracao) << " " << titulo << " " << string(espacamento_lateral - 1, decoracao) << endl;
    cout << string(titulo.length() + espacamento_lateral * 2, decoracao) << endl;
}
