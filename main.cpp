#include "construtor-fichas/main-fichas.h"
#include "enredo-principal/main-enredo.h"
using namespace std;

int main() {
    vector<Ficha*> fichas = retornarFichas();
    deletarFichas(fichas);
}