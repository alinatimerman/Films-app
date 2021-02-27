#pragma once
#include "Film.h"

class Repository {

private:
	vector<Film> filmsList = {};
	vector<Film> watchList = {};

public:
	/*
		repository constructor
		creates a new object of type Repository
	*/
	Repository();

	/*
		adds a new film to the filmsList
		in: the film which we want to add
		out: true if the film was added successfully
			 false if the film couldn't be added ( a film with the same title already exists in the list )
	*/
	bool addFilm(Film newFilm);			

	/*
		deletes a film from the list
		in: the title of the film we want to delete from the list
		out: true if the film was deleted
			 false if the film couldn't be deleted ( no film with the given title was found in the list )
	*/
	bool deleteFilm(string givenTitle);							

	/*
		updates a film in the list
		in: the film with the updated credentials
		out: true if the film was updated
			 false if the film couldn't be updated ( no film with the given title was found in the list )
	*/
	bool updateFilm(Film updatedFilm);							

	/*
		searches a film in the given list
		in: the list in which we want to search the film and the title of the searched film
		out: returns the position of the film with the given title in the given list or -1 if no such film was found
	*/
	int searchFilm(vector<Film> givenList, string givenTitle);	

	/*
		adds a film to the watch list
		in: the film we want to add to the watch list
		out: true if the film was added successfully
			 false if the film couldn't be added ( a film with the same title already exists in the watch list )
	*/
	bool addFilmToWatchList(Film film);							

	/*
		deletes a film from the watch list
		in: the title of the film we want to delete
		out: true if the film was deleted
			 false if the film couldn't be deleted ( no film with the given title was found in the watch list )
	*/
	bool deleteFilmFromWatchList(string givenTitle);			

	/*
		returns the list of films
		in: -
		out: returns a vector of objects of type Film containing the films in the list
	*/
	vector<Film> getFilmsList();								

	/*
	returns the list of films in the watch list
		in: -
		out: returns a vector of objects of type Film containing the films in the watch list
	*/
	vector<Film> getWatchList();								

	/*
		returns a list of films of the given genre
		in: the genre of the films
		out: returns a vector of objects of type Film containing the films in the films list of the given genre
	*/
	vector<Film> getFilmsByGenre(string givenGenre);			

	/*
		initializes the films list with certain films
	*/
	void filmExamples();
};