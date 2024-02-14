#include "Film.h"
#include <iostream>


using namespace std;

Film::Film(string titre, int duree, char rating, string genre, string synopsis, string publicite, string acteur, string realisateur)
:titre(titre), duree(duree), ageRating(rating), genre(genre), synopsis(synopsis), publicite(publicite),acteurPrincipal(acteur), realisateur(realisateur), reviewScore(5) {}


//Code baser sur exemple fourni par prof, puis modifier avec recherche et documentation en ligne
void Film::addRating(double rating, string comment) {
	ratings_comments[rating] = comment;
}

double Film::getRating() const {
	double sum = 0;
	for (const auto& rating : ratings_comments) //
	{
		sum += rating.first;
	}
	return sum / ratings_comments.size(); //donne la note moyenne du film
}

string Film::getComment() const {
	if (ratings_comments.empty())
	{
		return " ";
	}
	return ratings_comments.begin()->second;
}