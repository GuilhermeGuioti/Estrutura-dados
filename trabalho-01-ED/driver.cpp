#include "Queue.h"
#include <iostream>
#include <fstream>
#include <sstream>  
#include <string>   
#include <cstdlib>
#include <ctime>
using namespace std;

void loadCards(Cards allCards[], int totalCards) {
    // 1. ABRIR O ARQUIVO
    // Cria um objeto de fluxo de entrada de arquivo (ifstream) e tenta abrir o "cards.csv".
    ifstream arquivo("cards.csv");

    // Verifica se o arquivo foi aberto corretamente. Se não, exibe um erro e encerra.
    if (!arquivo.is_open()) {
        cout << "Erro: Nao foi possivel abrir o arquivo cards.csv" << endl;
        abort();
    }

    string line;
    int count = 0;

    // 2. IGNORAR O CABEÇALHO
    // A primeira line do CSV contém os títulos das colunas, então a lemos e descartamos.
    if (getline(arquivo, line)) {
        // A line do cabeçalho foi lida, mas não fazemos nada com ela.
    }

    // 3. LER OS DADOS DAS CARTAS
    // O loop continua enquanto houver lines para ler no arquivo e não tivermos
    // preenchido todo o nosso array (medida de segurança).
    while (count < totalCards && getline(arquivo, line)) {
        
        // 4. "QUEBRAR" A line (PARSING)
        // Cria um stringstream a partir da line lida. Isso nos permite "ler" da string
        // como se estivéssemos lendo do 'cin' ou de um arquivo.
        stringstream ss(line);

        // Variáveis temporárias para armazenar cada campo como string.
        string model_str, curb_weight_str, engine_size_str, horse_power_str, price_str, group_str;

        // Usa getline para extrair cada campo da stringstream, usando ';' como delimitador.
        getline(ss, model_str, ',');
        getline(ss, curb_weight_str, ',');
        getline(ss, engine_size_str, ',');
        getline(ss, horse_power_str, ',');
        getline(ss, price_str, ',');
        getline(ss, group_str, ',');

        // 5. CONVERTER E ARMAZENAR
        // Atribui os valores lidos ao elemento atual do array de cartas.
        // Os campos de texto são atribuídos diretamente.
        allCards[count].model = model_str;
        allCards[count].group = group_str;

        // Os campos numéricos precisam ser convertidos de string para int.
        // A função stoi() (string to integer) faz essa conversão.
        allCards[count].curb_weight = stoi(curb_weight_str);
        allCards[count].engine_size = stoi(engine_size_str);
        allCards[count].horse_power = stoi(horse_power_str);
        allCards[count].price = stoi(price_str);

        // Passa para a próxima posição do array.
        count++;
    }

    // 6. FECHAR O ARQUIVO
    arquivo.close();
}

// Função para embaralhar o array de cartas usando o algoritmo Fisher-Yates
void shuffleCards(Cards allCards[], int totalCards) {
    // O loop percorre o array do final para o começo.
    // Não precisamos ir até o índice 0, pois quando i=1, ele troca com 0 ou 1.
    for (int i = totalCards - 1; i > 0; i--) {
        // Gera um índice aleatório 'j' entre 0 e i (inclusive).
        // rand() % (i + 1) garante que o número sorteado esteja no intervalo correto.
        int j = rand() % (i + 1);

        // Troca os elementos das posições i e j.
        // Usamos uma variável 'temp' para não perder o valor de allCards[i].
        Cards temp = allCards[i];
        allCards[i] = allCards[j];
        allCards[j] = temp;
    }
    cout << "Cartas embaralhadas com sucesso!" << endl;
}

// Função para distribuir as cartas do array para os dois decks (filas)
void distributeCards(Cards allCards[], Queue& p1Deck, Queue& p2Deck, int totalCards) {
    int halfDeck = totalCards / 2;

    // Distribui a primeira metade das cartas para o Jogador 1
    for (int i = 0; i < halfDeck; i++) {
        p1Deck.append(allCards[i]);
    }

    // Distribui a segunda metade para o Jogador 2
    for (int i = halfDeck; i < totalCards; i++) {
        p2Deck.append(allCards[i]);
    }

    cout << "Cartas distribuidas para os dois jogadores." << endl;
}

void displayCard(Cards card){
    cout << "  ------------------------------------" << endl;
    cout << "  Modelo: " << card.model << endl;
    cout << "  Grupo: " << card.group << endl;
    cout << "  ------------------------------------" << endl;
    cout << "  1. Peso Bruto: " << card.curb_weight << " (Menor vence)" << endl;
    cout << "  2. Preco: $" << card.price << " (Menor vence)" << endl;
    cout << "  3. Cilindrada: " << card.engine_size << " (Maior vence)" << endl;
    cout << "  4. Potencia: " << card.horse_power << " hp (Maior vence)" << endl;
    cout << "  ------------------------------------" << endl;
}

