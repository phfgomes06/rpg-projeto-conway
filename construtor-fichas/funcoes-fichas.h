#pragma once
#include <iostream>
#include <string>
#include "structs.h"
#include <vector>
#include "../funcoes-universais/funcoes-universais.h"
using namespace std;

void resumoFichas();
void opcoesFichas();
void deletarFicha(vector<Ficha*>& party);
Ficha* criarFicha();
void escolherNome(Ficha* ficha);
void escolherClasse(Ficha* ficha);
int mudarPontosDoAtributo(int atributo, int restantes, string nome_atributo);
void distribuirPontos(Ficha* ficha);
void exibirFicha(Ficha* ficha);
string nomeDaArma(Ficha* p);

