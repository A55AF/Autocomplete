#include "gui.h"
#include "trie.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gui w;
    w.show();
    return a.exec();
}
