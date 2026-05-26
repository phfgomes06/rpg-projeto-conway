#include "../funcoes-universais/funcoes-universais.h"
#include "dialogos.h"
#include "../funcoes-luta/funcoes-luta.h"
#include "../inimigos/inimigos.h"
#include "../construtor-fichas/funcoes-fichas.h"
#include <oneapi/tbb/info.h>

namespace lore {
    void inicio() {
        imprimirTitulo("CAPÍTULO 1 - Sem Estrelas", 4, '~');
        cin.get();
        confirmPrint("É madrugada.");
        confirmPrint("Todos da aldeia estão dormindo.");
        confirmPrint("Vocês tiveram um mau pressentimento quando foram dormir.");
        confirmPrint("O medo de não estarem sozinhos atormenta vocês profundamente.");
        confirmPrint("E então, de repente...");
        confirmPrint("Vocês ouvem os arbustos farfalhando, cortando o silêncio da madrugada.");
    }

    void investigarArbusto(vector<Ficha *>& party) {
        int index;
        Ficha* escolhido;
        vector<Ficha*> oncas = {inimigo::onca(),inimigo::onca(),inimigo::onca()};
        confirmPrint("Vocês se aproximam do arbusto...");
        cin.get();
        confirmPrint("Está muito escuro...");
        confirmPrint("Alguém precisa ir na frente para abrir o arbusto.");
        index = escolherPersonagemIndex(party, "teste de Agilidade");
        escolhido = party[index];
        if (realizarTeste(escolhido, agilidade, 12)) {
            confirmPrint("Vocês se deparam com 3 onças enormes e famintas!!!");
            cout << "Por sorte, " << escolhido->nome << " foi mais rápido e desviou do ataque de uma!" << endl;
            cin.get();
        } else {
            confirmPrint("Vocês se deparam com 3 onças enormes e famintas!!!");
            cout << escolhido->nome << " foi lento e uma das onças conseguiu lhe morder!" << endl;
            cin.get();
            cout << escolhido->nome << " perdeu 10 pontos de vida" << endl;
            cin.get();
            escolhido->vida_atual -= 10;
        }
        luta::iniciar(party, oncas);
    }

    void ignorar(vector<Ficha*>& party) {
        vector<Ficha*> oncas = {inimigo::onca(),inimigo::onca(),inimigo::onca()};
        confirmPrint("Vocês decidem então se manter longe daquele arbusto misterioso");
        confirmPrint("Vocês voltam para a oca e tentam dormir.");
        confirmPrint("Quando vocês estão prestes a dormir, vocês escutam barulhos de passos vindo de fora.");
        confirmPrint("Os passos são pesados e rápidos e vão ficando cada vez mais alto.");
        confirmPrint("De repente, 3 onças enormes invadem a oca!");
        for (Ficha* p : party) {
            luta::atacar(inimigo::onca(), p);
        }
        luta::iniciar(party, oncas);
        confirmPrint("Depois da luta contra as onças, vocês decidem se aproximar do arbusto de onde elas vieram");
    }

    void depoisLutaOncas(vector<Ficha*>& party) {
        int index;
        Ficha* escolhido;
        confirmPrint("Vocês olham por detrás do arbusto de onde elas vieram");
        confirmPrint("Mas apenas um de vocês nota uma coisa estranha");
        index = escolherPersonagemIndex(party, "teste de inteligência");
        escolhido = party[index];
        if (realizarTeste(escolhido, inteligencia, 12)) {
            cout << escolhido->nome << " encontrou um corpo devorado pelas onças." << endl;
            cin.get();
            confirmPrint("O corpo continha um frasco pequeno vermelho que sobreviveu ao ataque das onças.");
            confirmPrint("O frasco é uma poção de cura!");
            index = escolherPersonagemIndex(party, "beber a poção de cura");
            escolhido = party[index];
            escolhido->vida_atual += 10;
            if (escolhido->vida_atual > escolhido->vida_max) escolhido->vida_atual = escolhido->vida_max;
            cout << escolhido->nome << " curou 10 pontos de vida!" << endl;
            cin.get();
        } else {
            cout << escolhido->nome << " encontrou um corpo devorado pelas onças." << endl;
            cin.get();
        }
        confirmPrint("Você nota que o corpo pertence na verdade a uma aldeia rival. Os Hovaigua.");
        confirmPrint("MEMÓRIA: Os Hovaigua possuem uma extensa rivalidade com o seu povo.");
        confirmPrint("MEMÓRIA: Inúmeras guerras e tentativas de conquista ocorreram entre vocês ao longo de mais de 700 anos.");
        confirmPrint("LÓGICA: Aquele homem devorado provavelmente estava de tocaia observando a aldeia.");
        confirmPrint("LÓGICA: Os Hovaigua provavelmente têm algum plano de conquista em mente!");
        confirmPrint("LÓGICA: Nós precisamos contra-atacar eles essa noite e acabar com essa história de uma vez por todas!");
        confirmPrint("Olhando ao fundo, entre as árvores, você se lembra que a aldeia Hovaigua fica logo átras da floresta, a poucos km dali.");
        confirmPrint("Vocês decidem então, seguir rumo até a aldeia Hovaigua.");
    }

