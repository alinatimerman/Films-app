#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

class Film {

private:
	string title;
	string genre;
	int yearOfRelease;
	float time;
	string location;
	string trailer;
	
public:
	/*
		film constructor: creates an object of type Film 
		in: title, genre, yearOfRelease, time, location and trailer
		out: creates the film object with the given parameters
	*/
	Film(const string& title = "", const string& genre = "", const int yearOfRelease = 0, const float time = 0, const string& location = "", const string& trailer = "");

	/*
		title getter 
		returns the title of the film
	*/
	const string& getTitle();

	/*
		genre getter
		returns the genre of the film
	*/
	const string& getGenre();

	/*
		yearOfRelease getter
		returns the year of release of the film
	*/
	const int getYearOfRelease();

	/*
		time getter
		returns the duration of the film
	*/
	const float getTime();

	/*
		location getter
		returns the location of the film's first showing
	*/
	const string& getLocation();

	/*
		trailer getter
		returns the link to the trailer of the film
	*/
	const string& getTrailer();

	/*
		redefines the equality relation for objects of type Film
		in: the other film we are comparing this one to
		out: true if the films have the same title
			 false if the films have different titles
	*/
	bool operator==(const Film& film) const;

	string toString();
};