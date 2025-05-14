#include <QtWidgets/QApplication>
#include <QFile>
#include <QDir>  
#include "load_files.h"
#include "gui.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Files::fonts();
    Files::style();

    a.setStyleSheet(Files::style());
    Gui w;
    w.show();
    return a.exec();
}
