#pragma once
#include "funcoes-fichas.h"
#include <vector>

vector<Ficha*> retornarFichas();
void deletarFichas(vector<Ficha*>& party);
vector<Ficha*> criarPartyTeste();
