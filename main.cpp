#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

class Card {
private:
    static const int DESIGN_SIZE = 7;
    std::vector<std::string> design;
    int cardValue, color;
public:
    Card() {}
    Card(const int _cardValue, int _color = 0) : design(DESIGN_SIZE, std::string("             ")), cardValue(_cardValue), color(_color) {
        for (int i = 0; i < DESIGN_SIZE; i++) {
            design[i][0] = design[i][DESIGN_SIZE - 1] = '|';
            design[0][i] = design[DESIGN_SIZE - 1][i] = '-';
        }
        design[DESIGN_SIZE - 1][0] = '-';

        switch (cardValue) {
        case 2:
            design[1][2] = design[1][3] = design[1][4] = '*';
            design[2][4] = design[3][4] = design[4][3] = '*';
            design[5][2] = design[2][2] = '*';
            design[5][2] = design[5][3] = design[5][4] = '*';
            break;
        case 3:
            design[1][2] = design[1][3] = design[1][4] = '*';
            design[3][2] = design[3][3] = design[3][4] = '*';
            design[5][2] = design[5][3] = design[5][4] = '*';
            design[2][4] = design[4][4] = '*';
            break;
        case 4:
            design[1][2] = design[2][2] = design[3][2] = '*';
            design[3][3] = design[3][4] = design[2][4] = '*';
            design[5][4] = design[4][4] = '*';
            break;
        case 5:
            design[1][2] = design[2][2] = design[3][2] = '*';
            design[1][3] = design[1][4] = design[3][3] = design[3][4] = '*';
            design[4][4] = design[5][2] = design[5][3] = design[5][4] = '*';
            break;
        case 6:
            design[1][2] = design[2][2] = design[3][2] = design[4][2] = design[5][2] = '*';
            design[1][3] = design[1][4] = design[3][3] = design[3][4] = '*';
            design[4][4] = design[5][3] = design[5][4] = '*';
            break;
        case 7:
            design[1][2] = design[1][3] = design[1][4] = '*';
            design[2][4] = design[3][4] = design[4][3] = design[5][2] = '*';
            break;
        case 8:
            design[1][2] = design[1][3] = design[1][4] = '*';
            design[3][2] = design[3][3] = design[3][4] = '*';
            design[5][2] = design[5][3] = design[5][4] = '*';
            design[2][2] = design[4][2] = design[2][4] = design[4][4] = '*';
            break;
        case 9:
            design[1][2] = design[1][3] = design[1][4] = '*';
            design[3][2] = design[3][3] = design[3][4] = '*';
            design[5][2] = design[5][3] = design[5][4] = '*';
            design[2][2] = design[2][4] = design[4][4] = '*';
            break;
        case 10:
            design[1][1] = design[2][1] = design[3][1] = design[4][1] = design[5][1] = '*';
            design[1][3] = design[1][4] = design[1][5] = '*';
            design[5][5] = design[5][4] = design[5][5] = '*';
            design[2][3] = design[3][3] = design[5][3] = '*';
            design[2][5] = design[3][5] = design[5][5] = '*';
            design[4][3] = design[4][5] = '*';
            design[3][0] = design[3][DESIGN_SIZE - 1] = 'X';
            break;
        case 11:
            design[1][2] = design[1][3] = design[1][4] = '*';
            design[2][4] = design[3][4] = design[4][4] = design[5][4] = '*';
            design[5][3] = design[5][2] = design[4][2] = '*';
            design[3][0] = design[3][DESIGN_SIZE - 1] = 'J';
            break;
        case 12:
            design[1][2] = design[1][3] = design[1][4] = '*';
            design[3][2] = design[3][4] = design[5][5] = '*';
            design[5][2] = design[5][3] = design[5][4] = '*';
            design[2][2] = design[4][2] = design[2][4] = design[4][4] = '*';
            design[3][0] = design[3][DESIGN_SIZE - 1] = 'Q';
            break;
        case 13:
            design[1][2] = design[2][2] = design[3][2] = design[4][2] = design[5][2] = '*';
            design[2][3] = design[4][3] = design[1][4] = design[5][4] = '*';
            design[3][0] = design[3][DESIGN_SIZE - 1] = 'K';
            break;
        case 14:
            design[2][2] = design[3][2] = design[4][2] = design[5][2] = '*';
            design[2][4] = design[3][4] = design[4][4] = design[5][4] = '*';
            design[1][3] = '*';
            design[3][0] = design[3][DESIGN_SIZE - 1] = 'A';
            break;
        default:
            break;
        }

        std::string colorString = "ROSU";
        switch (color) {
        case 1:
            colorString = "NEGRU";
            break;
        case 2:
            colorString = "ROMB";
            break;
        case 3:
            colorString = "TREFLA";
            break;
        default:
            break;
        }

        for (int i = 0; i < (int)colorString.size(); i++) {
            design[0][DESIGN_SIZE - (int)colorString.size() + i] = colorString[i];
            design[DESIGN_SIZE - 1][i] = colorString[i];
        }

        if (cardValue < 10) {
            design[3][0] = design[3][DESIGN_SIZE - 1] = (char)cardValue + '0';
        }
    }
    Card(const Card &other) : design(other.design), cardValue(other.cardValue), color(other.color) {}
    ~Card() {
        design.clear();
    }
    Card& operator =(const Card &other) {
        design = other.design;
        color = other.color;
        cardValue = other.cardValue;
        return *this;
    }

