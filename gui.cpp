#include <iostream>
#include <QtWidgets/QApplication>
#include <QSoundEffect>
#include <QCloseEvent>
#include "gui.h"

Gui::Gui(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QWidget* centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    centralWidget->setLayout(ui.mainLayout);

	Files::loadWordFreqs(trie);

    refreshList();

    searchTimer = new QTimer(this);
    searchTimer->setSingleShot(true);
    searchTimer->setInterval(2000);

    connect(ui.clearTextField, &QPushButton::clicked, this, &Gui::onButtonClickedClearTextField);
    connect(ui.searchTextField, &QLineEdit::textEdited, this, &Gui::onChangeSearchTextField);
    connect(ui.addWord, &QPushButton::clicked, this, &Gui::onButtonClickedAddWord);
    connect(ui.sortBy, &QPushButton::clicked, this, &Gui::onButtonClickedSortBy);
    connect(ui.searchMode, &QComboBox::currentIndexChanged, this, &Gui::onComboBoxChangedSearchMode);
    connect(searchTimer, &QTimer::timeout, this, &Gui::onTimeout);
}

Gui::~Gui()
{
    delete searchTimer;
}

void Gui::closeEvent(QCloseEvent* event) {
    Files::saveWordFreqs(trie);
    event->accept();
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

void Gui::addWordItem(const QString& word, int freq, bool highlighted) {
    auto* itemWidget = new QCustomListItem(word, freq);
    auto* listItem = new QListWidgetItem(ui.listView);

    listItem->setSizeHint(itemWidget->sizeHint());
    ui.listView->addItem(listItem);
    ui.listView->setItemWidget(listItem, itemWidget);

    if (highlighted) {
        listItem->setBackground(QBrush(QColor("#3c3c3c")));
    }

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
    if (!word.size()) {
        return;
    }
    unordered_map<string, int>& searched_words = trie.get_searched_words();
    if (!trie.word_exist(word)) {
        if (++searched_words[word] == 3) {
            qDebug() << "Word not found in trie";
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

void Gui::refreshList() {
    int mode = ui.searchMode->currentIndex();
    string word = ui.searchTextField->text().toStdString();
    bool ascending = ui.sortBy->text() == "Ascending";
    char last_char = word.size() ? word.back() : 'A';
    if (last_char >= 'a' && last_char <= 'z')
        last_char = toupper(last_char);
    if ( last_char >= ' ' && last_char <= 'Z') {
        ui.listView->clear();
        gsearch(mode, word, ascending);
        return;
    }

    word.pop_back();
    ui.searchTextField->setText(QString::fromStdString(word));
    QSoundEffect* errorSound = new QSoundEffect(this);
    errorSound->setSource(QUrl("qrc:/autocomplete/assets/sounds/error.wav"));
    errorSound->setVolume(0.8f);
    errorSound->play();
}

void Gui::gsearch_default(string prefix, bool ascending) {
    vector<pair<int, string>> output = trie.search_default(prefix, ascending);
    for (auto [frq, word] : output) {
        addWordItem(QString::fromStdString(word), frq,prefix==word);
    }
}

void Gui::gsearch_shortest(string prefix, bool ascending) {
    vector<string> output = trie.search_shortest(prefix, ascending);
    for (string word : output) {
        addWordItem(QString::fromStdString(word), trie.freq_prefix(word), prefix == word);
    }
}

void Gui::gsearch_lexo(string prefix, bool ascending) {
    vector<pair<int, string>> output = trie.search_lexicographical_order(prefix, ascending);
    for (auto [frq, word] : output) {
        addWordItem(QString::fromStdString(word), trie.freq_prefix(word), prefix == word);
    }
}

void Gui::gsearch_fuzzy(string prefix) {
    set<string> output = trie.search_fuzzy(prefix);
    for (string word : output) {
        addWordItem(QString::fromStdString(word), trie.freq_prefix(word), prefix == word);
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
