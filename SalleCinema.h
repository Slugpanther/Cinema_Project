#pragma once
#include <string>
#include <iomanip>
#include "Film.h"
#include <stack>
#include "Reservation.h"
#include "RabaisTreeGroupe.h"
class SalleCinema
{
    //move those around if you need
private:


public:
    string name;
    vector<vector<bool>> seats;

    //stack reservations;
    stack<Reservation> sReservationSalle;
    int basePrice;
    int salleID;
    Film filmCourant;
    string heureDebut;
    string heureFin;
    bool filmEnCours;
    int nbSieges; //en lien avec la matrice de sieges
    const int ROWS = 10;
    const int SEATS_PER_ROW = 20;


    int readInt();

    //Constructeur
    SalleCinema(const string& name, int roomID, Film currentFilm, string Start, string Finish, bool isFilmRunning);


    void display_seats() const;

    void make_Reservation(RabaisTreeGroupe treeRabais);


    void displayRecentBill(int tickets, int basePrice, RabaisTreeGroupe treeRabais);
};