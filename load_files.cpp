#include <string>
#include <QFile>
#include <QDir>
#include <QFontDatabase>
#include <QTextStream>
#include <QRegularExpression>
#include <QDebug>
#include <vector>
#include "trie.h"
#include "load_files.h"
using namespace std;

QStringList Files::fontsCache;
QString Files::styleCache;

QString Files::loadStyleSheet(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qWarning() << "Could not open style file:" << filePath;
        return "";
    }
    QTextStream in(&file);
    return in.readAll();
}

QStringList Files::loadFontsFromFolder(const QString& path) {
    QStringList loadedFonts;

    QDir fontDir(path);
    QStringList fontFiles = fontDir.entryList(QStringList() << "*.ttf" << "*.otf", QDir::Files);

    for (const QString& fileName : fontFiles) {
        QString filePath = fontDir.absoluteFilePath(fileName);
        int id = QFontDatabase::addApplicationFont(filePath);
        if (id != -1) {
            QStringList families = QFontDatabase::applicationFontFamilies(id);
            if (!families.isEmpty()) {
                loadedFonts << families.first();
            }
        }
        else {
            qWarning() << "Failed to load font:" << filePath;
        }
    }

    return loadedFonts;
}

const QStringList& Files::fonts() {
    if (fontsCache.isEmpty()) {
        fontsCache = loadFontsFromFolder("assets/fonts");
    }
    return fontsCache;
}

const QString& Files::style() {
    if (styleCache.isEmpty()) {
        styleCache = loadStyleSheet(":/autocomplete/assets/styles/style.qss")
            .arg(fonts()[1])
            .arg(fonts()[0]);
    }
    return styleCache;
}

void Files::loadData(Trie& trie) {
    QFile file(":/autocomplete/data/words.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file WORDS";
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList splited_line = line.split(QRegularExpression(","), Qt::SkipEmptyParts);
        string word = splited_line[0].toStdString();
        int freq = splited_line[1].toInt();
        trie.add(word, freq);
    }
    file.close();
}

void Files::writeData(Trie& trie) {
	QFile file("data/words.csv");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing";
        return;
    }
	QTextStream out(&file);
    string inp = "";
    vector<string> words = trie.search_shortest(inp, 1);
    for (string& word : words) {
        out << QString::fromStdString(word) << "," << trie.freq_prefix(word) << "\n";
    }

    file.close();
}