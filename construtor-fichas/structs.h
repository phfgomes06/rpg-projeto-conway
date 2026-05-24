#pragma once

#include <string>
using namespace std;

enum Classes {
    nenhuma_classe,
    tacapeiro,
    arqueiro,
    mateiro,
    paje
};

enum Armas {
    nenhuma_arma,
    tacape,
    arco,
    facas,
    maraca,
    garra,
    mordida_jacare,
    mordida_cobra
};

struct Ficha {
    string nome;
    Classes classe;
    Armas arma;
    int vida_max;
    int vida_atual;
    int forca;
    int inteligencia;
    int agilidade;
    int resistencia;
    int espirito;
    int restantes; //pontos restantes para gastar
};

enum atributos {
    forca,
    inteligencia,
    agilidade,
    resistencia,
    espirito
};