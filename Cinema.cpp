#include "Cinema.h"
#include <iostream>

using namespace std;

Cinema::Cinema(string nomCinema, list<SalleCinema> mesSalles, LinkedListFilm mesFilms, User admin, int prixBillet, queue<Reservation> qReservationsCinema)
:nomCinema(nomCinema), mesSalles(mesSalles), mesFilms(mesFilms), admin(admin), prixBillet(prixBillet), qReservationsCinema(qReservationsCinema) {}
