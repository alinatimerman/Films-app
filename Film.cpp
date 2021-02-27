#include "Film.h"

Film::Film(const string& givenTitle, const string& givenGenre, const int givenYearOfRelease, const float givenTime, const string& givenLocation, const string& givenTrailer)
{
	this->title = givenTitle;
	this->genre = givenGenre;
	this->yearOfRelease = givenYearOfRelease;
	this->time = givenTime;
	this->location = givenLocation;
	this->trailer = givenTrailer;
}

const string& Film::getTitle()
{
	// TODO: insert return statement here
	return this->title;
}

const string& Film::getGenre()
{
	// TODO: insert return statement here
	return this->genre;
}

const int Film::getYearOfRelease()
{
	return this->yearOfRelease;
}

const float Film::getTime()
{
	return this->time;
}

const string& Film::getLocation()
{
	// TODO: insert return statement here
	return this->location;
}

const string& Film::getTrailer()
{
	// TODO: insert return statement here
	return this->trailer;
}

bool Film::operator==(const Film& film) const
{
	return (this->title == film.title);
}

string Film::toString()
{
	return this->title + ", " + this->genre + ", " + to_string(this->yearOfRelease) + ", " + to_string((int)this->time) + ", " + this->location + ", " + this->trailer;
}
