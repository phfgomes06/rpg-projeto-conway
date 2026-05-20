#include "funcoes-universais.h"
#include "construtor-fichas/structs.h"

namespace luta {
    bool morreu(Ficha* personagem) {
        if (personagem->vida_atual <= 0) return true;
        return false;
    }

    void atacar(Ficha* atacante, Ficha* atacado) {
        int dano = 0;
        switch (atacante->arma) {
            case nenhuma_arma:
                dano = rolarDado(4);
                break;
            case tacape:
                dano = 3 * atacante->forca + rolarDado(10);
                break;
            case arco:
                dano = atacante->forca + atacante->inteligencia + 2 * rolarDado(6);
                break;
            case facas:
                dano = atacante->agilidade + 4 * rolarDado(4);
                break;
            case maraca:
                dano = atacante->inteligencia + 2 * rolarDado(4);
                break;
            case garra:
                dano = atacante->forca + rolarDado(4);
                break;
        }
        dano -= atacado->resistencia * checarSorte(atacado);
        if (dano < 0) dano = 0;
        atacado->vida_atual -= dano;
        cout << atacante->nome << " causou " << dano << " de dano!" << endl;
        if (morreu(atacado)) {
            delete atacado;
            cout << atacado->nome << " morreu!" << endl;
        }
        espaco();
    }

    void status(vector<Ficha*> party, vector<Ficha*> inimigos, int ordem_party, int ordem_inimigos, bool vez_da_party) {
        cout << "===============================================================" << endl;
        cout << "Ordem da party:" << endl;
        espaco(1);
        for (int i = 0; i < party.size(); i++) {
            if (i == ordem_party && vez_da_party) {
                cout << ">>>" << i + 1 << ". " << party[i]->nome;
                imprimirPorcentagem("", party[i]->vida_atual, party[i]->vida_max);
            } else {
                cout << i + 1 << ". " << party[i]->nome;
                imprimirPorcentagem("", party[i]->vida_atual, party[i]->vida_max);
            }
        }
        espaco(1);
        cout << "Ordem dos inimigos" << endl;
        for (int i = 0; i < inimigos.size(); i++) {
            if (i == ordem_inimigos && !vez_da_party) {
                cout << ">>>" << i + 1 << ". " << inimigos[i]->nome;
                imprimirPorcentagem("", inimigos[i]->vida_atual, inimigos[i]->vida_max);
            } else {
                cout << i + 1 << ". " << inimigos[i]->nome;
                imprimirPorcentagem("", inimigos[i]->vida_atual, inimigos[i]->vida_max);
            }
        }
    }

    Ficha* escolherInimigo(Ficha* char_atual, vector<Ficha*> inimigos) {
        vector<string> nomes = {};
        int input;

        for(Ficha* f : inimigos) {
            nomes.push_back(f->nome);
        }
        cout << "Qual inimigo " << char_atual->nome << " atacará?";
        input = exibirOpcoes("", nomes);

        return inimigos[input - 1];
    }

    void iniciar(vector<Ficha*> party, vector<Ficha*> inimigos) {
        int ordem_party = 0;
        int ordem_inimigos = 0;
        bool vez_da_party = true;
        int input;
        Ficha* inimigo_escolhido;
        Ficha* char_atual = party[ordem_party];
        Ficha* inimigo_atual = inimigos[ordem_inimigos];
        imprimirTitulo("Luta iniciada!!");

        while(!party.empty() && !inimigos.empty()) {
            status(party, inimigos, ordem_party, ordem_inimigos, vez_da_party);
            if(vez_da_party) {
                inimigo_escolhido = escolherInimigo(char_atual, inimigos);
                atacar(char_atual, inimigo_escolhido);
            }
        }
    }
}