    std::pair<int, int> getCardInfo() {
        return std::make_pair(cardValue, color);
    }
    bool isPoint() {
        return (cardValue == 10 || cardValue == 14);
    }
    bool isImportant() {
        return isPoint() || (cardValue == 7);
    }

    friend std::ostream& operator <<(std::ostream& out, const Card &C) {
        for (int i = 0; i < C.DESIGN_SIZE; i++) {
            if (i > 0) {
                out << "\n";
            }
            for (int j = 0; j < C.DESIGN_SIZE; j++) {
                if (j > 0) {
                    out << " ";
                }
                out << C.design[i][j];
            }
        }
        return out;
    }
};

class Deck {
private:
    std::vector<Card> cards;
    int deckSize;
    std::mt19937 gen;
    std::uniform_int_distribution<int> distr;
public:
    Deck(int _deckSize) : deckSize(_deckSize) {
        for (int i = 0; i < deckSize; i++) {
            for (int color = 0; color < 4; color++) {
                cards.push_back(Card(i + 2, color));
            }
        }

        deckSize *= 4;
        std::random_device rd;
        gen = std::mt19937(rd());
        distr = std::uniform_int_distribution<int>(0, deckSize - 1);
    }

    int size() {
        return deckSize;
    }
    void resize(int _deckSize) {
        deckSize = _deckSize;
        cards.clear();
        for (int i = 0; i < deckSize; i++) {
            for (int color = 0; color < 4; color++) {
                cards.push_back(Card(i + 2, color));
            }
        }
        deckSize *= 4;
        distr = std::uniform_int_distribution<int>(0, deckSize - 1);
    }
    bool empty() {
        return (deckSize == 0);
    }
    void shuffleDeck() {
        random_shuffle(cards.begin(), cards.end());
    }
    const Card getCard() {
        int pos = distr(gen);
        return cards[pos];
    }
    const Card getCardAndRemoveIt() {
        int pos = distr(gen);
        Card Answer = cards[pos];
        cards.erase(cards.begin() + pos);
        deckSize--;
        distr = std::uniform_int_distribution<int>(0, deckSize - 1);
        return Answer;
    }

    friend std::ostream& operator <<(std::ostream &out, const Deck &D) {
        for (const Card &C : D.cards) {
            out << C << "#######\n";
        }
        return out;
    }
};

class Player {
private:
    std::vector<Card> cards;
    int points;
public:
    Player() : points(0) {}

