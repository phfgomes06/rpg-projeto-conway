#include "funcoes-fichas.h"
#include "main-fichas.h"
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
    for (Ficha* f : party) delete f;
}