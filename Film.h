#pragma once
#include <string>
#include <unordered_map>
class Film 
{
	//move those around if you need
private:
	unordered_map<double, string> ratings_comments; //hash table

public:
	//Constructeur
	string titre;
	int duree;
	char ageRating;
	string synopsis;
	string publicite;
	string genre;
	string acteurPrincipal;
	string realisateur;
	double reviewScore; //de 0 a 10

	Film(string titre, int duree, char rating,string genre, string synopsis,string publicite, string acteur, string realisateur);
	
	//fonctions seulement pour ajouter et obtenir des ratings et commentaire
	void addRating(double rating, string comment); //add un rating et commentaire a cette video
	double getRating() const; //donne la note moyenne du film selon les ratings
	string getComment() const;
};