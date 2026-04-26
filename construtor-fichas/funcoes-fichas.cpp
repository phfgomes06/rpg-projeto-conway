#include <iostream>
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
        cout << "4. Pajé (feitiços de cura, fraqueza e força) - arma: Maracá (" << endl;
        cin >> classe;
    } while (classe > 4 || classe < 1);
    ficha->classe = static_cast<Classes>(classe);
}
