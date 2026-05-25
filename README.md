# Tembia

Esse jogo foi feito para o projeto final do curso de introdução a C++ da CONWAY-USP.

Ele se trata de um jogo de RPG de texto, onde as informações são todas enviadas e recebidas pelo terminal do computador.
O jogo se passa em uma aldeia indígena e trata sobre a guerra entre 2 aldeias.
O jogo tem duração média de 10 a 15 minutos e é dividido em 4 capítulos. O jogo possui vários caminhos e escolhas que o jogador deve fazer durante a aventura e 2 finais diferentes.

## Criação de personagem

Para a criação do personagem, o jogo solicita esses critérios:
* Nome do personagem
* Classe:
  * **Tacapeiro**
  * **Arqueiro**
  * **Mateiro**
  * **Pajé**
* Arma (automaticamente associada à classe):
  * **Tacape** - dano: 3 * força + 1d10
  * **Arco** - dano: força + inteligencia + 2d6
  * **Facas de osso** - dano: agilidade + 4d4
  * **Maracás** - dano: inteligencia + 2d4 | cura: inteligencia + espírito + 1d8
* Atributos (7 pontos para distribuir entre eles, sendo que cada um precisa de 1 no mínimo):
  * **Força**
  * **Inteligência**
  * **Agilidade**
  * **Resistência**
  * **Espírito** (altera em algumas coisas que demandam sorte, quanto maior, mais sorte)

## Guia de Uso
Para compilar, basta digitar: `make`.
Com isso, automaticamente um arquivo "rpg" será criado.
Para jogar, basta digitar `./rpg`.
E para deletar, pode se usar `clean`.


## Notas
Quando eu terminei o curso e comecei a trabalhar no jogo, a parte do curso sobre Orientação a Objeto não existia ainda, entao eu comecei a fazer sem o uso de classes. Depois que inseriram as aulas sobre classes, apesar de ter visto as aulas, eu quis continuar o jogo com essa filosofia de não usar classes como uma espécie de desafio para expandir minha visão.

*Me arrependi muito disso, foi muito complicado trabalhar com structs e ponteiros KASDJAKKDAJDS*

Além disso, tentei ao máximo explorar todos os conceitos abordados no curso.

Esse projeto não tem o menor objetivo de lucrar ou se restringir a minha autoria. Sinta-se livre para modificar, explorar e se divertir :)