    int travessia(vector<Ficha*>& party) {
        int input;
        imprimirTitulo("CAPÍTULO 2 - Longe de Qualquer Estrada", 4, '~');
        cin.get();
        confirmPrint("Vocês começam então a travessia pela floresta.");
        confirmPrint("A floresta é escura, densa e silenciosa, apenas com barulhos de alguns animais noturnos.");
        confirmPrint("Mesmo se fosse de dia, as copas das árvores são fechadas demais para permitir qualquer passagem de luz.");
        confirmPrint("Depois de alguns minutos caminhando, o grupo se depara com 2 caminhos diferentes para seguir.");
        confirmPrint("MEMÓRIA: O caminho da esquerda já é conhecido pela aldeia como uma rota que pode conter caçadores perigosos de outras aldeias vizinhas.");
        confirmPrint("MEMÓRIA: O caminho da direita é conhecido como uma área de cruzamento de animais perigosos.");
        return exibirOpcoes("Para qual caminho vocês vão?", {"Esquerda", "Direita"});
    }

    void caminhoEsquerda(vector<Ficha*>& party) {
        vector<Ficha*> cacadores = {};
        int falhas = 0;
        int index;
        Ficha* escolhido;

        confirmPrint("Vocês seguem pelo caminho da esquerda.");
        confirmPrint("Conforme vão caminhando silenciosamente pela rota, vocês acabam ouvindo vozes.");
        confirmPrint("Vocês precisam agora tomar muito mais cuidado e serem mais silenciosos.");
        confirmPrint("De repente, vocês percebem que estão passando do lado dos caçadores.");
        confirmPrint("Todos precisam testar sua agilidade para ver se conseguem passar rapida e silenciosamente.");
        for (Ficha* f : party) {
            if (!realizarTeste(f, agilidade, 15)) {
                falhas++;
                cout << f->nome << " acabou pisando em um galho e alertou 1 inimigo!" << endl;
                cin.get();
            } else {
                cout << f->nome << " conseguiu passar furtivamente" << endl;
                cin.get();
            }
        }
        if (falhas != 0) {
            for (int i = 0; i < falhas; i++) {
                if (rolarDado(2) == 1) {
                    cacadores.push_back(inimigo::cacador_arqueiro());
                } else {
                    cacadores.push_back(inimigo::cacador_mateiro());
                }
            }
            cout << falhas << " caçadores notaram a presença de vocês" << endl;
            cin.get();
            luta::iniciar(party, cacadores);
            confirmPrint("Ao saquear os corpos, vocês encontram 2 poções de cura!");
            for (int i = 0; i < 2; i ++) {
                index = escolherPersonagemIndex(party, "beber a poção de cura");
                escolhido = party[index];
                escolhido->vida_atual += 10;
                if (escolhido->vida_atual > escolhido->vida_max) escolhido->vida_atual = escolhido->vida_max;
                cout << escolhido->nome << " curou 10 pontos de vida!" << endl;
                cin.get();
            }

        } else {
            confirmPrint("Todos conseguiram passar furtivamente e sem alertar os caçadores!");
        }
    }

