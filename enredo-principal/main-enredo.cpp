#include "dialogos.h"
#include <type_traits>
#include <vector>
#include "main-enredo.h"

void comecarJogo(vector<Ficha*> party) {
    int input;
    lore::inicio();
    input = exibirOpcoes("O que vocês fazem?", {"Investigar os arbustos", "Ignorar"});
    if (input == 1) {
        lore::investigarArbusto(party);
    } else {
        lore::ignorar(party);
    }
    lore::depoisLutaOncas(party);
    input = lore::travessia(party);
    if (input == 1) {
        lore::caminhoEsquerda(party);
    } else {
        lore::caminhoDireita(party);
    }
}

