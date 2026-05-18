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
        }
        dano -= atacado->resistencia * checarSorte(atacado);
        if (dano < 0) dano = 0;
        atacado->vida_atual -= dano;
        if (morreu(atacado)) {
            delete atacado;
            cout << atacado->nome << " morreu!" << endl;
        }
        
    }
}