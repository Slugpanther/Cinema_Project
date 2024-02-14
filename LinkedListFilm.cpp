//Code basee sur example fourni par le prof et de la documentation en ligne

#include <iostream>
#include "Film.h"
#include "LinkedListFilm.h"

using namespace std;

LinkedListFilm::LinkedListFilm() {
	head = NULL;
}
LinkedListFilm::~LinkedListFilm() {
	NodeFilm* current = head;
	while (current != nullptr) {
		NodeFilm* temp = current->next;
		delete current;
		current = temp;
	}
}
void LinkedListFilm::insertFilm(Film data) {
	NodeFilm* new_node = new NodeFilm(data);
	if (head == NULL) {
		head = new_node;
	}
	else {
		NodeFilm* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
	}
}
void LinkedListFilm::removeFilm(Film data) {
	NodeFilm* temp = head;
	NodeFilm* prev = NULL;
	if (temp == NULL) {
		return;
	}
	if (head->data.titre == data.titre) {
		NodeFilm* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	while (temp != NULL && temp->data.titre != data.titre) {
		prev = temp;
		temp = temp->next;
	}
	
	if (prev == NULL) {
		head = temp->next;
	}
	else {
		prev->next = temp->next;
	}
	delete temp;
}
void LinkedListFilm::displayList() {
	NodeFilm* temp = head;
	while (temp != NULL) {
		cout << temp->data.titre << " || " << temp->data.duree << " minutes || " << temp->data.ageRating << endl;
		temp = temp->next;
	}
	cout << endl;
}

vector<Film*> LinkedListFilm::searchByActor(string actor) {
	vector<Film*> myFilms;
	NodeFilm* temp = head;
	while (temp != NULL)
	{
		if (temp->data.acteurPrincipal == actor)
		{
			myFilms.push_back(&temp->data);
		}
		temp->next;
	}
	return myFilms;
}
vector<Film*> LinkedListFilm::searchByProducer(string producer) {
	vector<Film*> myFilms;
	NodeFilm* temp = head;
	while (temp != NULL)
	{
		if (temp->data.realisateur == producer)
		{
			myFilms.push_back(&temp->data);
		}
		temp->next;
	}
	return myFilms;
}
vector<Film*> LinkedListFilm::searchByTitle(string title) {
	vector<Film*> myFilms;
	NodeFilm* temp = head;
	while (temp != NULL)
	{
		if (temp->data.titre == title)
		{
			myFilms.push_back(&temp->data);
		}
		temp->next;
	}
	return myFilms;
}

vector<Film*> LinkedListFilm::searchByGenre(string genre) {
	vector<Film*> myFilms;
	NodeFilm* temp = head;
	while (temp != NULL)
	{
		if (temp->data.genre == genre)
		{
			myFilms.push_back(&temp->data);
		}
		temp->next;
	}
	return myFilms;
}

vector<Film*> LinkedListFilm::searchByDuration(int duration) {
	vector<Film*> myFilms;
	NodeFilm* temp = head;
	while (temp != NULL)
	{
		if (temp->data.duree == duration)
		{
			myFilms.push_back(&temp->data);
		}
		temp->next;
	}
	return myFilms;
}

vector<Film*> LinkedListFilm::searchByRating(char rating) {
	vector<Film*> myFilms;
	NodeFilm* temp = head;
	while (temp != NULL)
	{
		if (temp->data.ageRating == rating)
		{
			myFilms.push_back(&temp->data);
		}
		temp->next;
	}
	return myFilms;
}

//FONCTION PAS USER A DATE

//Get Length: This function is used to get the number of nodes in the list.
int LinkedListFilm::getLength() {
	NodeFilm* temp = head;
	int count = 0;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}
//Clear List: This function is used to delete all the nodes in the list.
void LinkedListFilm::clear() {
	NodeFilm* temp = head;
	while (temp != NULL) {
		NodeFilm* next = temp->next;
		delete temp;
		temp = next;
	}
	head = NULL;
}
