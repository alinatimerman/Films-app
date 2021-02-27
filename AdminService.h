#pragma once
#include "Repository.h"

class AdminService {

private:
	Repository repository;

public:
	/*
		AdminService constructor
		in: an object of type repository
		out: returns the object of type AdminService containing the given repository
	*/
	AdminService(Repository repository);

	/*
		adds a film to the films list 
		in: title, genre, yearOfRelease, time, location and trailer of the film we want to add
		out: true if the film with given credentials was added to the list
			 false if the film with given credentials couldn't be added to the list ( a film with the same title already exists in the list )
	*/
	bool addFilmAdmin(string givenTitle, string givenGenre, int givenYearOfRelease, float givenTime, string givenLocation, string givenTrailer);

	/*
		deletes a film from the films list
		in: the title of the film we want to delete
		out: true if the film was deleted from the list
			 false if the film couldn't be deleted ( no film with the given title exists in the list )
	*/
	bool deleteFilmAdmin(string givenTitle);

	/*
		updates a film in the films list
		in: title, genre, yearOfRelease, time, location and trailer of the updated film
		out: true if the film was updated
			 false if the film couldn't be updated ( no film with the given title exists in the list )
	*/
	bool updateFilmAdmin(string givenTitle, string givenGenre, int givenYearOfRelease, float givenTime, string givenLocation, string givenTrailer);

	/*
		returns the list of films
		in: -
		out: a vector of objects of type Film containing all the films
	*/
	vector<Film> getFilmsListAdmin();
};