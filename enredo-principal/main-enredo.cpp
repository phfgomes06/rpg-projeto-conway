#include "dialogos.h"
#include <vector>
#include "main-enredo.h"

void comecarJogo(vector<Ficha*> party) {
    int input;
    lore::inicio();
    input = exibirOpcoes("O que vocês fazem?", {"Investigar os arbustos", "Ignorar"});
    if (input == 1) {
        lore::investigarArbusto(party);
    }
}

