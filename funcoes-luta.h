#pragma once
#include "funcoes-universais.h"

namespace luta {
    bool morreu(Ficha* personagem);
    void atacar(Ficha* atacante, Ficha* atacado);
    void status(vector<Ficha*> party, vector<Ficha*> inimigos, int ordem_party, int ordem_inimigos, bool vez_da_party);
    int escolherInimigoIndex(Ficha* char_atual, vector<Ficha*> inimigos);
    void iniciar(vector<Ficha*> party, vector<Ficha*> inimigos);
}