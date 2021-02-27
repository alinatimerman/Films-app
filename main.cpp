#include "ProiectAlinaTIFFGUI.h"
#include <QtWidgets/QApplication>
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    Repository repository;
    repository.filmExamples();
    AdminService adminService{ repository };
    UserService userService{ repository };
    
    GUI gui{ adminService, userService };
    gui.show();

    return a.exec();
}
