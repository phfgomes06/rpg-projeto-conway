#pragma once
#include <iostream>
#include <string>
#include <random>
#include <thread>
#include <chrono>
#include "construtor-fichas/structs.h"
using namespace std::chrono_literals;
using namespace std;

void espaco(int tamanho = 2);
void imprimirPorcentagem(string titulo, int completado, int total, char char_completado = '#', char char_vazio = '-', string apos = "", bool mostrar_valores = true);
void imprimirTitulo(string titulo, int espacamento_lateral = 4, char decoracao = '=');
int rolarDado(int lados);
int exibirOpcoes(string pergunta, vector<string> opcoes);
void confirmPrint(string conteudo);
bool checarSorte(Ficha* personagem);
int escolherPersonagemIndex(vector<Ficha*>& party, string acao);
bool realizarTeste(Ficha* p, atributos atr, int dt);
Ficha* personagemAleatorio(vector<Ficha*>& party);
void falar(Ficha* personagem,string fala);
