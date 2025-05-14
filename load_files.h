#pragma once
#include <QtWidgets/QApplication>
#include <QFile>
#include <QDir>
#include <QFontDatabase>
#include <QCloseEvent>
#include "trie.h"


class Files {
private:
    static QString loadStyleSheet(const QString&);
    static QStringList loadFontsFromFolder(const QString&);
    static QStringList fontsCache;
    static QString styleCache;

public:
    static const QStringList& fonts();
    static const QString& style();
    static void loadData(Trie&);
    static void writeData(Trie&);
};
