#include "Repository.h"

Repository::Repository()
{
}

bool Repository::addFilm(Film newFilm)
{
	if (searchFilm(filmsList, newFilm.getTitle()) != -1)
		return false;
	filmsList.push_back(newFilm);
	return true;
}

bool Repository::deleteFilm(string givenTitle)
{
	int foundFilmIndex = searchFilm(filmsList, givenTitle);
	if (foundFilmIndex == -1)
		return false;
	filmsList.erase(filmsList.begin() + foundFilmIndex);
	return true;
}

bool Repository::updateFilm(Film updatedFilm)
{
	int foundFilmIndex = searchFilm(filmsList, updatedFilm.getTitle());
	if (foundFilmIndex == -1)
		return false;
	filmsList[foundFilmIndex] = updatedFilm;
	return true;
}

int Repository::searchFilm(vector<Film> givenList, string givenTitle)
{
	for (int i = 0; i < givenList.size(); ++i)
		if (givenList[i].getTitle() == givenTitle)
			return i;
	return -1;
}

bool Repository::addFilmToWatchList(Film film)
{
	if (searchFilm(watchList, film.getTitle()) != -1)
		return false;
	watchList.push_back(film);
	return true;
}

bool Repository::deleteFilmFromWatchList(string title)
{
	int foundFilmIndex = searchFilm(watchList, title);
	if (foundFilmIndex == -1)
		return false;
	watchList.erase(watchList.begin() + foundFilmIndex);
	return true;
}

vector<Film> Repository::getFilmsList()
{
	return this->filmsList;
}

vector<Film> Repository::getWatchList()
{
	return this->watchList;
}

vector<Film> Repository::getFilmsByGenre(string givenGenre)
{
	vector<Film> filmsWithGivenGenre;
	vector<Film> filmsList = getFilmsList();
	Film film("", "", 0, 0, "", "");

	for (int i = 0; i < filmsList.size(); ++i) {
		film = filmsList[i];
		if (film.getGenre() == givenGenre)
			filmsWithGivenGenre.push_back(film);
	}

	return filmsWithGivenGenre;
}

void Repository::filmExamples()
{
	Film film1 ("1917", "Drama", 2019, 119, "USA", "https://www.imdb.com/video/vi4095655705?playlistId=tt8579674&ref_=tt_ov_vi");
	addFilm(film1);
	Film film2 ("A Clockwork Orange", "Crime", 1971, 136, "USA", "https://www.imdb.com/video/vi4030506521?playlistId=tt0066921&ref_=tt_ov_vi");
	addFilm(film2);
	Film film3 ("Cold war", "History", 2018, 89, "USA", "https://www.imdb.com/video/vi237484569?playlistId=tt6543652&ref_=tt_ov_vi");
	addFilm(film3);
	Film film4 ("Vertigo", "Mystery", 1958, 128, "UK", "https://www.imdb.com/video/vi216072473?playlistId=tt0052357&ref_=tt_ov_vi");
	addFilm(film4);
	Film film5 ("Little Women", "Romance", 2019, 135, "USA", "https://www.imdb.com/video/vi2655304729?playlistId=tt3281548&ref_=tt_ov_vi");
	addFilm(film5);
	Film film6 ("Taxi Driver", "Crime", 1976, 114, "USA", "https://www.imdb.com/video/vi474987289?playlistId=tt0075314&ref_=tt_ov_vi");
	addFilm(film6);
	Film film7 ("Solo: A Star Wars Story", "Action", 2018, 135, "USA", "https://www.imdb.com/video/vi1229043737?playlistId=tt3778644&ref_=tt_ov_vi");
	addFilm(film7);
	Film film8 ("Persepolis", "Animation", 2017, 96, "USA", "https://www.imdb.com/video/vi280101145?playlistId=tt0808417&ref_=tt_ov_vi");
	addFilm(film8);
	Film film9 ("Amelie", "Comedy", 2001, 122, "USA", "https://www.imdb.com/video/vi1406515737?playlistId=tt0211915&ref_=tt_ov_vi");
	addFilm(film9);
	Film film10 ("The Shawshank Redemption", "Drama", 1994, 142, "USA", "https://www.imdb.com/video/vi3877612057?playlistId=tt0111161&ref_=tt_ov_vi");
	addFilm(film10);
}
