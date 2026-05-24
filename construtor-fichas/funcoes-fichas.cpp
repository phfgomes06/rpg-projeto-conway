#include <iostream>
#include <string>
#include "structs.h"
#include <vector>
#include "../funcoes-universais.h"
#include "funcoes-fichas.h"
using namespace std;

void resumoFichas() {
    cout << "Aqui, jogador, você pode criar fichas para sua party de personagens!!" << endl;
}

void opcoesFichas() {
    cout << "Digite o número da opção que deseja acessar:" << endl;
    cout << "1. Criar nova ficha" << endl;
    cout << "2. Remover uma ficha" << endl;
    cout << "3. Visualizar fichas criadas" << endl;
    cout << "4. Começar jornada!" << endl;
    espaco();
}

void deletarFicha(vector<Ficha*>& party) {
    int input;

    if (party.empty()) {
        cout << "Não há nenhuma ficha criada!" << endl;
        espaco();
        return;
    }

    while (true) {
        cout << "Qual ficha deseja deletar?" << endl;
        for (int i = 0; i < party.size(); ++i) {
            cout << i + 1 << ". " << party[i]->nome << endl;
        }
        cout << "0. sair" << endl;

        cin >> input;
        espaco();
        if (input > 0 && input <= party.size()) {
            delete party[input - 1];
            party.erase(party.begin() + (input - 1));
            cout << "Ficha deletada!" << endl;
            espaco();
            return;
        } else if (input == 0) {
            return;
        } else {
            cout << "Opção inválida!" << endl;
        }
    }
}

Ficha* criarFicha() {
    Ficha* ficha = new Ficha();
    ficha->nome = "Anônimo";
    ficha->classe = nenhuma_classe;
    ficha->arma = nenhuma_arma;
    ficha->forca = 1;
    ficha->inteligencia = 1;
    ficha->agilidade = 1;
    ficha->resistencia = 1;
    ficha->espirito = 1;
    ficha->restantes = 7;
    ficha->vida_max = 15 + ficha->resistencia * 4 + ficha->forca * 2;
    ficha->vida_atual = ficha->vida_max;
    return ficha;
}

void escolherNome(Ficha* ficha) {
    string nome;
    cout << "Digite o nome que você quer para o seu personagem: " << endl;
    cin >> nome;
    ficha->nome = nome;
    cout << "Nome <" << nome << "> salvo para o personagem!";
    espaco();
}

void escolherClasse(Ficha* ficha) {
    int classe;
    do {
        cout << "Escolha qual classe você quer atribuir: " << endl;
        cout << "1. Tacapeiro (dano muito alto em curto alcance) - arma: Tacape (dano: 3 * força + 1d10) " << endl;
        cout << "2. Arqueiro (dano preciso a longo alcance) - arma: Arco Longo (dano: força + inteligencia + 2d6)" << endl;
        cout << "3. Mateiro (muitas facadas de emboscada) - arma: Faca de Ossos (dano: agilidade * d3 + força)" << endl;
        cout << "4. Pajé (feitiços de cura e dano) - arma: Maracá (dano: inteligencia + 2d4 | cura: inteligencia + espirito + 1d10)" << endl;
        cin >> classe;
    } while (classe > 4 || classe < 1);
    ficha->classe = static_cast<Classes>(classe);
    ficha->arma = static_cast<Armas>(classe);
    espaco();
}

int mudarPontosDoAtributo(int atributo, int restantes, string nome_atributo) {
    int num_input;
    cout << "Em quantos pontos deseja aumentar ou diminuir(-) " << nome_atributo << "?" << endl;
    cin >> num_input;
    if (num_input <= restantes && (num_input + atributo) > 0) {
        espaco();
        return num_input;
    }
    espaco();
    return 0;
}

