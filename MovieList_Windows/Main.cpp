#include <iostream>
#include <string> // import getline
#include "Data.h"
using namespace std;
using namespace ns;

int menu();

int main()
{
	MovieList movieList;
	float num;
	int ch;

	do
	{
		ch = menu();
		// system("cls");
		if (ch == 1)
		{
			string input;

			cout << " << Returning a Movie >> " << endl << endl;
			cout << "Enter a Movie Code: ";
			int movieCode = 0;
			getline(cin, input);
			movieCode = stoi(input); // convert input string to int

			cout << "Enter a Movie Title: ";
			string movieTitle;
			getline(cin, movieTitle);

			cout << "Enter a Movie Genre: ";
			string movieGenre;
			getline(cin, movieGenre);

			cout << "Enter a Year Released: ";
			int yearReleased;
			getline(cin, input);
			yearReleased = stoi(input); // convert input string to int

			movieList.returnMovie(movieCode, movieTitle, movieGenre, yearReleased);
		}
		else if (ch == 2)
		{
			string input;

			cout << " << Inserting new Movie >> " << endl << endl;
			cout << "Enter a Movie Code: ";
			int movieCode = 0;
			getline(cin, input);
			movieCode = stoi(input); // convert input string to int

			cout << "Enter a Movie Title: ";
			string movieTitle;
			getline(cin, movieTitle);

			cout << "Enter a Movie Genre: ";
			string movieGenre;
			getline(cin, movieGenre);

			cout << "Enter a Year Released: ";
			int yearReleased;
			getline(cin, input);
			yearReleased = stoi(input); // convert input string to int

			// inserts the movie depending on movie Code in ascending order
			movieList.insertMovie(movieCode, movieTitle, movieGenre, yearReleased);
		}
		else if (ch == 3)
		{
			cout << " << Renting a Movie >> " << endl << endl;
			cout << "Enter the Movie Code#: ";
			string input;
			int movieCode;
			getline(cin, input);
			movieCode = stoi(input);

			movieList.rentMovie(movieCode);
		}

		else if (ch == 4)
		{
			cout << " << Printing List of Movies >> " << endl << endl;
			movieList.printMovies();
      		system("pause");
		}
		else if (ch == 5)
		{
			cout << " << Showing Movie Details >> " << endl << endl;
			cout << "Enter the Movie Code to display#: ";
			string input;
			int movieCode;
			getline(cin, input);
			movieCode = stoi(input);

			movieList.showMovieDetails(movieCode);

      		system("pause");
		}
		else if (ch == 6)
		{
			cout << "Thank you for using the program!" << endl; 
			movieList.~MovieList();
			exit(0);
		}
		else
		{
			cout << "Invalid Input!" << endl << endl;
			break;
		}
		cout << endl;
	} while (ch >= 1 && ch <= 5);
}


int menu()
{
	int ch;
	string input;
	system("cls");
	cout << " << Binary Brains Video Store >> " << endl << endl;
	cout << "[1] Return a Movie" << endl;
	cout << "[2] Insert a New Movie" << endl; // 1
	cout << "[3] Rent a Movie" << endl;
	cout << "[4] Print List of Movies" << endl;
	cout << "[5] Show Movie Details" << endl;
	cout << "[6] Quit the Program" << endl << endl;
	cout << "Enter Choice: ";
	getline(cin, input);
	ch = stoi(input);
	return(ch);
}