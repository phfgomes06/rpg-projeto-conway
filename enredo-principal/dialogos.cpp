#include "../funcoes-universais.h"
#include "dialogos.h"
#include "../funcoes-luta.h"
#include "../inimigos.h"

namespace lore {
    void inicio() {
        confirmPrint("É madrugada.");
        confirmPrint("Todos da aldeia estão dormindo.");
        confirmPrint("Vocês tiveram um mau pressentimento quando foram dormir.");
        confirmPrint("O medo de não estarem sozinhos atormenta vocês profundamente.");
        confirmPrint("E então, de repente...");
        confirmPrint("Vocês ouvem os arbustos farfalhando, cortando o silêncio da madrugada.");
    }

    void investigarArbusto(vector<Ficha *> party) {
        int index;
        Ficha* escolhido;
        vector<Ficha*> oncas = {inimigo::onca(),inimigo::onca(),inimigo::onca()};
        confirmPrint("Vocês se aproximam do arbusto...");
        cin.get();
        confirmPrint("Está muito escuro...");
        confirmPrint("Alguém precisa ir na frente para abrir o arbusto.");
        index = escolherPersonagemIndex(party, "teste de Agilidade");
        escolhido = party[index];
        if (realizarTeste(escolhido, agilidade, 12)) {
            confirmPrint("Vocês se deparam com 3 onças enormes e famintas!!!");
            cout << "Por sorte, " << escolhido->nome << " foi mais rápido e desviou do ataque de uma!" << endl;
            cin.get();
            luta::iniciar(party, oncas);
        } else {
            confirmPrint("Vocês se deparam com 3 onças enormes e famintas!!!");
            cout << escolhido->nome << " foi lento e uma das onças conseguiu lhe morder!" << endl;
            cin.get();
            cout << escolhido->nome << " perdeu 10 pontos de vida" << endl;
            cin.get();
            escolhido->vida_atual -= 10;
            luta::iniciar(party, oncas);
        }
    }
}
