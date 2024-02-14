#include "SalleCinema.h"
#include <iostream>
#include "RabaisTreeGroupe.h"
#include "Cinema.h"
using namespace std;

int SalleCinema::readInt() {
    int value;
    cout << "Enter a numerical value: ";
    cin >> value; // transfers the entered value
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(512, '\n');
        cout << "Warning – numerical value!: ";
        cin >> value;
    }
    cin.ignore(512, '\n');
    cout << value << endl;
}


//Constructeur
SalleCinema::SalleCinema(const string& name, int roomID, Film currentFilm, string Start, string Finish, bool isFilmRunning)
    :name(name), salleID(roomID), filmCourant(currentFilm), heureDebut(Start), heureFin(Finish), filmEnCours(isFilmRunning) {
    for (int i = 0; i < ROWS; i++) {
        seats.push_back(vector<bool>(SEATS_PER_ROW, false));
    }
}

void SalleCinema::display_seats() const {
    cout << "Movie Theater Seat Layout" << endl;
    cout << "-------------------------" << endl;

    for (int i = 0; i < ROWS; i++) {
        cout << setw(2) << i + 1 << " ";

        for (int j = 0; j < SEATS_PER_ROW; j++) {
            if (seats[i][j]) {
                cout << "X";
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void SalleCinema::make_Reservation(RabaisTreeGroupe treeRabais) {
    int movie, group_size, row, seat;

    string name;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter movie ID";
    cout << "1 - Top Gun";
    cout << "2 - John Wick";
    cout << "3 - peter";
    cout << "4 - Fureur";
    movie = readInt();
    switch (movie)
    {
    case 1:
    {
        salleID = 1;
    }break;
    case 2:
    {
        salleID = 2;
    }break;
    case 3:
    {
        salleID = 3;
    }break;
    case 4:
    {
        salleID = 4;
    }break;

    default:
        cout << "Enter a valid number!\n";
        break;
    }

    cout << "Enter group size: ";
    group_size = readInt();

    int numberOfPpl = group_size;

    do
    {

        display_seats();
        cout << "Enter row (1-10): ";
        row = readInt();
        cout << "Enter seat (1-20): ";
        seat = readInt();

        if (seats[row - 1][seat - 1]) {
            cout << "Error: Seat " << row << "-" << seat << " is already taken." << endl;
        }
        else
        {
            seats[row - 1][seat - 1] = true;
            numberOfPpl -= 1;
        }
    } while (numberOfPpl > 0);

    // Add the reservation to the list
    //give it to cinema instead?
    sReservationSalle.push(Reservation(movie, group_size, row, seat, name, heureDebut + " - " + heureFin, salleID));
    //ajouter le film aux films vu du user?
    displayRecentBill(group_size,basePrice,treeRabais);
    cout << "Reservation successful!" << endl;
}

void SalleCinema::displayRecentBill(int tickets, int basePrice, RabaisTreeGroupe treeRabais) {
    int tempTickets = tickets;
    if (tickets > 10)
    {
        tempTickets = 10;
    }
    int rabais = treeRabais.searchTree(tempTickets);
    int prixBillet = basePrice - rabais;
    float prixTotal = tickets * prixBillet;
    cout << tickets << " billets a " << prixBillet << "$ = " << prixTotal << endl;
}