    void caminhoDireita(vector<Ficha*>& party) {
        vector<Ficha*> animais = {inimigo::jacare_acu(), inimigo::sucuri_verde()};
        Ficha* p_loot;
        confirmPrint("Vocês seguem o caminho da direita...");
        confirmPrint("Os barulhos dos animais noturnos os deixa um pouco assustados e cautelosos.");
        confirmPrint("Enquanto caminham, vocês percebem que precisam cruzar um pequeno e raso lago para continuar.");
        confirmPrint(string("Durante a travessia do lago, " + personagemAleatorio(party)->nome + " pisou em uma pedra macia que afundou no momento da pisada."));
        confirmPrint("Ao olhar mais de perto a pedra era na verdade um jacaré-açu!");
        confirmPrint(string("Ao mesmo tempo, " + personagemAleatorio(party)->nome + " sente algo enroscando na sua perna."));
        confirmPrint("A coisa na verdade era uma cobra!");
        luta::iniciar(party, animais);
        p_loot = personagemAleatorio(party);
        switch (p_loot->arma) {
            case tacape:
                cout << "Após a luta, " << p_loot->nome << " percebeu que seu tacape pode ser melhorado acoplando os dentes do jacaré na ponta!" << endl;
                cin.get();
                cout << p_loot->nome << " teve sua arma melhorada para tacape dentado!" << endl;
                cin.get();
                p_loot->arma = tacape_dentado;
                break;
            case arco:
                cout << "Após a luta, " << p_loot->nome << " percebeu que suas flechas podem ser melhoradas usando os dentes da sucuri como pontas afiadas!" << endl;
                cin.get();
                cout << p_loot->nome << " teve sua arma melhorada para arco afiado!" << endl;
                cin.get();
                p_loot->arma = arco_afiado;
                break;
            case facas:
                cout << "Após a luta, " << p_loot->nome << " percebeu que os ossos do jacaré podem ser usados para fazer novas facas!" << endl;
                cin.get();
                cout << p_loot->nome << " teve sua arma melhorada para facas de ossos serrilhados!" << endl;
                cin.get();
                p_loot->arma = facas_serrilhadas;
                break;
            case maraca:
                cout << "Após a luta, " << p_loot->nome << " percebeu que o veneno da cobra pode ser usado como uma tinta para pintar os maracás e aumentar seus poderes ritualísticos!" << endl;
                cin.get();
                cout << p_loot->nome << " teve sua arma melhorada para maracás pintados!" << endl;
                cin.get();
                p_loot->arma = maraca_pintada;
                break;
            default:
                confirmPrint("Não era pra você estar lendo isso xD");
                break;
        }
    }

    void juncaoCaminhos(vector<Ficha*>& party) {
        confirmPrint("Depois da luta, vocês seguiram o caminho e chegaram no ponto em que os dois caminhos se juntavam.");
        confirmPrint("REFLEXÃO: Vocês se perguntam o que será que teria acontecido caso vocês tivessem seguido o outro caminho...");
        confirmPrint("REFLEXÃO: Talvez vocês não tivessem sobrevivido...");
        confirmPrint(string("Enquanto refletiam, " + personagemAleatorio(party)->nome + " notou começou a ver focos de fogo à distância!"));
        confirmPrint("LÓGICA: É a aldeia Hovaigua!");
        confirmPrint("Continuando no caminho da mata, a floresta vai ficando gradualmente menos densa.");
        confirmPrint("O mato vai se abrindo e vocês se aproximam da aldeia.");
    }

