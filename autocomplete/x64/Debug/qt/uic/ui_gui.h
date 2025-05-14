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
#include <QtWidgets/QSpinBox>
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
    QHBoxLayout *horizontalLayout;
    QSpinBox *wordFrequency;
    QPushButton *addWord;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GuiClass)
    {
        if (GuiClass->objectName().isEmpty())
            GuiClass->setObjectName("GuiClass");
        GuiClass->resize(645, 489);
        centralWidget = new QWidget(GuiClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(110, 70, 490, 301));
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
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchTextField->sizePolicy().hasHeightForWidth());
        searchTextField->setSizePolicy(sizePolicy);
        searchTextField->setMinimumSize(QSize(150, 35));
        searchTextField->setMaximumSize(QSize(16777215, 40));
        searchTextField->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_1->addWidget(searchTextField);

        clearTextField = new QToolButton(verticalLayoutWidget);
        clearTextField->setObjectName("clearTextField");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(clearTextField->sizePolicy().hasHeightForWidth());
        clearTextField->setSizePolicy(sizePolicy1);
        clearTextField->setMinimumSize(QSize(35, 35));
        clearTextField->setMaximumSize(QSize(40, 40));
        clearTextField->setStyleSheet(QString::fromUtf8(""));
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
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(2);
        sizePolicy2.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy2);
        listView->setMinimumSize(QSize(300, 200));
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
        searchMode->addItem(QString());
        searchMode->setObjectName("searchMode");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(searchMode->sizePolicy().hasHeightForWidth());
        searchMode->setSizePolicy(sizePolicy3);
        searchMode->setMinimumSize(QSize(80, 30));
        searchMode->setMaximumSize(QSize(180, 40));
        searchMode->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_1->addWidget(searchMode);

        sortBy = new QPushButton(verticalLayoutWidget);
        sortBy->setObjectName("sortBy");
        sizePolicy3.setHeightForWidth(sortBy->sizePolicy().hasHeightForWidth());
        sortBy->setSizePolicy(sizePolicy3);
        sortBy->setMinimumSize(QSize(80, 30));
        sortBy->setMaximumSize(QSize(180, 40));
        sortBy->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::GoUp));
        sortBy->setIcon(icon1);
        sortBy->setIconSize(QSize(14, 14));

        verticalLayout_1->addWidget(sortBy);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        wordFrequency = new QSpinBox(verticalLayoutWidget);
        wordFrequency->setObjectName("wordFrequency");
        sizePolicy3.setHeightForWidth(wordFrequency->sizePolicy().hasHeightForWidth());
        wordFrequency->setSizePolicy(sizePolicy3);
        wordFrequency->setMinimumSize(QSize(70, 20));
        wordFrequency->setMaximumSize(QSize(80, 40));
        wordFrequency->setMinimum(1);
        wordFrequency->setMaximum(100);

        horizontalLayout->addWidget(wordFrequency);

        addWord = new QPushButton(verticalLayoutWidget);
        addWord->setObjectName("addWord");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(addWord->sizePolicy().hasHeightForWidth());
        addWord->setSizePolicy(sizePolicy4);
        addWord->setMinimumSize(QSize(70, 20));
        addWord->setMaximumSize(QSize(80, 40));

        horizontalLayout->addWidget(addWord);


        verticalLayout_1->addLayout(horizontalLayout);

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
        searchTextField->setText(QString());
        searchTextField->setPlaceholderText(QCoreApplication::translate("GuiClass", "Search", nullptr));
        clearTextField->setText(QCoreApplication::translate("GuiClass", "...", nullptr));
        searchMode->setItemText(0, QCoreApplication::translate("GuiClass", "Default", nullptr));
        searchMode->setItemText(1, QCoreApplication::translate("GuiClass", "Shortest", nullptr));
        searchMode->setItemText(2, QCoreApplication::translate("GuiClass", "Lexographically", nullptr));
        searchMode->setItemText(3, QCoreApplication::translate("GuiClass", "Fuzzy", nullptr));

        sortBy->setText(QCoreApplication::translate("GuiClass", "Ascending", nullptr));
        addWord->setText(QCoreApplication::translate("GuiClass", "Add Word", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GuiClass: public Ui_GuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
