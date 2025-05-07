#pragma once

#include <QtWidgets/QMainWindow>
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