    void chegandoAldeia(vector<Ficha*>& party) {
        imprimirTitulo("CAPÍTULO 3 - Horizontes", 4, '~');
        cin.get();
        confirmPrint("Vocês chegam na aldeia Hovaigua.");
        confirmPrint("PERCEPÇÃO: A aldeia é silenciosa, iluminada e pequena, mas extremamente mortal.");
        confirmPrint("PERCEPÇÃO: As grandes bandeiras e decorações de penas vermelhas chamam a atenção de vocês.");
        confirmPrint("Vocês já ouviram muitas histórias na infância sobre os Hovaigua e sobre como era a aldeia deles.");
        confirmPrint("Mas vê-la de perto os causa um frio na espinha que nunca sentiram antes.");
        confirmPrint("DETERMINAÇÃO: Vocês precisam fazer isso pelos seus antepassados.");
        confirmPrint("PERCEPÇÃO: Olhando a frente, vocês enxergam 3 ocas próximas e uma oca muito maior atrás.");
        confirmPrint("PERCEPÇÃO: As 3 ocas da frente estão na frente da oca maior, como se estivessem protegendo-a.");
        confirmPrint("INTUIÇÃO: O pajé líder dos Hovaigua deve estar na oca maior.");
        confirmPrint("INTUIÇÃO: Se quisermos chegar nele, devemos antes invadir as 3 ocas e garantir que nenhum soldado possa nos atrapalhar.");
        if (realizarTeste(party[escolherPersonagemIndex(party, "teste de Inteligência")], inteligencia, 15)) {
            confirmPrint("PERCEPÇÃO: A oca da esquerda parece normal.");
            confirmPrint("PERCEPÇÃO: A oca do meio tem um símbolo de ervas.");
            confirmPrint("PERCEPÇÃO: A oca da direita tem um símbolo de espada.");
            if (realizarTeste(party[escolherPersonagemIndex(party, "teste de Espírito")], espirito, 12)) {
                confirmPrint("INTUIÇÃO: A oca da esquerda pode ser uma habitação.");
                confirmPrint("INTUIÇÃO: A oca do meio pode ser uma loja de ervas medicinais.");
                confirmPrint("INTUIÇÃO: A oca da direita pode ser um armazém de armamentos.");
            } else {
                confirmPrint("Você não percebe mais nada");
            }
        } else {
            confirmPrint("Você não percebe nada além disso.");
        }
    }

    void ocaEsquerda(vector<Ficha*>& party) {
        int input;
        vector<Ficha*> guardas = {inimigo::guardaHovaigua(), inimigo::guardaHovaigua(), inimigo::guardaHovaigua()};
        confirmPrint("Vocês se aproximam da oca da esquerda receosos.");
        confirmPrint("Vocês caminham silenciosamente para não alertar ninguém.");
        confirmPrint("Vocês se encostam na parede ao redor da abertura.");
        input = exibirOpcoes("Vocês querem apenas entrar ou espiar antes?", {"Entrar", "Espiar"});
        if (input == 1) {
            confirmPrint("Vocês se deparam com muitos Hovaigua!");
            confirmPrint("Quando eles notam a presença de vocês, os moradores saem correndo gritando.");
            confirmPrint("Exceto 3 deles, os guardas, que ficam para combater vocês!");
        } else {
            int idx = escolherPersonagemIndex(party, "espiar");
            Ficha* escolhido = party[idx];
            if (realizarTeste(escolhido, agilidade, 12)) {
                confirmPrint("PERCEPÇÃO: Você enxerga muitos Hovaigua, eles estão todos reunidos e conversando em uma roda.");
                confirmPrint("PERCEPÇÃO: Mas você percebe que 3 deles se destacam.");
                confirmPrint("PERCEPÇÃO: Os 3 são guardas da aldeia.");
                confirmPrint("INTUIÇÃO: Sabendo quem são os guardas, podemos atacar eles furtivamente!");
                confirmPrint("Vocês conseguem entrar sorrateiramente e desferir um golpe contra um dos guardas!");
                luta::atacar(escolhido, guardas[0]);
            } else {
                confirmPrint("Você se apoia para espiar a oca, mas perde o equilíbrio e cai no chão, alertando todos que estão dentro.");
                confirmPrint("Você enxerga 3 guardas Hovaigua correndo na direção de vocês.");
                cout << "Um deles se aproxima de " << escolhido->nome << " e ataca-o com a lança" << endl;
                cin.get();
                luta::atacar(guardas[0], escolhido);
            }
        }
        luta::iniciar(party, guardas);
        confirmPrint("Depois da cansativa luta contra os guardas, vocês saem da oca.");
    }

