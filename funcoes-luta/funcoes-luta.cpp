#include "../construtor-fichas/funcoes-fichas.h"
#include "../funcoes-universais/funcoes-universais.h"
#include "../construtor-fichas/structs.h"
#include <cstdlib>

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
                dano = atacante->agilidade * rolarDado(3) + atacante->forca;
                break;
            case maraca:
                dano = atacante->inteligencia + 2 * rolarDado(4);
                break;
            case garra:
                dano = atacante->forca + rolarDado(4);
                break;
            case mordida_jacare:
                dano = atacante->forca + rolarDado(6);
                break;
            case mordida_cobra:
                dano = atacante->forca + agilidade * rolarDado(2);
                break;
            case tacape_dentado:
                dano = 3 * atacante->forca + rolarDado(20);
                break;
            case arco_afiado:
                dano = atacante->forca * atacante->inteligencia + 2 * rolarDado(8);
                break;
            case facas_serrilhadas:
                dano = atacante->agilidade * rolarDado(4) + 2 * atacante->forca;
                break;
            case maraca_pintada:
                dano = atacante->inteligencia + atacante->espirito + 2 * rolarDado(8);
                break;
            case lanca_hovaigua:
                dano = atacante->forca + rolarDado(8);
                break;
            case tacapaco:
                dano = 4 * atacante->forca + rolarDado(20) + rolarDado(20);
                break;
            case arco_triplo:
                dano = atacante->forca + atacante->inteligencia + 3 * rolarDado(10);
                break;
            case facas_2_gumes:
                dano = (atacante->agilidade + 2) * (rolarDado(6) + atacante->forca);
                break;
            case grimorio:
                dano = 3 * atacante->inteligencia + 3 * rolarDado(8);
                break;
            case poderes_natureza:
                dano = atacante->inteligencia + rolarDado(12);
                break;
        }
        dano -= atacado->resistencia * checarSorte(atacado);
        if (dano < 0) dano = 0;
        atacado->vida_atual -= dano;
        espaco(1);
        cout << atacante->nome << " causou " << dano << " de dano a " << atacado->nome << "!" << endl;
        cin.get();
    }

    void status(vector<Ficha*>& party, vector<Ficha*>& inimigos, int ordem_party, int ordem_inimigos, bool vez_da_party) {
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

    int escolherInimigoIndex(Ficha* char_atual, vector<Ficha*>& inimigos) {
        vector<string> nomes = {};
        int input;

        for(Ficha* f : inimigos) {
            nomes.push_back(f->nome);
        }
        cout << "Qual inimigo " << char_atual->nome << " atacará?";
        input = exibirOpcoes("", nomes);

        return (input - 1);
    }

    bool pajeVaiCurar() {
        int input;
        input = exibirOpcoes("Deseja curar ou atacar?", {"Curar", "Atacar"});
        if (input == 1) return true;
        else return false;
    }

    int pajeEscolherAliado(Ficha* paje, vector<Ficha*>& party) {
        vector<string> nomes = {};
        int input;

        for(Ficha* f : party) {
            nomes.push_back(f->nome);
        }
        cout << "Qual aliado " << paje->nome << " curará?";
        input = exibirOpcoes("", nomes);

        return (input - 1);
    }

    void pajeCurarAliado(Ficha* paje, Ficha* alvo) {
        int cura;
        if (paje->arma == maraca) {
            cura = paje->inteligencia + paje->espirito + rolarDado(8);
        } else if (paje->arma == maraca_pintada) {
            cura = 2 * paje->inteligencia + paje->espirito + rolarDado(12);
        } else if (paje->arma == grimorio) {
            cura = 3 * paje->inteligencia + 2 * paje->espirito + rolarDado(12);
        }
        alvo->vida_atual += cura;
        if (alvo->vida_atual > alvo->vida_max) {
            alvo->vida_atual = alvo->vida_max;
        }
        espaco(1);
        cout << alvo->nome << " curou " << cura << " pontos de vida!" << endl;
        espaco(1);
        cin.get();
    }

    void iniciar(vector<Ficha*>& party, vector<Ficha*>& inimigos) {
        int ordem_party = 0;
        int ordem_inimigos = 0;
        bool vez_da_party = true;
        bool paje_vai_curar = false;
        int input;
        int index_inimigo_escolhido;
        int index_aliado_escolhido;
        int index_cura_escolhido;
        Ficha* aliado_escolhido;
        Ficha* inimigo_escolhido;
        Ficha* char_atual = party[ordem_party];
        Ficha* inimigo_atual = inimigos[ordem_inimigos];
        imprimirTitulo("Luta iniciada!!");

        // loop até algum dos grupos acabar
        while(!party.empty() && !inimigos.empty()) {
            if(vez_da_party) { // turno party
                status(party, inimigos, ordem_party, ordem_inimigos, vez_da_party);
                cin.get();
                imprimirTitulo("Vez da party!");
                cin.get();
                char_atual = party[ordem_party];
                cout << ">>> " << char_atual->nome << " - " << nomeDaArma(char_atual);
                imprimirPorcentagem("", char_atual->vida_atual, char_atual->vida_max);
                cin.get();
                if (char_atual->classe == paje) {
                    paje_vai_curar = pajeVaiCurar();
                }
                espaco(1);
                if (paje_vai_curar) { // caso o pajé escolha curar
                    index_cura_escolhido = pajeEscolherAliado(char_atual, party);
                    pajeCurarAliado(char_atual, party[index_cura_escolhido]);
                } else { // caso o pajé escolha causar dano ou outro personagem
                    index_inimigo_escolhido = escolherInimigoIndex(char_atual, inimigos);
                    inimigo_escolhido = inimigos[index_inimigo_escolhido];
                    atacar(char_atual, inimigo_escolhido);
                    if (morreu(inimigo_escolhido)) {
                        if (inimigo_escolhido->arma != poderes_natureza) { // gambiarra suprema KKKKKKK
                            cout << inimigo_escolhido->nome << " morreu!" << endl;
                            inimigos.erase(inimigos.begin() + index_inimigo_escolhido);
                            delete inimigo_escolhido;
                        } else {
                            inimigo_escolhido->vida_atual = 1;
                            break;
                        }
                    }
                }
                ordem_party++;
                if (ordem_inimigos >= inimigos.size()) {
                    ordem_inimigos = 0;
                }
                espaco();
                vez_da_party = false;
                cin.get();
                paje_vai_curar = false;

            } else if (!vez_da_party && !inimigos.empty()) { // turno inimigo
                if (ordem_party >= party.size()) {
                    ordem_party = 0;
                }

                status(party, inimigos, ordem_party, ordem_inimigos, vez_da_party);
                cin.get();
                imprimirTitulo("Vez dos inimigos!");
                cin.get();

                inimigo_atual = inimigos[ordem_inimigos];
                cout << ">>> " << inimigo_atual->nome << " - " << nomeDaArma(inimigo_atual);
                imprimirPorcentagem("", inimigo_atual->vida_atual, inimigo_atual->vida_max);
                cin.get();
                espaco(1);

                int index_vetor_aliado = rolarDado(party.size()) - 1;
                aliado_escolhido = party[index_vetor_aliado];

                atacar(inimigo_atual, aliado_escolhido);

                if (morreu(aliado_escolhido)) {
                    cout << aliado_escolhido->nome << " morreu!" << endl;
                    delete aliado_escolhido;
                    party.erase(party.begin() + index_vetor_aliado);
                    if (index_vetor_aliado <= ordem_party && ordem_party > 0) {
                        ordem_party--;
                    }
                }

                ordem_inimigos++;
                if (ordem_inimigos >= inimigos.size()) {
                    ordem_inimigos = 0;
                }

                if (party.empty() || ordem_party >= party.size()) {
                    ordem_party = 0;
                }

                espaco();
                vez_da_party = true;
                cin.get();
            }
        }

        if (party.empty()) {
            imprimirTitulo("GAME OVER!!!");
            exit(0);
        }
        
        if (!inimigos.empty()) {
            if (inimigos[0]->arma == poderes_natureza) { // gambiarra suprema parte 2 KKKKKKKKKKKKKKK
                return;
            }
        }


        if (!party.empty()) {
            imprimirTitulo("Vitória!!!");
            cin.get();
        }
    }
}
