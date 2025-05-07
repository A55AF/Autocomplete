/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiClass
{
public:
    QWidget *centralWidget;
    QListView *listView;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GuiClass)
    {
        if (GuiClass->objectName().isEmpty())
            GuiClass->setObjectName("GuiClass");
        GuiClass->resize(600, 400);
        centralWidget = new QWidget(GuiClass);
        centralWidget->setObjectName("centralWidget");
        listView = new QListView(centralWidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(160, 130, 256, 192));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 90, 80, 24));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(330, 50, 81, 24));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(160, 90, 161, 21));
        GuiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GuiClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        GuiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GuiClass);
        mainToolBar->setObjectName("mainToolBar");
        GuiClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GuiClass);
        statusBar->setObjectName("statusBar");
        GuiClass->setStatusBar(statusBar);

        retranslateUi(GuiClass);

        QMetaObject::connectSlotsByName(GuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *GuiClass)
    {
        GuiClass->setWindowTitle(QCoreApplication::translate("GuiClass", "Gui", nullptr));
        pushButton->setText(QCoreApplication::translate("GuiClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuiClass: public Ui_GuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
