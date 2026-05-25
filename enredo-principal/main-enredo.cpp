#include "dialogos.h"
#include <vector>
#include "main-enredo.h"

void comecarJogo(vector<Ficha*>& party) {
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
    lore::juncaoCaminhos(party);
    vector<string> ocasDisponiveis = {"Esquerda", "Meio", "Direita"};
    lore::chegandoAldeia(party);
    while(true) {
        if (ocasDisponiveis[0] == "Já visitada" && ocasDisponiveis[1] == "Já visitada" && ocasDisponiveis[2] == "Já visitada") break;
        input = exibirOpcoes("Qual oca vocês desejam ir", ocasDisponiveis);
        if (input == 1 && ocasDisponiveis[0] != "Já visitada") {
                lore::ocaEsquerda(party);
                ocasDisponiveis[0] = "Já visitada";
        }
        else if (input == 2 && ocasDisponiveis[1] != "Já visitada") {
                lore::ocaMeio(party);
                ocasDisponiveis[1] = "Já visitada";
        }
        else if (input == 3 && ocasDisponiveis[2] != "Já visitada") {
                lore::ocaDireito(party);
                ocasDisponiveis[2] = "Já visitada";
        }
    }
    lore::final(party);

}
