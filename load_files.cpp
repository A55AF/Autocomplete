#include <string>
#include <QFile>
#include <QDir>
#include <QFontDatabase>
#include <QTextStream>
#include <QRegularExpression>
#include <vector>
#include <fstream>
#include <sstream>
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

vector<pair<string, int>> Files::loadWordFreqs(Trie&trie) {
	const string& filename = "data/words.txt";
    ifstream inFile(filename);
    vector<pair<string, int>> result;
    string line;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string word;
        int freq;
        if (iss >> word >> freq) {
            trie.add(word, freq);
        }
    }
    inFile.close();
    return result;
}

void Files::saveWordFreqs(Trie& trie) {
    filesystem::create_directories("data");

    ofstream outFile("data/words.txt");

    string str = "";
    const auto data = trie.search_default(str, 1);

    for (const auto& [freq, word] : data) {
        outFile << word << " " << freq << "\n";
    }
}