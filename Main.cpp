//Main.cpp : This file contains the 'main' function.Program execution begins and ends there.
//
#pragma once
#include <iostream>
#include "RabaisTreeGroupe.h"
#include "Cinema.h"
#include "SearchTreeSalle.h"
#include "AVLTreeFilm.h"

using namespace std;

int readInt() {
    int value;
    cout << "Enter a numerical value: ";
    cin >> value; // transfers the entered value
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(512, '\n');
        cout << "Warning – numerical value!: ";
        cin >> value;
    }
    cin.ignore(512, '\n');
    cout << value << endl;
}

int main()
{
#pragma region creerVariables
    //CREER UN CINEMA, DES SALLES, DES FILMS ET AU MOINS 3 USERS (1 CLIENT, 1 EMPLOYEE, 1 ADMIN)
    // 
    // Users
    unordered_map<Film*, pair<double, string>> films_ratings_comments; //hash table de base d'unuser pour ses reviews/comments
    User uAdmin("Jean", "1", true, 100, 17, 43, NULL, films_ratings_comments); //Admin
    User uPaul("Paul", "2", true, 120, 10, 24, NULL, films_ratings_comments); //Employee
    User uTom("Tom", false, 50, 7, 14, "drame", films_ratings_comments);//Client
    // 
    // 
    // LinkedListFilm
    LinkedListFilm mesFilms;
    // Films
    Film topGun("Top Gun", 130, 'M', "drame", "Tom Cruise dans un avion", "Des avions, ca va vite -Top Gun", "Tom Cruise", "Paul Byron");
    Film johnWick("John Wick", 100, 'M', "action", "Venger son chien: le film", "Bang t'es mort -John Wick", "Keanu Reeves", "John Cena");
    Film peter("Peter", 30, 'E', "comedie", "Peter tombe a terre", "Ayoye -Peter", "Mon cousin", "Samuel");
    Film fureur("Fureur", 90, 'T', "drame", "L'ecole c'est plate", "ZZZZZZ -Fureur", "Omar Si", "Quelqu'un");

    mesFilms.insertFilm(topGun);
    mesFilms.insertFilm(johnWick);
    mesFilms.insertFilm(peter);
    mesFilms.insertFilm(fureur);
    // 
    // 
    // SallesCinema
    list<SalleCinema> mesSalles;
    SalleCinema salle1("SalleImax", 1, topGun, "12h30", "14h40", false); //call sur elle pour des methodes
    SalleCinema salle2("SalleBleue", 2, johnWick, "14h", "15h40", false);
    SalleCinema salle3("SalleVerte", 3, peter, "12h30", "13h", false);
    SalleCinema salle4("SalleMode", 4, fureur, "10h30", "12h", true);

    mesSalles.push_back(salle1);
    mesSalles.push_back(salle2);
    mesSalles.push_back(salle3);
    mesSalles.push_back(salle4);

    //Search tree salle
    SearchTreeSalle mySearchTree;

    // Reservations queue
    queue<Reservation> qReservationsCinema;
    //Cinema
    Cinema monCinema("Guzzo", mesSalles, mesFilms, uAdmin, 10, qReservationsCinema);
    salle1.basePrice = monCinema.prixBillet;

    //AVL tree
    AVLTree avlTree;
    avlTree.insert(topGun);
    avlTree.insert(johnWick);
    avlTree.insert(peter);
    avlTree.insert(fureur);

    //arbre rabais groupe
    RabaisTreeGroupe treeRabais;
    treeRabais.insertNode(1, 0);
    treeRabais.insertNode(2, 0);
    treeRabais.insertNode(3, 1);
    treeRabais.insertNode(4, 1);
    treeRabais.insertNode(5, 1);
    treeRabais.insertNode(6, 2);
    treeRabais.insertNode(7, 2);
    treeRabais.insertNode(8, 3);
    treeRabais.insertNode(9, 3);
    treeRabais.insertNode(10, 3);
#pragma endregion

    


    int choix;
    string nomFilmChercher;
    do//menu/interface ou on demande et genere un cinema
    {
        cout << "Pas tout le code est lier dans le main.cpp, mais la grande majorite est la. On a manquer de temps mettre tout ensemble." << endl;
        cin >> nomFilmChercher;
        system("cls"); //clear l'ecran
        cout << "Etes-vous un employer?" << endl;
        cout << " 1) oui" << endl;
        cout << " 2) non" << endl;
        cout << " 0) Quitter" << endl;
        choix = readInt();
        switch (choix)
        {
        case 1:
            bool valid = false;
            int mdp;
            do
            {
                cout << "Entrer votre mot de passe: (1 admin) (2 employee):" << endl; // temp debug
                mdp = readInt();
                if (mdp == 1 || mdp == 2)
                {
                    valid = true;
                }
            } while (!valid);
            if (mdp == 1)
            {
                uAdmin.MenuManager();
            }
            else
            {
                do
                {
                    cout << "Travailler?" << endl;
                    cout << " 1) oui" << endl;
                    cout << " 2) non" << endl;
                    cout << " 0) Quitter" << endl;
                    choix = readInt();
                    if (choix == 1)
                    {
                        uPaul.money += 100;
                    }
                } while (choix != 0 || choix != 2);
            }
            break;
        case 2:
            //demander si user existe et creer nouveau user ici
            //on va juste faire Tom, manque de temps

            //menu principal
            do
            {
                cout << "Que voulez-vous faire?" << endl;
                cout << " 1) Voir films a l'affiche" << endl;
                cout << " 2) Voir prochaine diffusion film precis" << endl;
                cout << " 3) Voir les salles et leur diffusion" << endl;
                cout << " 4) Reserver billets" << endl;
                cout << " 5) Recommander film" << endl;
                cout << " 0) Quitter" << endl;
                choix = readInt();
                switch (choix)
                {
                case 1:
                    mesFilms.displayList();
                    break;
                case 2:
                    cout << "Entrer nom film:" << endl;
                    cin >> nomFilmChercher;
                    avlTree.displayByTitle(nomFilmChercher);

                    break;
                case 3:
                    for (int i = 0; i < mesSalles.size(); i++)
                    {
                        //diffuser infos salles
                    }
                    break;
                case 4:
                    salle1.make_Reservation(treeRabais);
                    break;
                case 5:
                    uTom.MovieReconmendation(uTom);
                    break;
                default:
                    break;
                }

            } while (choix != 0);
            break;
        case 0:
            cout << "Vous quitter l'application..." << endl;
            break;
        default:
            break;
        }
    } while (choix != 0);
    //ajouter ici les methodes vider les donnees AKA destructor
    return 0;
}