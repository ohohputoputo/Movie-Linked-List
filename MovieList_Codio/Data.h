#pragma once
namespace ns
{

	class MovieList
	{
		private:
			struct MovieNode
			{
				int movieCode;
				std::string movieTitle;
				std::string movieGenre;
				int yearReleased;
				struct MovieNode *next;
			};
			MovieNode *head = NULL;			
		public:
			// 0 Destructor, deletes everything in the List before deleting this Object
			~MovieList();

			// 1 Inserts a Movie to the List in ascending order by movie Code
			void insertMovie(int movieCode, std::string movieTitle, std::string movieGenre, int yearReleased);
			// 2 Deletes a Movie from the List
			void rentMovie(int code);
			// 3 Appends a Movie from the List
			void returnMovie(int movieCode, std::string movieTitle, std::string movieGenre, int yearReleased);
			// 4 Find the desired Movie Code then returns Movie
			void showMovieDetails(int code);
			// 5 Prints all the Movies in the List
			void printMovies();
			// prints the contents of the MovieNode
			void printDetails(MovieNode movie);
	};
	
}