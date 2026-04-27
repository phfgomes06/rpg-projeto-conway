#include <iostream>
#include <string>
#include "structs.h"
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
}

void escolherClasse(Ficha* ficha) {
    int classe;
    do {
        cout << "Escolha qual classe você quer atribuir: " << endl;
        cout << "1. Tacapeiro (dano muito alto em curto alcance) - arma: Tacape (dano: 3 * força + 1d20) a cada 2 rodadas" << endl;
        cout << "2. Arqueiro (dano preciso a longo alcance) - arma: Arco Longo (dano: força + inteligencia + 2d6)" << endl;
        cout << "3. Mateiro (muitas facadas de emboscada) - arma: Faca de Ossos (dano: agilidade + 4d4)" << endl;
        cout << "4. Pajé (feitiços de cura e dano) - arma: Maracá (dano: inteligencia + 2d4 | cura: inteligencia + espirito + 1d10)" << endl;
        cin >> classe;
    } while (classe > 4 || classe < 1);
    ficha->classe = static_cast<Classes>(classe);
    ficha->arma = static_cast<Armas>(classe);
}

void mudarPontosDoAtributo(int atributo, int restantes, string nome_atributo) {
    int num_input;
    cout << "Em quantos pontos deseja aumentar ou diminuir(-) " << nome_atributo << "?" << endl;
    cin >> num_input;
    if (num_input <= restantes && (num_input + atributo) > 0) {
        atributo = num_input;
        restantes -= num_input;
    }
}

void distribuirPontos(Ficha* ficha, int restantes) {
    int atr_input;

    while (true) {
        cout << "Você tem " << restantes << "/7 pontos restantes para distribuir entre os atributos" << endl;
        cout << "[Alerta] Cada atributo precisa ter pelo menos 1 ponto!" << endl;
        cout << "Escolha onde você quer alocar os pontos: " << endl;
        cout << "1. Força        [" << string(ficha->forca, '#') << string(8 - ficha->forca, '-') << "]" << endl;
        cout << "2. Inteligência [" << string(ficha->inteligencia, '#') << string(8 - ficha->inteligencia, '-') << "]" << endl;
        cout << "3. Agilidade    [" << string(ficha->agilidade, '#') << string(8 - ficha->agilidade, '-') << "]" << endl;
        cout << "4. Resistência  [" << string(ficha->resistencia, '#') << string(8 - ficha->resistencia, '-') << "]" << endl;
        cout << "5. Espírito     [" << string(ficha->espirito, '#') << string(8 - ficha->espirito, '-') << "]" << endl;
        cout << "0. Sair" << endl;
        cin >> atr_input;
        switch (atr_input) {
            case 1:
                mudarPontosDoAtributo(ficha->forca, restantes, "sua força");
                break;
            case 2:
                mudarPontosDoAtributo(ficha->inteligencia, restantes, "sua inteligência");
                break;
            case 3:
                mudarPontosDoAtributo(ficha->agilidade, restantes, "sua agilidade");
                break;
            case 4:
                mudarPontosDoAtributo(ficha->resistencia, restantes, "sua resistência");
                break;
            case 5:
                mudarPontosDoAtributo(ficha->espirito, restantes, "seu espírito");
                break;
            case 0:
                return;
            default:
                break;
        }
    }
}
