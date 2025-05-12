#include "gui.h"
#include<QListWidget>
#include<QLabel>
#include<QPushButton>
#include<QWidget>
Gui::Gui(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QWidget* centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    centralWidget->setLayout(ui.mainLayout);
    //QString t1 = QString("Assaf");
    //QString t2 = QString("1");
    //QCustomListItem* test = new QCustomListItem(t1,t2, ui);
}

Gui::~Gui()
{}

QCustomListItem::QCustomListItem(QString &labelString, QString &frqString,Ui::GuiClass&ui) {
    //listWidget = ui.listView;

    //itemWidget = new QWidget();
    //itemLayout = new QHBoxLayout(itemWidget);
    //
    //word = new QLabel(labelString);
    //frequencyOfWord = new QLabel(frqString);
    //deleteButton = new QToolButton();
    //deleteButton->setIcon(QIcon().fromTheme(QIcon::ThemeIcon::EditDelete));
    //
    //itemLayout->addWidget(word);
    //itemLayout->addWidget(frequencyOfWord);
    //itemLayout->addWidget(deleteButton);
    //
    //QListWidgetItem* item = new QListWidgetItem();
    //listWidget->addItem(item);
    //listWidget->setItemWidget(item, itemWidget);
    //item->setSizeHint(itemWidget->sizeHint());
}

QCustomListItem::~QCustomListItem() {
    delete listWidget;
    delete itemWidget;
    delete itemLayout;
    delete word;
    delete frequencyOfWord;
    delete deleteButton;
}