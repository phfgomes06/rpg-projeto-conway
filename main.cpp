#include "construtor-fichas/main-fichas.h"
#include "enredo-principal/main-enredo.h"
#include "funcoes-luta.h"
#include "inimigos.h"
using namespace std;

int main() {
    // vector<Ficha*> fichas = retornarFichas();
    vector<Ficha*> party = criarPartyTeste();
    vector<Ficha*> inimigos = {inimigo::onca(), inimigo::onca(), inimigo::onca()};
    luta::iniciar(party, inimigos);
    // comecarJogo();
    deletarFichas(party);
    deletarFichas(inimigos);
}
