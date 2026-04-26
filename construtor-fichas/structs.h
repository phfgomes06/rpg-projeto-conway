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
    maraca
}; 


struct Ficha {
    string nome;
    Classes classe;
    Armas arma;
    int forca;
    int inteligencia;
    int agilidade;
    int resistencia;
    int espirito;

};