    void ocaMeio(vector<Ficha *>& party) {
        int input;
        int input_idosa;
        int idx;
        int atr;
        Ficha* escolhido;
        bool matou_idosa = false;
        confirmPrint("Vocês se aproximam da oca do meio.");
        confirmPrint("PERCEPÇÃO: Ao chegar mais perto, vocês notam um símbolo de ervas na entrada da oca.");
        confirmPrint("PERCEPÇÃO: Vocês imediatamente percebem que a oca possue um forte odor de ervas sendo exalados.");
        input = exibirOpcoes("Vocês desejam entrar ou espiar?", {"Entrar", "Espiar"});
        if (input == 1) {
            confirmPrint("Vocês entram na oca e se deparam com uma idosa brava.");
            confirmPrint("PERCEPÇÃO: esse lugar é uma loja de ervas medicinais e a idosa provavelmente é quem cuida do local.");
            confirmPrint("INTUIÇÃO: A senhora está com medo no fundo.");
            input_idosa = exibirOpcoes("Vocês desejam matar ou render a senhora?", {"Matar", "Render"});
                if (input_idosa == 1) {
                    confirmPrint("Vocês brutalmente matam a idosa.");
                    confirmPrint("A loja agora é completamente de vocês e podem pegar o que quiser.");
                    matou_idosa = true;
                } else {
                    confirmPrint("Vocês rendem a idosa e agora ela está disposta a ajudar vocês.");
                }
        } else {
            idx = escolherPersonagemIndex(party, "espiar");
            escolhido = party[idx];
            cout << escolhido->nome << " espia a oca por dentro e percebe que aquele lugar é uma loja de ervas." << endl;
            cin.get();
            confirmPrint("Mas de repente, uma idosa aparece e dá uma panelada na sua cabeça.");
            escolhido->vida_atual -= 3;
            cout << escolhido->nome << " perde 3 pontos de vida!" << endl;
            cin.get();
            if (luta::morreu(escolhido)) {
                party.erase(party.begin() + idx);
                cout << escolhido->nome << " morreu!" << endl;
                cin.get();
            }
            input_idosa = exibirOpcoes("Vocês desejam matar ou render a senhora?", {"Matar", "Render"});
            if (input_idosa == 1) {
                confirmPrint("Vocês brutalmente matam a idosa.");
                confirmPrint("A loja agora é completamente de vocês e podem pegar o que quiser.");
                matou_idosa = true;
            } else {
                confirmPrint("Vocês rendem a idosa e agora ela está disposta a ajudar vocês.");
            }
        }

        confirmPrint("Vocês exploram o lugar e encontram 3 ervas medicinais");
        for (int i = 0; i < 3; i++) {
            idx = escolherPersonagemIndex(party, "curar");
            party[idx]->vida_atual += 8;
            if (party[idx]->vida_atual > party[idx]->vida_max) party[idx]->vida_atual = party[idx]->vida_max;
            cout << party[idx]->nome << " curou 8 pontos de vida!" << endl;
            cin.get();
        }

        if (!matou_idosa) {
            confirmPrint("A idosa, com medo, diz que possui uma erva poderosa escondida.");
            confirmPrint("De repente, ela traz para vocês uma erva do poder!");
            confirmPrint("MEMÓRIA: A erva do poder dá ao seu consumidor mais 3 pontos de atributo para usar em qualquer atributo.");
            idx = escolherPersonagemIndex(party, "usar erva do poder");
            escolhido = party[idx];
            atr = exibirOpcoes("Qual atributo você deseja adicionar os pontos?", {"Força", "Inteligência", "Agilidade", "Resistência", "Espírito"});
            switch (atr) {
                case 1:
                    escolhido->forca += 3;
                    cout << "Sua força agora é " << escolhido->forca << endl;
                    cin.get();
                    break;
                case 2:
                    escolhido->inteligencia += 3;
                    cout << "Sua inteligência agora é " << escolhido->inteligencia << endl;
                    cin.get();
                    break;
                case 3:
                    escolhido->agilidade += 3;
                    cout << "Sua agilidade agora é " << escolhido->agilidade << endl;
                    cin.get();
                    break;
                case 4:
                    escolhido->resistencia += 3;
                    cout << "Sua resistência agora é " << escolhido->resistencia << endl;
                    cin.get();
                    break;
                case 5:
                    escolhido->espirito += 3;
                    cout << "Sua espírito agora é " << escolhido->espirito << endl;
                    cin.get();
                    break;
            }
        }
        confirmPrint("Já tendo tudo revistado, vocês decidem sair da oca");
    }

