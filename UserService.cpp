#include "UserService.h"

UserService::UserService(Repository repository)
{
	this->repository = repository;
}

vector<Film> UserService::getFilmsListUser()
{
	return this->repository.getFilmsList();
}

bool UserService::addFilmToWatchListUser(Film film)
{
	return this->repository.addFilmToWatchList(film);
}

bool UserService::deleteFilmFromWatchListUser(string givenTitle)
{
	return this->repository.deleteFilmFromWatchList(givenTitle);
}

vector<Film> UserService::getWatchListUser()
{
	return this->repository.getWatchList();
}

vector<Film> UserService::getFilmsByGenreUser(string genre)
{
	return this->repository.getFilmsByGenre(genre);
}
