#pragma once

#include <QtWidgets/QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include "ui_gui.h"

class Gui : public QMainWindow
{
    Q_OBJECT

public:
    Gui(QWidget *parent = nullptr);
    ~Gui();

private:
    Ui::GuiClass ui;
};

class QCustomListItem {
private:
    QListWidget* listWidget;
    QWidget* itemWidget;
    QHBoxLayout* itemLayout;
    QLabel* word;
    QLabel* frequencyOfWord;
    QToolButton* deleteButton;

public:
    QCustomListItem(QString&,QString&,Ui::GuiClass &);
    ~QCustomListItem();
};

