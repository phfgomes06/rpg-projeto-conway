#pragma once
#include "../funcoes-universais.h"

namespace lore {
    void inicio();
    void investigarArbusto(vector<Ficha *> party);
    void ignorar(vector<Ficha*> party);
    void depoisLutaOncas(vector<Ficha*> party);
    int travessia(vector<Ficha*> party);
    void caminhoEsquerda(vector<Ficha*> party);
    void caminhoDireita(vector<Ficha*> party);
}
