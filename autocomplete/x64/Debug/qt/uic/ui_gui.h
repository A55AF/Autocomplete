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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *horizontalLayout_1;
    QLineEdit *searchTextField;
    QToolButton *clearTextField;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listView;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_1;
    QComboBox *searchMode;
    QPushButton *sortBy;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GuiClass)
    {
        if (GuiClass->objectName().isEmpty())
            GuiClass->setObjectName("GuiClass");
        GuiClass->resize(881, 488);
        centralWidget = new QWidget(GuiClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(110, 70, 461, 309));
        mainLayout = new QVBoxLayout(verticalLayoutWidget);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(15, 20, 15, 20);
        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setSpacing(6);
        horizontalLayout_1->setObjectName("horizontalLayout_1");
        searchTextField = new QLineEdit(verticalLayoutWidget);
        searchTextField->setObjectName("searchTextField");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchTextField->sizePolicy().hasHeightForWidth());
        searchTextField->setSizePolicy(sizePolicy);
        searchTextField->setMinimumSize(QSize(150, 25));
        searchTextField->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_1->addWidget(searchTextField);

        clearTextField = new QToolButton(verticalLayoutWidget);
        clearTextField->setObjectName("clearTextField");
        sizePolicy.setHeightForWidth(clearTextField->sizePolicy().hasHeightForWidth());
        clearTextField->setSizePolicy(sizePolicy);
        clearTextField->setMinimumSize(QSize(25, 25));
        clearTextField->setMaximumSize(QSize(35, 35));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::WindowClose));
        clearTextField->setIcon(icon);
        clearTextField->setIconSize(QSize(10, 10));

        horizontalLayout_1->addWidget(clearTextField);


        mainLayout->addLayout(horizontalLayout_1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        listView = new QListWidget(verticalLayoutWidget);
        listView->setObjectName("listView");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy1);
        listView->setMinimumSize(QSize(160, 200));
        listView->setMaximumSize(QSize(16777215, 700));
        listView->setFrameShape(QFrame::Shape::StyledPanel);

        verticalLayout_2->addWidget(listView);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_1 = new QVBoxLayout();
        verticalLayout_1->setSpacing(6);
        verticalLayout_1->setObjectName("verticalLayout_1");
        searchMode = new QComboBox(verticalLayoutWidget);
        searchMode->addItem(QString());
        searchMode->addItem(QString());
        searchMode->addItem(QString());
        searchMode->setObjectName("searchMode");
        sizePolicy.setHeightForWidth(searchMode->sizePolicy().hasHeightForWidth());
        searchMode->setSizePolicy(sizePolicy);
        searchMode->setMinimumSize(QSize(80, 20));
        searchMode->setMaximumSize(QSize(160, 30));

        verticalLayout_1->addWidget(searchMode);

        sortBy = new QPushButton(verticalLayoutWidget);
        sortBy->setObjectName("sortBy");
        sizePolicy.setHeightForWidth(sortBy->sizePolicy().hasHeightForWidth());
        sortBy->setSizePolicy(sizePolicy);
        sortBy->setMinimumSize(QSize(80, 20));
        sortBy->setMaximumSize(QSize(160, 30));
        sortBy->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::GoDown));
        sortBy->setIcon(icon1);
        sortBy->setIconSize(QSize(14, 14));

        verticalLayout_1->addWidget(sortBy);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_1->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_1);


        mainLayout->addLayout(horizontalLayout_2);

        GuiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GuiClass);
        statusBar->setObjectName("statusBar");
        GuiClass->setStatusBar(statusBar);

        retranslateUi(GuiClass);

        QMetaObject::connectSlotsByName(GuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *GuiClass)
    {
        GuiClass->setWindowTitle(QCoreApplication::translate("GuiClass", "Gui", nullptr));
        clearTextField->setText(QCoreApplication::translate("GuiClass", "...", nullptr));
        searchMode->setItemText(0, QCoreApplication::translate("GuiClass", "Default", nullptr));
        searchMode->setItemText(1, QCoreApplication::translate("GuiClass", "Shortest", nullptr));
        searchMode->setItemText(2, QCoreApplication::translate("GuiClass", "Lexographically", nullptr));

        sortBy->setText(QCoreApplication::translate("GuiClass", "Ascending", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuiClass: public Ui_GuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
