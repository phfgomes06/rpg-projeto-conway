#include "construtor-fichas/main-fichas.h"
#include "enredo-principal/main-enredo.h"
#include "funcoes-luta.h"
#include "inimigos.h"
using namespace std;

int main() {
    // vector<Ficha*> fichas = retornarFichas();
    vector<Ficha*> party = criarPartyTeste();
    comecarJogo(party);
    deletarFichas(party);
}
