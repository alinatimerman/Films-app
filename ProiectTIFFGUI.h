#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProiectAlinaTIFFGUI.h"

class ProiectAlinaTIFFGUI : public QMainWindow
{
    Q_OBJECT

public:
    ProiectAlinaTIFFGUI(QWidget *parent = Q_NULLPTR);

private:
    Ui::ProiectAlinaTIFFGUIClass ui;
};