    const Card getCard(int pos) {
        Card answer = cards[pos];
        cards.erase(cards.begin() + pos);
        return answer;
    }
    int getNumberOfCards() {
        return (int)cards.size();
    }
    int getPoints() {
        return points;
    }
    void updateHand(std::vector<Card> &taken) {
        for (Card &C : taken) {
            if (C.isPoint()) {
                points++;
            }
        }
    }
    void addCard(const Card &C) {
        cards.push_back(C);
    }
    const Card move(int baseCardValue, bool win, int pos = -1) {
        if (pos == -1) {
            if (win) {
                for (int i = 0; i < (int)cards.size(); i++) {
                    if (cards[i].getCardInfo().first != 7 && cards[i].isPoint() && cards[i].getCardInfo().first != baseCardValue) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    for (int i = 0; i < (int)cards.size(); i++) {
                        if (cards[i].getCardInfo().first != 7 && cards[i].getCardInfo().first != baseCardValue) {
                            pos = i;
                            break;
                        }
                    }
                    if (pos == -1) {
                        for (int i = 0; i < (int)cards.size(); i++) {
                            if (cards[i].getCardInfo().first != 7) {
                                pos = i;
                                break;
                            }
                        }
                        if (pos == -1) {
                            pos = 0;
                        }
                    }
                }
            } else {
                for (int i = 0; i < (int)cards.size(); i++) {
                    if (cards[i].getCardInfo().first == baseCardValue) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    if (baseCardValue == 10 || baseCardValue == 14) {
                        for (int i = 0; i < (int)cards.size(); i++) {
                            if (cards[i].getCardInfo().first == 7) {
                                pos = i;
                                break;
                            }
                        }
                        if (pos == -1) {
                            pos = 0;
                        }
                    } else {
                        for (int i = 0; i < (int)cards.size(); i++) {
                            if (!cards[i].isImportant()) {
                                pos = i;
                                break;
                            }
                        }
                    }
                }
            }
        }
        Card answer = cards[pos];
        cards.erase(cards.begin() + pos);
        return answer;
    }
    friend std::ostream& operator <<(std::ostream &out, const Player &P) {
        out << "Player has " << P.points << " points.\nCards:\n";
        for (const Card &C : P.cards) {
            out << C << "\n";
        }
        return out;
    }
};

class Game {
private:
    std::vector<Player> players;
    Deck D;
    std::pair<int, int> score;
    int roundsPlayed, starts;
public:
    Game() : players(4), D(13), score(0, 0), roundsPlayed(0), starts(0) {}
    void playRound() {
        D.resize(13);
        D.shuffleDeck();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                players[i].addCard(D.getCardAndRemoveIt());
            }
        }
        // TODO: add some corner cases
        while (!D.empty()) {
            std::vector<Card> taken;
            while (true) {
                int who = starts;
                bool changed = false;
                std::cout << players[0] << "\n";
                Card Base;
                if (starts == 0) {
                    int id; std::cout << "Select the i-th card: "; std::cin >> id;
                    Base = players[0].getCard(id);
                } else {
                    Base = players[starts].getCard(0);
                }
                taken.push_back(Base);
                std::cout << Base << "\n";
                for (int i = 0; i < 3; i++) {
                    int pos = (starts + i + 1) % 4;
                    Card Down;
                    if (pos == 0) {
                        int id; std::cout << "Select the i-th card: "; std::cin >> id;
                        Down = players[0].move(Base.getCardInfo().first, who, id);
                    } else {
                        Down = players[pos].move(Base.getCardInfo().first, who);
                    }
                    taken.push_back(Down);
                    std::cout << Down << "\n";
                    if (Down.getCardInfo().first == 7 || Down.getCardInfo().first == Base.getCardInfo().first) {
                        changed |= (who % 2 != starts % 2);
                        who = starts;
                    }
                }
                std::cout << "###########################\n";
                starts = who;
                if (!changed || D.empty()) {
                    players[who].updateHand(taken);
                    break;
                }
            }
            int numberOfCards = players[0].getNumberOfCards(), X = (int)D.size() / 4;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < std::min(4 - numberOfCards, X); j++) {
                    players[i].addCard(D.getCardAndRemoveIt());
                }
            }
        }
        roundsPlayed++;
    }
    bool finished() {
        if (score.first == 8 || score.second == 8) {
            return true;
        }
        return false;
    }
    friend std::ostream& operator <<(std::ostream &out, const Game &G) {
        out << "Score: " << G.score.first << " - " << G.score.second << "\n";
        out << "Number of rounds played: " << G.roundsPlayed << "\n";
        if (G.starts % 2 == 0) {
            out << "You start!\n";
        } else {
            out << "The opponent will start!\n";
        }
        return out;
    }
};

int main() {
    Game G;
    while (!G.finished()) {
        G.playRound();
    }
    std::cout << G << "\n";
    return 0;
}