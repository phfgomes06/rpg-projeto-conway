#include "construtor-fichas/structs.h"
#include <vector>
using namespace std;

namespace inimigo {
    void onca(vector<Ficha*> inimigos) {
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
        inimigos.push_back(f);
    }
}