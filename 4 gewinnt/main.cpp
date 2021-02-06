#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <vector>

using namespace std;

struct _player {
    string name;
    int score;
    char sign;
};

void player_menu(vector<_player> &spieler, bool set = false);
void new_game(vector<_player> &spieler);
void print_field(char spielfeld[6][7]);
bool push_field(char (&spielfeld)[6][7], char field, char sign);
bool check_winner(char spielfeld[6][7], vector<_player> &spieler);

/*
 *
 */

int main(int argc, char** argv) {
    vector<_player> spieler;
    spieler.push_back(_player());
    spieler[0].name = "Spieler 1";
    spieler[0].score = 0;
    spieler[0].sign = 'X';
    spieler.push_back(_player());
    spieler[1].name = "Spieler 2";
    spieler[1].score = 0;
    spieler[1].sign = 'O';

    char auswahl;
    do {
        cout << "\nWillkommen bei VIER-Gewinnt:"
                << "\n(n/N) Namen eingeben"
                << "\n(h/H) Highscore"
                << "\n(s/S) Neues Spiel starten"
                << "\n(q/Q) Verlassen"
                << "\nAuswahl: ";
        cin >> auswahl;

        switch (toupper(auswahl))
        {
            case 'N':
                player_menu(spieler, true);
                break;
            case 'H':
                player_menu(spieler);
                break;
            case 'S':
                new_game(spieler);
                break;
            case 'Q':
                cout << "Vielen Dank fÃ¼rs Spielen!" << endl << endl;
                break;
            default:
                cout << "UngÃ¼ltige Eingabe!" << endl << endl;
        }
    } while (auswahl != 'Q');

    return 0;
}

void player_menu(vector<_player> &spieler, bool set) {
    if (set) {
        cout << "\nNamen eingeben\n\n";

        for (int i = 0; i < 2; i++) {
            cout << "Geben Sie den Namen fÃ¼r Spieler " << (i + 1) << " ein: ";
            cin >> spieler[i].name;
        }

        cout << "Namen gespeichert!\n";
    } else {
        cout << "\nHighscores\n\n"
                << spieler[0].name << "\t\t" << spieler[0].score << endl
                << spieler[1].name << "\t\t" << spieler[1].score << endl;
    }
}

void new_game(vector<_player> &spieler) {
    char spielfeld[6][7];
    for (int i = 0; i < 6; i++) {
        for (int k = 0; k < 7; k++)
            spielfeld[i][k] = '*';
    }

    bool winner = false;
    int current_player = 0;
    char auswahl;

    cout << "\nNeues Spiel beginnt!\n\n";
    print_field(spielfeld);

    do {
        bool back = false;
        cout << spieler[current_player].name << " ist an der Reihe\nEingabe: ";

        do {
            cin >> auswahl;
            auswahl = toupper(auswahl);
            if (int(auswahl) >= 65 && int(auswahl) <= 71) {
                if (push_field(spielfeld, auswahl, spieler[current_player].sign)) {
                    print_field(spielfeld);
                    winner = check_winner(spielfeld, spieler);
                    back = true;
                } else {
                    print_field(spielfeld);
                    cout << "Dieses Feld ist schon voll! Versuchen Sie ein anderes.\nEingabe: ";
                }
            } else if (auswahl == 'Q')
                back = true;
            else
                cout << "Fehlerhafte Eingabe, versuchen Sie es erneut!\nEingabe: ";
        } while (!back);

        current_player = !current_player;
    } while (auswahl != 'Q' && !winner);
}

bool push_field(char (&spielfeld)[6][7], char field, char sign) {
    int cell = int(field) % 65;
    int is_set = false;

    for (int i = 5; i >= 0; i--) {
        if (spielfeld[i][cell] == '*') {
            spielfeld[i][cell] = sign;
            is_set = true;
            break;
        }
    }
    return is_set;
}

void print_field(char spielfeld[6][7]) {
    for (int i = 65; i < 72; i++)
        cout << char(i) << " ";

    for (int i = 0; i < 6; i++) {
        cout << endl;
        for (int k = 0; k < 7; k++) {
            cout << spielfeld[i][k] << " ";
        }
    }
    cout << "\n\n\n";
}

bool check_winner(char spielfeld[6][7], vector<_player> &spieler) {
    bool unentschieden = true;
    for (int i = 0; i < 6; i++) {
        for (int k = 0; k < 7; k++) {
            char pattern = spielfeld[i][k];

            if (pattern != '*') {
                int senkrecht_i = i + 1, waagerecht_k = k + 1, diagonal_i = i + 1, diagonal_k = k + 1;
                if (i > 2)
                    diagonal_i = i - 1;

                bool senkrecht = true, waagerecht = true, diagonal = true;
                while (senkrecht || waagerecht || diagonal) {
                    //Senkrecht
                    if (senkrecht && i < 3 && spielfeld[senkrecht_i][k] == pattern)
                        senkrecht_i++;
                    else
                        senkrecht = false;

                    //Waagerecht
                    if (waagerecht && k < 4 && spielfeld[i][waagerecht_k] == pattern)
                        waagerecht_k++;
                    else
                        waagerecht = false;

                    //Diagonal
                    if (diagonal && k < 4 && spielfeld[diagonal_i][diagonal_k] == pattern) {
                        if (i < 3)
                            diagonal_i++;
                        else
                            diagonal_i--;
                                               
                        diagonal_k++;
                    } else
                        diagonal = false;

                    //Ergebnis
                    if (senkrecht_i - i > 3 || waagerecht_k - k > 3 || diagonal_k - k > 3) {
                        for (int g = 0; g < 2; g++)
                            if (spieler[g].sign == pattern) {
                                cout << spieler[g].name << " hat gewonnen!\n\n";
                                spieler[g].score++;
                                return true;
                            }
                    }
                }
            }
            else
                unentschieden = false;
        }
    }
    
    if (unentschieden)
    {
        cout << "Das Spiel endete unentschieden!\n\n";
        return true;
    }
    else
        return false;
}