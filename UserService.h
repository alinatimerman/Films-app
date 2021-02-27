#pragma once
#include "Repository.h"

class UserService {
	
private:
	Repository repository;

public:
	/*
		UserService constructor
		in: an object of type repository
		out: returns the object of type UserService containing the given repository
	*/
	UserService(Repository repository);

	/*
		returns the list of films
		in: -
		out: a vector of objects of type Film containing all the films
	*/
	vector<Film> getFilmsListUser();

	/*
		adds a film to the watch list
		in: the film we want to add
		out: true if the film with given credentials was added to the watch list
			 false if the film with given credentials couldn't be added to the list ( a film with the same title already exists in the watch list )
	*/
	bool addFilmToWatchListUser(Film film);

	/*
		deletes a film from the watch list
		in: the title of the film we want to delete
		out: true if the film was deleted from the watch list
			 false if the film couldn't be deleted ( no film with the given title exists in the watch list )
	*/
	bool deleteFilmFromWatchListUser(string givenTitle);

	/*
		returns the watch list
		in: -
		out: a vector of objects of type Film containing all the films from the watch list
	*/
	vector<Film> getWatchListUser();

	/*
		returns the list of films of the given genre
		in: the genre of the films we want to return
		out: a vector of objects of type Film containing all the films with teh given genre
	*/
	vector<Film> getFilmsByGenreUser(string givenGenre);
};