    void ocaDireito(vector<Ficha *>& party) {
        Ficha* esc = personagemAleatorio(party);
        Armas loot;
        switch (esc->arma) {
            case tacape:
            case tacape_dentado:
                loot = tacapaco;
                break;
            case arco:
            case arco_afiado:
                loot = arco_triplo;
                break;
            case facas:
            case facas_serrilhadas:
                loot = facas_2_gumes;
                break;
            case maraca:
            case maraca_pintada:
                loot = grimorio;
                break;
            default:
                confirmPrint("Top 10 coisas que você não deveria estar lendo");
                break;
        }
        confirmPrint("PERCEPÇÃO: Conforme vocês se aproximam da oca da direita, vocês notam que nela tem gravado um símbolo de uma espada.");
        confirmPrint("Vocês entram todos juntos nela e notam que ela é onde os guardas guardam seus equipamentos.");
        confirmPrint("Mas todos os armamentos parecem ter sido pegos, não sobrando nenhum.");
        esc->arma = loot;
        cout << "De repente, " << esc->nome << " acaba encontrando " << nomeDaArma(esc) << "!" << endl;
        cin.get();
        confirmPrint("Sem ter mais nada para verificar, vocês saem da oca.");
    }

    void finalTraicao() {
        falar(inimigo::cacique(), "Obrigado. Vocês não vão se arrepender.");
        confirmPrint("Vocês se juntam ao cacique.");
        confirmPrint("Vocês são cuidados, tratados, respeitados.");
        confirmPrint("Vocês vivem uma vida muito presitigada.");
        confirmPrint("Mas precisam servir ao cacique.");
        confirmPrint("Vocês vão para a aldeia de vocês junto com o exército dele.");
        confirmPrint("Os moradores acreditam que vocês voltaram vitoriosos, eles estão felizes.");
        confirmPrint("Mas depois notam que vocês estão com outros propósitos.");
        confirmPrint("Vocês invadem as ocas e mata cada um deles a sangue frio.");
        confirmPrint("Adultos, Crianças, Idosos, todos.");
        confirmPrint("Até os da sua família, aqueles que vocês sempre conviveram juntos.");
        confirmPrint("A antiga aldeia de vocês agora é Hovaigua.");
        imprimirTitulo("FINAL 1 - A Traição");
    }

    void finalBom() {
        confirmPrint("Depois de derrotar o cacique e os Hovaigua, vocês retornam para casa.");
        confirmPrint("O dia está amanhecendo, os pássaros estão começando a cantar.");
        confirmPrint("Essa foi uma noite muito longa.");
        confirmPrint("Ao notar vocês chegando, a aldeia inteira sai de suas ocas para recebê-los.");
        confirmPrint("Ninguém tem riquezas para oferecer.");
        confirmPrint("Mas tem peixes feitos na hora, abraços, agradecimentos, crianças felizes, idosos em segurança.");
        confirmPrint("Vocês são os verdadeiros heróis da aldeia.");
        confirmPrint("Todos estão em segurança e vocês sabem que serão para sempre dessa aldeia.");
        imprimirTitulo("FINAL 2 - Nós Podemos Ser Heróis");
    }

