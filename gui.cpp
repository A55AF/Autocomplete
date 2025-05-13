#include "gui.h"
#include<QListWidget>
#include<QLabel>
#include<QPushButton>
#include<QWidget>
#include<iostream>
Gui::Gui(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QWidget* centralWidget = new QWidget(this);
    gsearch(0, "", ui.sortBy->text() == "Ascending");
    connect(ui.clearTextField, &QPushButton::clicked, this, &Gui::onButtonClickedClearTextField);
    connect(ui.searchTextField, &QLineEdit::textEdited, this, &Gui::onChangeSearchTextField);
    connect(ui.addWord, &QPushButton::clicked, this, &Gui::onButtonClickedAddWord);
    connect(ui.sortBy, &QPushButton::clicked, this, &Gui::onButtonClickedSortBy);
    connect(ui.searchMode, &QComboBox::currentIndexChanged, this, &Gui::onComboBoxChangedSearchMode);
    
    searchTimer = new QTimer(this);
    searchTimer->setSingleShot(true);
    searchTimer->setInterval(2000);
    
    connect(searchTimer, &QTimer::timeout, this, &Gui::onTimeout);
    this->setCentralWidget(centralWidget);
    centralWidget->setLayout(ui.mainLayout);
}

Gui::~Gui()
{
}

void Gui::onComboBoxChangedSearchMode() {
    int mode = ui.searchMode->currentIndex();
    if (mode == 3) {
        ui.sortBy->setDisabled(true);
        ui.searchTextField->clear();
        ui.listView->clear();
        return;
    }
    ui.sortBy->setDisabled(false);
    refreshList();
}

void Gui::onButtonClickedSortBy() {
    if (ui.sortBy->text() == "Ascending") {
        ui.sortBy->setIcon(QIcon().fromTheme(QIcon::ThemeIcon::GoDown));
        ui.sortBy->setText("Descending");
    }
    else {
        ui.sortBy->setIcon(QIcon().fromTheme(QIcon::ThemeIcon::GoUp));
        ui.sortBy->setText("Ascending");
    }
    onChangeSearchTextField();
}

void Gui::onButtonClickedAddWord() {
    string word = ui.searchTextField->text().toStdString();
    int frq = ui.wordFrequency->value();
    if (word.size()) {
        trie.add(word, frq);
        onButtonClickedClearTextField();
        ui.wordFrequency->setValue(1);
    }
}

void Gui::addWordItem(const QString& word, int freq) {
    auto* itemWidget = new QCustomListItem(word, freq);
    auto* listItem = new QListWidgetItem(ui.listView);

    listItem->setSizeHint(itemWidget->sizeHint());

    ui.listView->addItem(listItem);
    ui.listView->setItemWidget(listItem, itemWidget);

    connect(itemWidget, &QCustomListItem::deleteWord, this, [=](const QString& wordToDelete) {
        string word = wordToDelete.toStdString();
        trie.erase(word);

        int row = ui.listView->row(listItem);
        delete ui.listView->takeItem(row);
        });
}

void Gui::onButtonClickedClearTextField() {
    ui.searchTextField->clear();
    refreshList();
}

void Gui::onChangeSearchTextField() {
    searchTimer->start();
    refreshList();
}

void Gui::onTimeout() {
    string word = ui.searchTextField->text().toStdString();
    unordered_map<string, int>& searched_words = trie.get_searched_words();
    if (!trie.word_exist(word)) {
        if (++searched_words[word] == 3) {
            trie.add(word, 1);
            refreshList();
            searched_words.erase(word);
        }
    }
    else {
        trie.add(word, 1);
        refreshList();
    }
}

// Refresh List every change in textField/searching mode/clear textfield
void Gui::refreshList() {
    int mode = ui.searchMode->currentIndex();
    string word = ui.searchTextField->text().toStdString();
    bool ascending = ui.sortBy->text() == "Ascending";
    ui.listView->clear();
    gsearch(mode, word, ascending);
}

// Searching in trie for GUI
void Gui::gsearch_default(string prefix, bool ascending) {
    vector<pair<int, string>> output = trie.search_default(prefix, ascending);
    for (auto [frq, word] : output) {
        addWordItem(QString::fromStdString(word), frq);
    }
}

void Gui::gsearch_shortest(string prefix, bool ascending) {
    vector<string> output = trie.search_shortest(prefix, ascending);
    for (string word : output) {
        addWordItem(QString::fromStdString(word), trie.freq_prefix(word));
    }
}

void Gui::gsearch_lexo(string prefix, bool ascending) {
    vector<pair<int, string>> output = trie.search_lexicographical_order(prefix, ascending);
    for (auto [frq, word] : output) {
        addWordItem(QString::fromStdString(word), trie.freq_prefix(word));
    }
}

void Gui::gsearch_fuzzy(string prefix) {
    set<string> output = trie.search_fuzzy(prefix);
    for (string word : output) {
        addWordItem(QString::fromStdString(word), trie.freq_prefix(word));
    }
}

void Gui::gsearch(int mode, string prefix, bool ascending) {
    switch (mode) {
    case 0:
        gsearch_default(prefix, ascending);
        break;
    case 1:
        gsearch_shortest(prefix, ascending);
        break;
    case 2:
        gsearch_lexo(prefix, ascending);
        break;
    case 3:
        gsearch_fuzzy(prefix);
        break;
    }
}
