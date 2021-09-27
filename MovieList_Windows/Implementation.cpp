#include <iostream>
#include "Data.h"
using namespace std;
using namespace ns;

// 0
MovieList::~MovieList()
{
	MovieNode *nodePtr, *nextNode;

	nodePtr = head;
	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	cout << "Movie List has been destroyed!" << endl;
}

// 3
void MovieList::returnMovie(int movieCode, string movieTitle, string movieGenre, int yearReleased)
{
	MovieNode *newNode, *nodePtr;
	// Allocate a new node & store the movie data into newNode
	newNode = new struct MovieNode;
	newNode->movieCode = movieCode;
	newNode->movieTitle = movieTitle;
	newNode->movieGenre = movieGenre;
	newNode->yearReleased = yearReleased;
	newNode->next = NULL;
	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
		head = newNode;
	else	// Otherwise, insert newNode at end
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		// Find the last node in the list
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		// Insert newNode as the last node
		nodePtr->next = newNode;
	}
	cout << endl << "Movie has been successfully Appended!" << endl;
}

// 4
void MovieList::showMovieDetails(int code)
{
	MovieList::MovieNode *nodePtr, *previousNode;
	int found = 0;

	// If the list is empty, do nothing.
	if (!head)
	{
		cout << "List is empty!" << endl;
		// throw exception Movie not found
		// throw std::invalid_argument("Invalid code, code does not exist in the List");
	}

	// Determine if the first node is the one.
	if (head->movieCode == code)
	{
		nodePtr = head->next;
		printDetails(*head); // pass to the print movie function to print all the details
		found = 1;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		previousNode = NULL;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != NULL && nodePtr->movieCode != code)
		{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
		}

		// Link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr != NULL)
		{
			printDetails(*nodePtr); // pass to the print movie function to print all the details
			// cout << "Movie Code has been successfully found!" << endl;
			found = 1;
		}
	}
	if (found == 0) {
		cout << "Movie Code is not found in the list!" << endl;
		// throw exception Movie not found
		// throw std::invalid_argument("Invalid code, code does not exist in the List");
	}
	
}

void MovieList::printDetails(MovieNode movie) {
	cout << "Movie Code: " << movie.movieCode << endl;
	cout << "Movie Title: " << movie.movieTitle << endl;
	cout << "Movie Genre: " << movie.movieGenre << endl;
	cout << "Year Released: " << movie.yearReleased << endl;
}

// 2
void MovieList::rentMovie(int code) {
	MovieList::MovieNode *nodePtr, *previousNode;
	int found = 0;

	// If the list is empty, do nothing.
	if (!head)
	{
		cout << "List is empty!" << endl;
		return;
	}

	// Determine if the first node is the one.
	if (head->movieCode == code)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		cout << "Input has been successfully DELETED!" << endl;
		found = 1;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		previousNode = NULL;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != NULL && nodePtr->movieCode != code)
		{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
		}

		// Link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr != NULL)
		 {
			previousNode->next = nodePtr->next;
			delete nodePtr;
			cout << "Input has been successfully DELETED!" << endl;
			found = 1;
		}
	}
	if (found == 0)
		cout << "Input is not found in the list!" << endl;
}

// 5
void MovieList::printMovies()
{
	MovieList::MovieNode *nodePtr;
	if (head == NULL)
		cout << "The list is empty!" << endl;
	else
	{
		cout << "The movie in the list are... " << endl;
		cout << "Format( Code : Movie Title) " << endl << endl;
		nodePtr = head;
		while (nodePtr)
		{
			// print movie Code alongside with movie Title
			cout << "\tCode(" << nodePtr->movieCode << ") : " << nodePtr->movieTitle << endl;
			nodePtr = nodePtr->next;
		}
	}
}

// 1
void MovieList::insertMovie(int movieCode, std::string movieTitle, std::string movieGenre, int yearReleased)
{
	MovieNode *newNode, *nodePtr, *previousNode;

	// Allocate a new node & store Num
	newNode = new MovieNode;
	newNode->movieCode = movieCode;
	newNode->movieTitle = movieTitle;
	newNode->movieGenre = movieGenre;
	newNode->yearReleased = yearReleased;

	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else	// Otherwise, insert newNode.
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		previousNode = NULL;

		// Skip all nodes whose value member is less
		// than num.
		while (nodePtr != NULL && nodePtr->movieCode < movieCode)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		// If the new mode is to be the 1st in the list,
			// insert it before all other nodes.
		if (previousNode == NULL)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
	cout << endl << "Input has been successfully Inserted!" << endl;
}




