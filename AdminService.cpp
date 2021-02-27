#include "AdminService.h"

AdminService::AdminService(Repository repository)
{
	this->repository = repository;
}

bool AdminService::addFilmAdmin(string givenTitle, string givenGenre, int givenYearOfRelease, float givenTime, string givenLocation, string givenTrailer)
{
	Film newFilm(givenTitle, givenGenre, givenYearOfRelease, givenTime, givenLocation, givenTrailer);
	return repository.addFilm(newFilm);
}

bool AdminService::deleteFilmAdmin(string givenTitle)
{
	return repository.deleteFilm(givenTitle);
}

bool AdminService::updateFilmAdmin(string givenTitle, string givenGenre, int givenYearOfRelease, float givenTime, string givenLocation, string givenTrailer)
{
	Film updatedFilm(givenTitle, givenGenre, givenYearOfRelease, givenTime, givenLocation, givenTrailer);
	return repository.updateFilm(updatedFilm);
}

vector<Film> AdminService::getFilmsListAdmin()
{
	return repository.getFilmsList();
}
