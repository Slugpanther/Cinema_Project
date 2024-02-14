#include "User.h"
#include "Film.h"
#include <string>
#include <iostream>

using namespace std;
User::User(string nom, string password, bool employee, int money, int ptsFidelites, int age, string genrePreferee, unordered_map<Film*, pair<double, string>> films_ratings_comments)
:nom(nom),password (password), employee(employee), money(money), ptsFidelites(ptsFidelites), age(age), genrePreferee(genrePreferee),films_ratings_comments(films_ratings_comments){
    LinkedListFilm mesFilms;
}
User::User(string nom, bool employee, int money, int ptsFidelites, int age, string genrePreferee, unordered_map<Film*, pair<double, string>> films_ratings_comments)
:nom(nom), employee(employee), money(money), ptsFidelites(ptsFidelites), age(age), genrePreferee(genrePreferee), films_ratings_comments(films_ratings_comments) {
    LinkedListFilm mesFilms;
}


void User::addRating(Film* film, double rating, string comment) {
	films_ratings_comments[film] = make_pair(rating, comment);
}

double User::getAverageRating() const {
    double sum = 0;
    for (const auto& rating_comment : films_ratings_comments) { //auto& const accede a qqch en read-only si j'ai bien compris lol
        sum += rating_comment.second.first;
    }
    return sum / films_ratings_comments.size();
}

string User::getComment(Film* film) const {
    auto it = films_ratings_comments.find(film); //auto fait une copie de l'element sans y faire reference..? pas sur mais c ce qu'internet dit
    if (it == films_ratings_comments.end()) {
        return " ";
    }
    return it->second.second;
}

void User::printAllRatings() const {
    cout << "Ratings and comments for " << nom << ":" << std::endl;
    for (const auto& p : films_ratings_comments) {
        string ratingStr = to_string(p.second.first); //converts the double to_string
        string comment = p.second.second;
        string videoStr = p.first->titre;
        cout << videoStr << ": " << ratingStr << " stars - " << comment << std::endl;
    }
}

bool User::GestionEmploye(string nomAdmin, string passwordAdmin)
{
    const string Manager_Id = "Manager";
    const string Manager_Password = "Cinema";
    if (nomAdmin == Manager_Id && passwordAdmin == Manager_Password) {
        return true;
    }
    else {
        return false;
    }

    MenuManager();


   
}
void User::displayMenu()
{
    cout << "Welcome, Manager!" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Check employee list" << endl;
    cout << "2. Follow sales" << endl;
    cout << "3. Update movie schedule and info" << endl;
    cout << "4. Exit" << endl;
}
int User:: MenuManager()
{
    string nomAdmin;
    string passwordAdmin;

    cout << "Please enter your manager ID: ";
    cin >> nomAdmin;

    cout << "Please enter your password: ";
    cin >> passwordAdmin;

    if (GestionEmploye(nomAdmin, passwordAdmin)) {
        int choice;

        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Checking employee list..." << endl;
                void ListEmploye();
                break;
            case 2:
                cout << "Following sales..." << endl;
                FidelityPoints();
                break;
            case 3:
                cout << "Updating movie schedule amd info..." << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        } while (choice != 5);
    }
    else {
        cout << "Invalid ID or password. Access denied." << endl;
    }

    return 0;
}


struct Employee {
    string name;
    int id;
};

void printEmployeeIDs(const list<Employee>& employees) {  
    for (const auto& employee : employees) {
        cout << "Employee name: " << employee.name << ", ID: " << employee.id << "\n";  
    }
}

int  ListEmpoloye() {
    list<Employee> employees = { {"Alice", 123}, {"Bob", 456}, {"Charlie", 789} };
    printEmployeeIDs(employees);
    return 0;
}




 int FidelityPoints(){
     unordered_map<string, int> pointsMap;

     while (true) {
         string nom;
         int numTickets;

         cout << "Enter your name (or 'quit' to exit): ";
         cin >> nom;

         if (nom == "quit") {
             break;
         }

         cout << "Enter the number of movie tickets you have purchased: ";
         cin >> numTickets;

         calculatePoints(nom, numTickets, pointsMap);
     }

     // display the total points for each user
     for (const auto& entry : pointsMap) {
         cout << entry.first << " has " << entry.second << " points." << endl;
     }

     return 0;

};


 void calculatePoints(const string& nom, int numTickets, unordered_map<string, int>& pointsMap) {
     int points = numTickets / 2; // each ticket is worth 2 points
     pointsMap[nom] += points; // add points to the user's total
     cout << "Congratulations, " << nom << "!" << endl;
     cout << "You have earned " << points << " points." << endl;
 }

 void MovieReconmendation(User MyUser) 
 {
     vector<Film*> MyMovies;
     // ask user if they want to see movies by age or by genre
     cout << "Do you want to see a list of movies by age or by genre? (Enter A for age, G for genre): ";
     char choice;
     cin >> choice;
     switch (choice)
     {
     case 1:
         cout << "Search by age group" << endl;
         if (MyUser.age <12)
         {
             MyMovies = MyUser.UserFilms.searchByRating('E');
         }
         else if(MyUser.age> 12 && MyUser.age<17)
         {
             MyMovies = MyUser.UserFilms.searchByRating('T');
         }
         else
         {
             MyMovies = MyUser.UserFilms.searchByRating('M');
         }
         
         break;
     case 2:
         cout << "Search by your fav genre" << endl;
         MyMovies = MyUser.UserFilms.searchByGenre(MyUser.genrePreferee);
         
             break;
     default:
         break;
     }

     
 }






