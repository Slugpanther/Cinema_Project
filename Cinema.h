#pragma once
#include <string>
#include <list>
#include "SalleCinema.h"
#include "User.h"
#include <queue>
#include "Reservation.h"
#include "LinkedListFilm.cpp"
class Cinema
{
	//move those around if you need
private:
	
public:
	//Constructeur
	Cinema(string nomCinema, list<SalleCinema> mesSalles, LinkedListFilm mesFilms,User admin, int prixBillet,queue<Reservation> qReservationsCinema);

	string nomCinema;
	list<SalleCinema> mesSalles;
	//linkedlist des films a ajouter une fois fait
	LinkedListFilm mesFilms;
	User admin;
	int prixBillet;
	//Queue demandes de reservation
	queue<Reservation> qReservationsCinema;
};