#include "GUI.h"

GUI::GUI(AdminService& adminService, UserService& userService) : adminService{ adminService }, userService{ userService }
{
	this->initGUI();
	this->populateList();
	this->makeConnections();
}

void GUI::initGUI()
{
	filmsListWidget = new QListWidget{};
	//watchListWidget = new QListWidget{};

	titleLine = new QLineEdit{};
	genreLine = new QLineEdit{};
	yearLine = new QLineEdit{};
	timeLine = new QLineEdit{};
	locationLine = new QLineEdit{};
	trailerLine = new QLineEdit{};

	addButton = new QPushButton{"Add"};
	removeButton = new QPushButton{"Remove"};
	updateButton = new QPushButton{"Update"};
	/*listButton = new QPushButton{"List"};
	filterButton = new QPushButton{"Filter"};
	removeWatchButton = new QPushButton{"Remove WL"};
	modeButton = new QPushButton{"Change mode"};*/

	QVBoxLayout* mainLayout = new QVBoxLayout{ this };
	mainLayout->addWidget(filmsListWidget);
	//mainLayout->addWidget(watchListWidget);

	QFormLayout* formLayout = new QFormLayout{};
	formLayout->addRow("Title", titleLine);
	formLayout->addRow("Genre", genreLine);
	formLayout->addRow("Year of release", yearLine);
	formLayout->addRow("Time", timeLine);
	formLayout->addRow("Location", locationLine);
	formLayout->addRow("Trailer", trailerLine);
	mainLayout->addLayout(formLayout);

	QGridLayout* buttonsLayout = new QGridLayout{};
	buttonsLayout->addWidget(addButton, 0, 0);
	buttonsLayout->addWidget(removeButton, 0, 1);
	buttonsLayout->addWidget(updateButton, 0, 2);
	/*buttonsLayout->addWidget(listButton, 1, 0);
	buttonsLayout->addWidget(filterButton, 1, 1);
	buttonsLayout->addWidget(removeWatchButton, 1, 2);*/
	mainLayout->addLayout(buttonsLayout);

	/*QGridLayout* modeLayout = new QGridLayout{};
	modeLayout->addWidget(modeButton, 0, 1);
	mainLayout->addLayout(modeLayout);*/

}

void GUI::populateList()
{
	filmsListWidget->clear();

	vector <Film> filmsList = adminService.getFilmsListAdmin();

	for (int i = 0; i < filmsList.size(); ++i)
		filmsListWidget->addItem(QString::fromStdString(filmsList[i].toString()));
}

void GUI::makeConnections()
{
	QObject::connect(filmsListWidget, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = getSelectedIndex();
		if (selectedIndex == -1)
			return;
		vector <Film> filmsList = adminService.getFilmsListAdmin();
		Film selectedFilm = filmsList[selectedIndex];
		titleLine->setText(QString::fromStdString(selectedFilm.getTitle()));
		genreLine->setText(QString::fromStdString(selectedFilm.getGenre()));
		yearLine->setText(QString::fromStdString(to_string(selectedFilm.getYearOfRelease())));
		timeLine->setText(QString::fromStdString(to_string((int)selectedFilm.getTime())));
		locationLine->setText(QString::fromStdString(selectedFilm.getLocation()));
		trailerLine->setText(QString::fromStdString(selectedFilm.getTrailer()));
		});

	QObject::connect(addButton, &QPushButton::clicked, this, &GUI::addFilmGUI);
	QObject::connect(updateButton, &QPushButton::clicked, this, &GUI::updateFilmGUI);
	QObject::connect(removeButton, &QPushButton::clicked, this, &GUI::removeFilmGUI);

}

int GUI::getSelectedIndex()
{
	QModelIndexList selectedIndexes = filmsListWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
		return -1;

	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

void GUI::addFilmGUI()
{
	string title, genre, location, trailer;
	int year, time;

	title = titleLine->text().toStdString();
	genre = genreLine->text().toStdString();
	year = yearLine->text().toInt();
	time = timeLine->text().toInt();
	location = locationLine->text().toStdString();
	trailer = trailerLine->text().toStdString();

	bool ok = adminService.addFilmAdmin(title, genre, year, time, location, trailer);
	if (ok == false) {
		QMessageBox::critical(this, "Add film error!", "Film alraedy existent!");
		return;
	}
	else {
		this->populateList();
		vector <Film> filmsList = adminService.getFilmsListAdmin();
		filmsListWidget->setCurrentRow(filmsList.size() - 1);
	}
}

void GUI::updateFilmGUI()
{
	string title, genre, location, trailer;
	int year, time;

	title = titleLine->text().toStdString();
	genre = genreLine->text().toStdString();
	year = yearLine->text().toInt();
	time = timeLine->text().toInt();
	location = locationLine->text().toStdString();
	trailer = trailerLine->text().toStdString();

	bool ok = adminService.updateFilmAdmin(title, genre, year, time, location, trailer);
	if (ok == false) {
		QMessageBox::critical(this, "Update film error!", "Inexistent film!");
		return;
	}
	else {
		this->populateList();
		vector <Film> filmsList = adminService.getFilmsListAdmin();
		for ( int i = 0 ; i < filmsList.size(); ++ i )
			if (filmsList[i].getTitle() == title) {
				filmsListWidget->setCurrentRow(i);
				return;
			}
	}
}

void GUI::removeFilmGUI()
{
	string title;

	title = titleLine->text().toStdString();

	bool ok = adminService.deleteFilmAdmin(title);
	if (ok == false) {
		QMessageBox::critical(this, "Remove film error!", "Inexistent film!");
		return;
	}
	else {
		this->populateList();
		return;
	}
}
