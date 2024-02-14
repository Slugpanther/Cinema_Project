#include "Reservation.h"
#include <iostream>

using namespace std;


Reservation::Reservation(int movie, int group_size, int row, int seat, string user, string time, int salleID)
    :movie_(movie), groupsize(groupsize), row(row), seat(seat), userReservant(user), heureReservation(time), salleID(salleID) {}