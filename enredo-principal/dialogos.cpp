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
            cout << escolhido->nome << " curou 10 pontos de vida!" << endl;
            cin.get();
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

    int travessia(vector<Ficha*> party) {
        int input;
        imprimirTitulo("CAPÍTULO 2 - Longe de Qualquer Estrada", 4, '~');
        cin.get();
        confirmPrint("Vocês começam então a travessia pela floresta.");
        confirmPrint("A floresta é escura, densa e silenciosa, apenas com barulhos de alguns animais noturnos.");
        confirmPrint("Mesmo se fosse de dia, as copas das árvores são fechadas demais para permitir qualquer passagem de luz.");
        confirmPrint("Depois de alguns minutos caminhando, o grupo se depara com 2 caminhos diferentes para seguir.");
        confirmPrint("MEMÓRIA: O caminho da esquerda já é conhecido pela aldeia como uma rota que pode conter caçadores perigosos de outras aldeias vizinhas.");
        confirmPrint("MEMÓRIA: O caminho da direita é conhecido como uma área de cruzamento de animais perigosos.");
        return exibirOpcoes("Para qual caminho vocês vão?", {"Esquerda", "Direita"});
    }

    void caminhoEsquerda(vector<Ficha*> party) {
        vector<Ficha*> cacadores = {};
        int falhas;
        int index;
        Ficha* escolhido;

        confirmPrint("Vocês seguem pelo caminho da esquerda.");
        confirmPrint("Conforme vão caminhando silenciosamente pela rota, vocês acabam ouvindo vozes.");
        confirmPrint("Vocês precisam agora tomar muito mais cuidado e serem mais silenciosos.");
        confirmPrint("De repente, vocês percebem que estão passando do lado dos caçadores.");
        confirmPrint("Todos precisam testar sua agilidade para ver se conseguem passar rapida e silenciosamente.");
        for (Ficha* f : party) {
            if (!realizarTeste(f, agilidade, 15)) {
                falhas++;
                cout << f->nome << "acabou pisando em um galho e alertou 1 inimigo!" << endl;
                cin.get();
            } else {
                cout << f->nome << "conseguiu passar furtivamente" << endl;
                cin.get();
            }
        }
        if (falhas != 0) {
            for (int i = 0; i < falhas; i++) {
                if (rolarDado(2) == 1) {
                    cacadores.push_back(inimigo::cacador_arqueiro());
                } else {
                    cacadores.push_back(inimigo::cacador_mateiro());
                }
            }
            cout << falhas << " caçadores notaram a presença de vocês" << endl;
            cin.get();
            luta::iniciar(party, cacadores);
            confirmPrint("Ao saquear os corpos, vocês encontram 2 poções de cura!");
            for (int i = 0; i < 2; i ++) {
                index = escolherPersonagemIndex(party, "beber a poção de cura");
                escolhido = party[index];
                escolhido->vida_atual += 10;
                if (escolhido->vida_atual > escolhido->vida_max) escolhido->vida_atual = escolhido->vida_max;
                cout << escolhido->nome << " curou 10 pontos de vida!" << endl;
                cin.get();
            }
        } else {
            confirmPrint("Todos conseguiram passar furtivamente e sem alertar os caçadores!");
        }
    }

    void caminhoDireita(vector<Ficha*> party) {
        vector<Ficha*> animais = {inimigo::jacare_acu(), inimigo::sucuri_verde()};

    }


}
