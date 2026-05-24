#include "construtor-fichas/structs.h"
using namespace std;

namespace inimigo {
    Ficha* onca() {
        Ficha* f = new Ficha();
        f->nome = "Onça";
        f->classe = nenhuma_classe;
        f->arma = garra;
        f->vida_max = 20;
        f->vida_atual = 20;
        f->forca = 3;
        f->inteligencia = 1;
        f->agilidade = 1;
        f->resistencia = 2;
        f->espirito = 1;
        f->restantes = 0;
        return f;
    }

    Ficha* cacador_arqueiro() {
        Ficha* f = new Ficha();
        f->nome = "Caçador Arqueiro";
        f->classe = arqueiro;
        f->arma = arco;
        f->vida_max = 15;
        f->vida_atual = 15;
        f->forca = 4;
        f->inteligencia = 3;
        f->agilidade = 1;
        f->resistencia = 1;
        f->espirito = 1;
        f->restantes = 0;
        return f;
    }

    Ficha* cacador_mateiro() {
        Ficha* f = new Ficha();
        f->nome = "Caçador Mateiro";
        f->classe = mateiro;
        f->arma = facas;
        f->vida_max = 18;
        f->vida_atual = 18;
        f->forca = 3;
        f->inteligencia = 1;
        f->agilidade = 3;
        f->resistencia = 2;
        f->espirito = 1;
        f->restantes = 0;
        return f;
    }

    Ficha* jacare_acu() {
        Ficha* f = new Ficha();
        f->nome = "Jacaré-açu";
        f->classe = nenhuma_classe;
        f->arma = mordida_jacare;
        f->vida_max = 35;
        f->vida_atual = 35;
        f->forca = 5;
        f->inteligencia = 1;
        f->agilidade = 1;
        f->resistencia = 2;
        f->espirito = 1;
        f->restantes = 0;
        return f;
    }

    Ficha* sucuri_verde() {
        Ficha* f = new Ficha();
        f->nome = "Sucuri Verde";
        f->classe = nenhuma_classe;
        f->arma = mordida_jacare;
        f->vida_max = 16;
        f->vida_atual = 16;
        f->forca = 3;
        f->inteligencia = 1;
        f->agilidade = 3;
        f->resistencia = 3;
        f->espirito = 4;
        f->restantes = 0;
        return f;
    }
    
}