    void final(vector<Ficha*>& party) {
        int inp;
        vector<Ficha*> cacique = {inimigo::cacique()};
        imprimirTitulo("CAPÍTULO 4 - A Corte do Cacique Hovaigua", 4, '~');
        cin.get();
        confirmPrint("Depois de passar pelas 3 ocas e seus desafios, vocês começam a se aproximar da última oca.");
        confirmPrint("Ela se destaca muito mais que as outras.");
        confirmPrint("PERCEPÇÃO: Ela é muito maior que as outras 3 e é feita com uma material mais resistente.");
        confirmPrint("INTUIÇÃO: Vocês sabem que o Cacique Hovaigua já está ciente da presença de vocês.");
        confirmPrint("Vocês dão uma suspirada e repensam se vale a pena mesmo fazer isso.");
        confirmPrint("REFLEXÃO: É pela aldeia de vocês.");
        confirmPrint("REFLEXÃO: É por todo o sangue que os Hovaigua já derramou de vocês.");
        confirmPrint("Vocês entram na oca e veem ao fundo uma figura mal iluminada esperando por vocês.");
        confirmPrint("PERCEPÇÃO: Enquanto se aproximam, vocês percebem que a figura está de costas para vocês.");
        falar(cacique[0], "Então são vocês.");
        confirmPrint("PERCEPÇÃO: A voz dele é tranquila. Ele não tem medo.");
        falar(cacique[0], "Eu estive esperando.");
        falar(cacique[0], "Confesso que estou surpreso que vocês conseguiram chegar até aqui.");
        falar(cacique[0], "Eu vejo vocês como guerreiros extremamente determinados.");
        falar(cacique[0], "Sabe, seria uma pena ter que acabar com vocês.");
        falar(cacique[0], "Quase como um desperdício.");
        falar(cacique[0], "Depois de pensar por um tempo, eu cheguei a uma conclusão.");
        falar(cacique[0], "Eu tenho uma proposta para vocês.");
        falar(cacique[0], "A aldeia de vocês já está destruída.");
        falar(cacique[0], "Vocês são fracos, pequenos.");
        falar(cacique[0], "Eu só estava adiantando um processo natural que já era para ter ocorrido há muito tempo.");
        falar(cacique[0], "Mas vocês são melhores que isso.");
        falar(cacique[0], "A minha proposta é:");
        falar(cacique[0], "Se juntem a minha aldeia.");
        falar(cacique[0], "Eu darei todos os tipos de regalias, vocês serão autoridade aqui.");
        falar(cacique[0], "Terão suas terras, armamentos mais fortes e o que mais quiserem.");
        falar(cacique[0], "Nós vamos para a aldeia de vocês e vamos conquistá-la juntos.");
        falar(cacique[0], "Nós conquistaremos todas as aldeias da região. Seremos gigantes!");
        falar(cacique[0], "E então... O que decidem?");
        inp = exibirOpcoes("Se juntar aos Hovaigua?", {"Sim", "Não"});
        if (inp == 1) {
            finalTraicao();
        } else {
            falar(cacique[0], "Então é assim que vai ser...");
            falar(cacique[0], "Vou mandar lembranças para a aldeia de vocês");
            imprimirTitulo("A LUTA FINAL COMEÇA!");
            cin.get();
            luta::iniciar(party, cacique);
            falar(cacique[0], "Então é assim... que acaba...");
            falar(cacique[0], "Vocês estão fadados ao fracasso...");
            falar(cacique[0], "Depois de mim... virão mais...");
            falar(cacique[0], "E eles acabaram com a aldeia fraca de vocês...");
            falar(cacique[0], "Adeus...");
            confirmPrint("O Cacique Hovaigua morreu!");
            finalBom();
        }

    }

    /*
     * se você estiver lendo isso aqui, então vou te contar um fun fact.
     * O nome dos capítulos são em homenagem a músicas que eu gosto.
     * 1- sem estrelas -> Starless - King Crimson
     * 2- longe de qualquer estrada -> Far From Any Road - The Handsome Family
     * 3- Horizontes -> Horizons - Genesis
     * 4- A Corte do Cacique Hovaigua -> The Court of the Crimson King - King Crimson
     *
     * e o final 2 (Nós podemos ser heróis) é em homenagem à música "Heroes" - David Bowie :P
     *
     * Hovaigua significa "rival" em tupi guarani (sim, bem direto mesmo)
     *
     * e os comentários que começam com "PERCEPÇAO", "INTUICAO", "REFLEXAO", bla bla bla são
     * uma referência ao jogo Disco Elysium, em que os sentidos do protagonista são tratados como
     * falas, igualzinho como eu fiz.
     */


} // namespace
