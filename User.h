#pragma once
#include <string>
#include "Film.h"
#include <unordered_map>
#include "LinkedListFilm.h"
class User
{
	//move those around if you need
private:
	
public:
	string nom;
	string password; //employee/admin seulement
	bool employee;
	int money;
	int ptsFidelites;
	int age;
	string genrePreferee;
	unordered_map<Film*, pair<double, string>> films_ratings_comments;
	LinkedListFilm UserFilms;
	
	//Constructeur
	User(string nom,string password, bool employee,int money,int ptsFidelites,int age,string genrePreferee,unordered_map<Film*, pair<double, string>> films_ratings_comments);
	User(string nom, bool employee,int money,int ptsFidelites,int age,string genrePreferee,unordered_map<Film*, pair<double, string>> films_ratings_comments);
	//ajouter un constructeur qui prends un LinkedListFilm de fait?

	//le user track ces ratings et commentaires pour chaque video
	void addRating(Film* film, double rating, string comment); //call ca pour ajouter un rating et commentaire
	double getAverageRating() const;
	string getComment(Film* film) const;
	void printAllRatings() const; //montrer tous les ratings et commentaires fait par le user

	bool GestionEmploye(string nomAdmin, string passwordAdmin);
	void displayMenu();
	int MenuManager();
	void ListEmploye();
	void printEmployeeIDs(); 
	void SaleCheck();
	void UpdateMovie();
	int FidelityPoints();
	void calculatePoints(const string& nom, int numTickets, unordered_map<string, int>& pointsMap);
	void MovieReconmendation(User MyUser);

	
	
};