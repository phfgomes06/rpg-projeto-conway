#include "../funcoes-universais.h"
#include "dialogos.h"
#include "../funcoes-luta.h"
#include "../inimigos.h"
#include <oneapi/tbb/info.h>

namespace lore {
    void inicio() {
        imprimirTitulo("CAPÍTULO 1 - Sem Estrelas", 4, '~');
        cin.get();
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
        } else {
            confirmPrint("Vocês se deparam com 3 onças enormes e famintas!!!");
            cout << escolhido->nome << " foi lento e uma das onças conseguiu lhe morder!" << endl;
            cin.get();
            cout << escolhido->nome << " perdeu 10 pontos de vida" << endl;
            cin.get();
            escolhido->vida_atual -= 10;
        }
        luta::iniciar(party, oncas);
    }

    void ignorar(vector<Ficha*> party) {
        vector<Ficha*> oncas = {inimigo::onca(),inimigo::onca(),inimigo::onca()};
        confirmPrint("Vocês decidem então se manter longe daquele arbusto misterioso");
        confirmPrint("Vocês voltam para a oca e tentam dormir.");
        confirmPrint("Quando vocês estão prestes a dormir, vocês escutam barulhos de passos vindo de fora.");
        confirmPrint("Os passos são pesados e rápidos e vão ficando cada vez mais alto.");
        confirmPrint("De repente, 3 onças enormes invadem a oca!");
        for (Ficha* p : party) {
            luta::atacar(inimigo::onca(), p);
        }
        luta::iniciar(party, oncas);
        confirmPrint("Depois da luta contra as onças, vocês decidem se aproximar do arbusto de onde elas vieram");
    }

    void depoisLutaOncas(vector<Ficha*> party) {
        int index;
        Ficha* escolhido;
        confirmPrint("Vocês olham por detrás do arbusto de onde elas vieram");
        confirmPrint("Mas apenas um de vocês nota uma coisa estranha");
        index = escolherPersonagemIndex(party, "teste de inteligência");
        escolhido = party[index];
        if (realizarTeste(escolhido, inteligencia, 12)) {
            cout << escolhido->nome << " encontrou um corpo devorado pelas onças." << endl;
            cin.get();
            confirmPrint("O corpo continha um frasco pequeno vermelho que sobreviveu ao ataque das onças.");
            confirmPrint("O frasco é uma poção de cura!");
            index = escolherPersonagemIndex(party, "beber a poção de cura");
            escolhido = party[index];
            escolhido->vida_atual += 10;
            if (escolhido->vida_atual > escolhido->vida_max) escolhido->vida_atual = escolhido->vida_max;
            cout << escolhido->nome << " curou 10 pontos de vida!";
        } else {
            cout << escolhido->nome << " encontrou um corpo devorado pelas onças." << endl;
            cin.get();
        }
        confirmPrint("Você nota que o corpo pertence na verdade a uma aldeia rival. Os Hovaigua.");
        confirmPrint("MEMÓRIA: Os Hovaigua possuem uma extensa rivalidade com o seu povo.");
        confirmPrint("MEMÓRIA: Inúmeras guerras e tentativas de conquista ocorreram entre vocês ao longo de mais de 700 anos.");
        confirmPrint("LÓGICA: Aquele homem devorado provavelmente estava de tocaia observando a aldeia.");
        confirmPrint("LÓGICA: Os Hovaigua provavelmente têm algum plano de conquista em mente!");
        confirmPrint("LÓGICA: Nós precisamos contra-atacar eles essa noite e acabar com essa história de uma vez por todas!");
        confirmPrint("Olhando ao fundo, entre as árvores, você se lembra que a aldeia Hovaigua fica logo átras da floresta, a poucos km dali.");
        confirmPrint("Vocês decidem então, seguir rumo até a aldeia Hovaigua.");
    }
}