void checkSuperTrunfo(Cards cardP1, Cards cardP2, bool &p1Win, bool &p2Win, bool &isTrunfoRound){
    if (cardP1.group == "1A") {
        isTrunfoRound = true;
        cout << "Você jogou a Super Trunfo!" << endl;
    
        if (cardP2.group.find('A') != string::npos) {
            cout << "Mas o Jogador 2 tem uma carta do grupo A e vence a rodada!" << endl;
            p2Win = true;
        } else {
            cout << "Jogador 1 vence a rodada!" << endl;
            p1Win = true;
        }   
    }

    else if (cardP2.group == "1A") {
        isTrunfoRound = true;
        cout << "Jogador 2 jogou a Super Trunfo!" << endl;

        if (cardP1.group.find('A') != string::npos) {
            cout << "Mas o você tem uma carta do grupo A e vence a rodada!" << endl;
            p1Win = true;
        } else {
            cout << "Jogador 2 vence a rodada!" << endl;
            p2Win = true;
        }
    }

    else{
        isTrunfoRound = false;
    }
}

int getPlayerChoice() {
    int choice = 0;
    cout << "\nEscolha um atributo para comparar (1-4): ";
    
    // Loop para garantir que o jogador digite um número válido (entre 1 e 4)
    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Opcao invalida. Por favor, escolha um numero entre 1 e 4: ";
        cin.clear(); // Limpa o estado de erro do cin
        cin.ignore(10000, '\n'); // Descarta a entrada inválida do buffer
    }
    
    return choice;
}

/**
 * Executa uma rodada normal: pede a escolha, compara e lida com empates.
 * Altera as variáveis p1Wins ou p2Wins para indicar o vencedor.
 */
void playNormalRound(Cards cardP1,Cards cardP2, bool& p1Wins, bool& p2Wins) {
// O loop infinito para desempate continua o mesmo
    while (true) {
        int choice = getPlayerChoice(); // A função getPlayerChoice continua igual

        switch (choice) {
            case 1: // Peso Bruto (menor vence)
                if (cardP1.curb_weight < cardP2.curb_weight) { p1Wins = true; return; }
                if (cardP1.curb_weight > cardP2.curb_weight) { p2Wins = true; return; }
                cout << "--- EMPATE! --- Escolha outro atributo." << endl;
                break;

            case 2: // Preço (menor vence)
                if (cardP1.price < cardP2.price) { p1Wins = true; return; }
                if (cardP1.price > cardP2.price) { p2Wins = true; return; }
                cout << "--- EMPATE! --- Escolha outro atributo." << endl;
                break;

            case 3: // Cilindrada (maior vence)
                if (cardP1.engine_size > cardP2.engine_size) { p1Wins = true; return; }
                if (cardP1.engine_size < cardP2.engine_size) { p2Wins = true; return; }
                cout << "--- EMPATE! --- Escolha outro atributo." << endl;
                break;

            case 4: // Potência (maior vence)
                if (cardP1.horse_power > cardP2.horse_power) { p1Wins = true; return; }
                if (cardP1.horse_power < cardP2.horse_power) { p2Wins = true; return; }
                cout << "--- EMPATE! --- Escolha outro atributo." << endl;
                break;
        }
    }
}

int main(){
    srand(time(0));

    const int TOTAL_CARDS = 32;
    Cards allCards[TOTAL_CARDS];

    // 1. Carrega as cartas
    loadCards(allCards, TOTAL_CARDS);
    
    // 2. Embaralha as cartas
    shuffleCards(allCards, TOTAL_CARDS);

    // 3. Cria os decks dos jogadores
    Queue player1Deck;
    Queue player2Deck;

    // 4. Chama a nova função para distribuir as cartas
    distributeCards(allCards, player1Deck, player2Deck, TOTAL_CARDS);

    cout << "\n--- O JOGO VAI COMECAR! ---" << endl;
    
    int round = 1;

    while (!player1Deck.empty() && !player2Deck.empty()) {
      cout << "\n--- Rodada " << round << " ---" << endl;
      cout << "Jogador 1: " << player1Deck.size() << " cartas | Jogador 2: " << player2Deck.size() << " cartas" << endl;
      
      //VARIAVEIS DE CONTROLE DE ESTADO
      bool player1WinRound = false;
      bool player2WinRound = false;
      bool isTrunfoRound = false;

      // 1. RETIRAR AS CARTAS DO TOPO
      Cards cardP1, cardP2;
      player1Deck.serve(cardP1);
      player2Deck.serve(cardP2);

      // 2. EXIBIR AS INFORMAÇÕES DAS CARTAS
      cout << "\nSua carta:" << endl;
      displayCard(cardP1);

      // 3. VERIFICAR A CARTA SUPER TRUNFO (CASO ESPECIAL)
      checkSuperTrunfo(cardP1, cardP2, player1WinRound, player2WinRound, isTrunfoRound);

      // 4. ESCOLHER O ATRIBUTO E COMPARAR
      if(!isTrunfoRound) playNormalRound(cardP1, cardP2, player1WinRound, player2WinRound);  
      
      // 5. DETERMINAR O VENCEDOR E TRANSFERIR AS CARTAS
      if(player1WinRound){
        cout << "Voce venceu a rodada!" << endl;
        player1Deck.append(cardP2);
        player1Deck.append(cardP1);
      }
      if(player2WinRound){
        cout << "O computador venceu a rodada!" << endl;
        player2Deck.append(cardP1);
        player2Deck.append(cardP2);
      }

      round++;

      // Adicione uma pausa para o jogador poder ler o que aconteceu
      cout << "Pressione Enter para a proxima rodada...";
      cin.ignore();
      cin.get();
    }

    // --- FIM DO JOGO ---
    if (!player1Deck.empty()) {
      cout << "\nPARABENS! Voce venceu o jogo!" << endl;
    } else {
      cout << "\nFIM DE JOGO! O computador venceu." << endl;
    }

  return 0;
}