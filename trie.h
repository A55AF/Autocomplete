#pragma once
#include<vector>
#include<string>
#include<unordered_map>
#include<set>
#include "ui_gui.h"
using namespace std;

struct Node {
    int children[60]{};
    int freq = 0, end = 0;
};

class Trie {
private:
    vector<Node> trie;
    int max_depth = 0;
    unordered_map<string, int> searched_words;
public:
    static const int Lim = 60;
    Trie();
    void add(string&, int);
    vector<pair<int, string>> search_default(string&, bool);
    vector<string> search_shortest(string&, bool);
    vector<pair<int, string>> search_lexicographical_order(string&, bool);
    void search();
    void erase_interface();
    void erase(string&);
    bool word_exist(string&);
    void dfs_search_fuzzy(int, int, string&, set<string>&, string&);
    int freq_prefix(string&);
    set<string> search_fuzzy(string&);
    unordered_map<string, int>& get_searched_words();
};