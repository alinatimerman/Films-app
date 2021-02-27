#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qformlayout.h>
#include <qgridlayout.h>
#include <qmessagebox.h>
#include <qfont.h>
#include <qlabel.h>
#include <qevent.h>
#include <qkeyeventtransition.h>
#include "UserService.h"
#include "AdminService.h"

class GUI : public QListWidget
{

private:
	char mode;

	UserService& userService;
	AdminService& adminService;
	QListWidget* filmsListWidget, * watchListWidget;
	QLineEdit* titleLine, * genreLine, * yearLine, * timeLine, * locationLine, * trailerLine;
	QPushButton* addButton, * removeButton, * updateButton, * listButton, * filterButton, * removeWatchButton, * modeButton;

public:
	GUI(AdminService& adminService, UserService& userService);

private:
	void initGUI();
	void populateList();
	void makeConnections();

	int getSelectedIndex();
	void addFilmGUI();
	void updateFilmGUI();
	void removeFilmGUI();
};

