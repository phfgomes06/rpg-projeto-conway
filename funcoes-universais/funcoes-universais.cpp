#include <iostream>
#include <string>
#include <random>
#include "../construtor-fichas/structs.h"
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

int exibirOpcoes(string pergunta, vector<string> opcoes) {
    int input;
    int i;

    do {
        input = 0;
        cout << pergunta << endl;
        for (i = 1; i <= opcoes.size(); ++i) {
            cout << i  << ". " << opcoes[i - 1] << endl;
        }
        cin >> input;
    } while (input < 1 || input > opcoes.size());

    return input;
}

void confirmPrint(string conteudo) {
    cout << conteudo << endl;
    cin.get();
}

bool checarSorte(Ficha* personagem) {
    int odd = rolarDado(10);
    if (odd <= personagem->espirito) {
        return true;
    }
    return false;
}

int escolherPersonagemIndex(vector<Ficha*>& party, string acao) {
    vector<string> nomes = {};
    int input;
    string pergunta_completa = "Escolha um personagem para " + acao;

    for(Ficha* f : party) {
        if (f) {
            nomes.push_back(f->nome);
        }
    }
    input = exibirOpcoes(pergunta_completa, nomes);

    return (input - 1);
}

bool realizarTeste(Ficha* p, atributos atr, int dt) {
    int valor_atr;
    string nome_atr;
    string dado;
    int val_dado;
    int resultado;
    int digitos;
    switch (atr) {
        case forca:
            valor_atr = p->forca;
            nome_atr = "força";
            break;
        case inteligencia:
            valor_atr = p->inteligencia;
            nome_atr = "inteligência";
            break;
        case agilidade:
            valor_atr = p->agilidade;
            nome_atr = "agilidade";
            break;
        case resistencia:
            valor_atr = p->resistencia;
            nome_atr = "resistência";
            break;
        case espirito:
            valor_atr = p->espirito;
            nome_atr = "espírito";
            break;
        default:
            nome_atr = " ";
            valor_atr = 0;
            break;
    }

    cout << "Teste de " << nome_atr << endl;
    confirmPrint("Pressione Enter para rolar o dado:");
    cin.get();
    val_dado = rolarDado(20);
    if (val_dado < 10) digitos = 1;
    else digitos = 2;

    dado = "======" + string(digitos, '=') + '\n' + "|| " + string(digitos, ' ') + " ||\n" + "|| " + to_string(val_dado) + " ||\n" + "|| " + string(digitos, ' ') + " ||\n" + "======" + string(digitos, '=') + '\n';

    confirmPrint(dado);
    espaco(1);
    resultado = val_dado + valor_atr;
    cout << "Resultado final: " << val_dado << " + " << valor_atr << "(" << nome_atr << ") = " << resultado << endl;

    if (resultado >= dt) {
        confirmPrint("O resultado passa no teste!");
        return true;
    } else {
        confirmPrint("O resultado não passa no teste.");
        return false;
    }
}

Ficha* personagemAleatorio(vector<Ficha*>& party) {
    return party[rolarDado(party.size()) - 1];
}

void falar(Ficha* personagem,string fala) {
    cout << "> " << personagem->nome << ": " << fala << endl;
    cin.get();
}