#pragma once
#include <string>
#include <list>
#include "SalleCinema.h"
#include "User.h"
#include <queue>
class Reservation
{
    //move those around if you need
private:


    string userReservant;
    string heureReservation;
    SalleCinema salle;
    int siege;

    int movie_;
    int groupsize;
    int row;
    int seat;
    int salleID;

public:
    //Constructeur
    Reservation(int movie, int group_size, int row, int seat, string user, string time, int _salleID);
};