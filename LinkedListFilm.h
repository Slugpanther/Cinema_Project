#pragma once
#include <iostream>
#include "Film.h"
#include <vector>
using namespace std;

class LinkedListFilm {
private:
    class NodeFilm {
    public:
        Film data;
        NodeFilm* next;
        NodeFilm(Film data) {
            this->data = data;
            this->next = NULL;
        }
    };
    NodeFilm* head;

public:
    LinkedListFilm();
    ~LinkedListFilm();
    void insertFilm(Film data);
    void removeFilm(Film data);
    void displayList();
    int getLength();
    void clear();

    vector<Film*> searchByTitle(string title);
    vector<Film*> searchByDuration(int duration);
    vector<Film*> searchByRating(char rating);
    vector<Film*> searchByGenre(string genre);
    vector<Film*> searchByActor(string actor);
    vector<Film*> searchByProducer(string producer);
  


};