void distribuirPontos(Ficha* ficha) {
    int atr_input;
    int a_somar;

    while (true) {
        cout << "Você tem " << ficha->restantes << "/7 pontos restantes para distribuir entre os atributos" << endl;
        cout << "[Alerta] Cada atributo precisa ter pelo menos 1 ponto!" << endl;
        cout << "Escolha onde você quer alocar os pontos: " << endl;
        imprimirPorcentagem("1. Força        ", ficha->forca, 8);
        imprimirPorcentagem("2. Inteligência ", ficha->inteligencia, 8);
        imprimirPorcentagem("3. Agilidade    ", ficha->agilidade, 8);
        imprimirPorcentagem("4. Resistência  ", ficha->resistencia, 8);
        imprimirPorcentagem("5. Espírito     ", ficha->espirito, 8);
        cout << "0. Sair" << endl;
        cin >> atr_input;
        espaco();
        switch (atr_input) {
            case 1:
                a_somar = mudarPontosDoAtributo(ficha->forca, ficha->restantes, "sua força");
                ficha->forca += a_somar;
                ficha->restantes -= a_somar;
                break;
            case 2:
                a_somar = mudarPontosDoAtributo(ficha->inteligencia, ficha->restantes, "sua inteligência");
                ficha->inteligencia += a_somar;
                ficha->restantes -= a_somar;
                break;
            case 3:
                a_somar = mudarPontosDoAtributo(ficha->agilidade, ficha->restantes, "sua agilidade");
                ficha->agilidade += a_somar;
                ficha->restantes -= a_somar;
                break;
            case 4:
                a_somar = mudarPontosDoAtributo(ficha->resistencia, ficha->restantes, "sua resistência");
                ficha->resistencia += a_somar;
                ficha->restantes -= a_somar;
                break;
            case 5:
                a_somar = mudarPontosDoAtributo(ficha->espirito, ficha->restantes, "seu espírito");
                ficha->espirito += a_somar;
                ficha->restantes -= a_somar;
                break;
            case 0:
                ficha->vida_max = 15 + 4 * ficha->resistencia + 2 * ficha->forca;
                ficha->vida_atual = ficha->vida_max;
                return;
            default:
                break;
        }
    }
}

void exibirFicha(Ficha* ficha) {
    imprimirTitulo(ficha->nome);
    string classe;
    string arma;
    imprimirPorcentagem("-> Vida", ficha->vida_atual, ficha->vida_max);
    switch (ficha->classe) {
        case nenhuma_classe:
            classe = "Nenhuma classe definida ainda";
            arma = "Nenhuma arma definida ainda";
            break;
        case tacapeiro:
            classe = "Tacapeiro";
            arma = "Tacape (3 * força + 1d20)";
            break;
        case arqueiro:
            classe = "Arqueiro";
            arma = "Arco (força + inteligencia + 2d6)";
            break;
        case mateiro:
            classe = "Mateiro";
            arma = "Facas de ossos (agilidade + 4d4)";
            break;
        case paje:
            classe = "Pajé";
            arma = "maracás (dano: inteligencia + 2d4 | cura: inteligencia + espírito + 1d8)";
            break;
    }
    cout << "-> Classe:     " << classe << endl;
    cout << "-> Arma:       " << arma << endl;
    cout << "=============== Atributos ===============" << endl;
    cout << "-> (" << ficha->restantes << "/7) pontos restantes" << endl;
    imprimirPorcentagem("-> Força       ", ficha->forca, 8);
    imprimirPorcentagem("-> Inteligência", ficha->inteligencia, 8);
    imprimirPorcentagem("-> Agilidade   ", ficha->agilidade, 8);
    imprimirPorcentagem("-> Resistência ", ficha->resistencia, 8);
    imprimirPorcentagem("-> Espírito    ", ficha->espirito, 8);
    espaco();
}

string nomeDaArma(Ficha* p) {
    switch (p->arma) {
        case nenhuma_arma:
            return "sem arma";
        case tacape:
            return "tacape";
        case arco:
            return "arco";
        case facas:
            return "facas de osso";
        case maraca:
            return "maracás";
        case garra:
            return "garra";
        case mordida_jacare:
            return "mordida de jacaré";
        case mordida_cobra:
            return "mordida de cobra";
    }
}
