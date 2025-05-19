#pragma once
#include <QtWidgets/QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>
#include <QFontDatabase>
#include "load_files.h"
#include "ui_gui.h"
#include "trie.h"


class Gui : public QMainWindow
{
    Q_OBJECT

public:
    Gui(QWidget *parent = nullptr);
    ~Gui();

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    Ui::GuiClass ui;
    QTimer* searchTimer;
    Trie trie;
    void onButtonClickedClearTextField();
    void onChangeSearchTextField();
    void onButtonClickedAddWord();
    void onButtonClickedSortBy();
    void onComboBoxChangedSearchMode();
    void addWordItem(const QString&, int,bool);
    void gsearch_default(string, bool);
    void gsearch_lexo(string, bool);
    void gsearch_shortest(string, bool);
    void gsearch_fuzzy(string);
    void gsearch(int, string, bool);
    void onTimeout();
    void refreshList();
};

class QCustomListItem : public QWidget {
    Q_OBJECT

public:
    QCustomListItem(const QString& word, int frequency, QWidget* parent = nullptr)
        : QWidget(parent), word_(word) {
        auto* layout = new QHBoxLayout(this);

        wordLabel = new QLabel(word);
        freqLabel = new QLabel(QString::number(frequency));
        deleteButton = new QPushButton;
        deleteButton->setIcon(QIcon::fromTheme("edit-delete"));
        deleteButton->setFlat(true);
        deleteButton->setMinimumWidth(35);
        deleteButton->setMinimumHeight(35);
        deleteButton->setMaximumWidth(40);
        deleteButton->setMaximumHeight(40);
        deleteButton->setObjectName("deleteButton");
        wordLabel->setFont(QFont(Files::fonts()[0], 14));
        freqLabel->setFont(QFont(Files::fonts()[0], 14));

        layout->addWidget(wordLabel);
        layout->addWidget(freqLabel);
        layout->addWidget(deleteButton);
        layout->setContentsMargins(10, 5, 10, 5);


        connect(deleteButton, &QPushButton::clicked, this, &QCustomListItem::onDeleteClicked);
    }

    QString getWord() const { return word_; }

signals:
    void deleteWord(const QString& word);

private slots:
    void onDeleteClicked() {
        emit deleteWord(word_);
    }

private:
    QLabel* wordLabel;
    QLabel* freqLabel;
    QPushButton* deleteButton;
    QString word_;
};
