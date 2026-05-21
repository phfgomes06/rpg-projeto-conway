#include "funcoes-fichas.h"
#include "structs.h"
#include "main-fichas.h"
#include <execution>
#include <vector>

vector<Ficha*> retornarFichas() {
    vector<Ficha*> party;
    int input;
    bool loop { true };
    Ficha* atual;
    while (loop) {
        resumoFichas();
        opcoesFichas();
        cin >> input;
        switch (input) {
            case 1:
                party.push_back(criarFicha());
                atual = party[party.size() - 1];
                escolherNome(atual);
                escolherClasse(atual);
                distribuirPontos(atual);
                break;
            case 2:
                deletarFicha(party);
                break;
            case 3:
                cout << party.size() << " fichas encontradas" << endl;
                for (Ficha* f : party) {
                    cout << "" << endl;
                    exibirFicha(f);
                }
                break;
            case 4:
                break;
            default:
                break;
        }
    }


    return party;
}

void deletarFichas(vector<Ficha*> party) {
    if (!party.empty()) {
        for (Ficha* f : party) delete f;
    }
}

// PARA DEBUG

vector<Ficha*> criarPartyTeste() {
    Ficha* f1 = new Ficha();
    Ficha* f2 = new Ficha();
    Ficha* f3 = new Ficha();
    Ficha* f4 = new Ficha();

    f1->nome = "Flinstons";
    f1->classe = tacapeiro;
    f1->arma = tacape;
    f1->forca = 4;
    f1->inteligencia = 2;
    f1->agilidade = 1;
    f1->resistencia = 3;
    f1->espirito = 2;
    f1->restantes = 0;

    f2->nome = "Bananilson Farofa";
    f2->classe = arqueiro;
    f2->arma = arco;
    f2->forca = 3;
    f2->inteligencia = 3;
    f2->agilidade = 2;
    f2->resistencia = 3;
    f2->espirito = 1;
    f2->restantes = 0;

    f3->nome = "Spirogyra";
    f3->classe = mateiro;
    f3->arma = facas;
    f3->forca = 2;
    f3->inteligencia = 2;
    f3->agilidade = 4;
    f3->resistencia = 2;
    f3->espirito = 2;
    f3->restantes = 0;

    f4->nome = "Krugsberg";
    f4->classe = paje;
    f4->arma = maraca;
    f4->forca = 1;
    f4->inteligencia = 4;
    f4->agilidade = 2;
    f4->resistencia = 1;
    f4->espirito = 4;
    f4->restantes = 0;

    vector<Ficha*> party = {f1, f2, f3, f4};

    for (Ficha* f : party) {
        f->vida_max = 15 + 4 * f->resistencia + 2 * f->forca;
        f->vida_atual = f->vida_max;
    }

    return party;
}
