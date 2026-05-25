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
    mordida_cobra,
    tacape_dentado,
    arco_afiado,
    facas_serrilhadas,
    maraca_pintada,
    lanca_hovaigua,
    tacapaco,
    arco_triplo,
    facas_2_gumes,
    grimorio,
    poderes_natureza
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