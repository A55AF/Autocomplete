#include "trie.h"
#include "trie_tools.h"
#include "gui.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<set>
#include<QString>
using namespace std;

Trie::Trie() {
    trie.emplace_back(); // create root
}

void Trie::add(string& s, int cnt) {
    max_depth = max(max_depth, (int)s.size());
    if (searched_words.count(s)) {
        searched_words.erase(s);
    }
    int cur_node = 0;
    for (int idx = 0; idx < s.size(); idx++) {
        int Next = Tools::get_id(s[idx]);
        if (!Tools::exist(cur_node, Next, trie)) {
            trie[cur_node].children[Next] = trie.size();
            trie.emplace_back();
        }
        cur_node = trie[cur_node].children[Next];
        trie[cur_node].freq += cnt;
    }
    trie[cur_node].end += cnt;
}

vector<pair<int, string>> Trie::search_default(string& s, bool inc) {
    vector<pair<int, string>>all;
    int last = Tools::get_last(s, trie);
    if (~last)
        Tools::dfs(last, all, s, true, trie);
    inc ? sort(all.begin(), all.end()) : sort(all.rbegin(), all.rend());
    return all;
}

vector<string> Trie::search_shortest(string& s, bool inc) {
    int last = Tools::get_last(s, trie);
    vector<string>all;
    if (~last) {
        queue<pair<int, string>> q;
        q.push({ last ,s });
        while (q.size()) {
            auto [node, str] = q.front();
            if (trie[node].end)
                all.push_back(str);
            q.pop();
            for (int i = 0; i < Trie::Lim; i++) {
                if (Tools::exist(node, i, trie))
                    q.push({ trie[node].children[i] , str + Tools::get_char(i) });
            }
        }
    }
    if (!inc)
        reverse(all.begin(), all.end());
    return all;
}

vector<pair<int, string>> Trie::search_lexicographical_order(string& s, bool inc) {
    int last = Tools::get_last(s, trie);
    vector<pair<int, string>>all;
    if (~last)
        Tools::dfs(last, all, s, 0, trie);
    if (!inc)
        reverse(all.begin(), all.end());
    return all;
}

void Trie::search() {
    cout << "Choose :\n";
    cout << "1:- Search Default\n";
    cout << "2:- Search Shortest\n";
    cout << "3:- Search Lex.\n";
    cout << "4:- Search Fuzzy\n";
    int choice;cin >> choice;
    bool inc;
    cout << " inc ? : ";
    cin >> inc;

    string inp;cin >> inp;
    if (!word_exist(inp)) {
        if (++searched_words[inp] == 3) {
            add(inp, 1);
            searched_words.erase(inp);
        }
    }
    switch (choice) {
    case 1:
        search_default(inp, inc);
        break;

    case 2:
        search_shortest(inp, inc);
        break;

    case 3:
        search_lexicographical_order(inp, inc);
        break;

    case 4:
        search_fuzzy(inp);
        break;

    default:cout << "invalid\n";
    }
}

void Trie::erase(string& s) {
    int cur_node = 0;
    int last = Tools::get_last(s, trie);
    int fr_me = trie[last].end;
    for (int idx = 0; idx < s.size(); idx++) {
        int Next = Tools::get_id(s[idx]);
        cur_node = trie[cur_node].children[Next];
        trie[cur_node].freq -= fr_me;
    }
    trie[cur_node].end -= fr_me;
}

void Trie::erase_interface() {
    while (true) {
        cout << "Enter the word : \n";
        string s;cin >> s;
        int last = Tools::get_last(s, trie);
        if (~last && trie[last].end) {
            erase(s);
            break;
        }
        if (last == -1) {
            cout << "no words found\n";
        }
        else {
            cout << "choose the correct word\n";
            search_shortest(s,1);
        }
    }
}

bool Trie::word_exist(string& s) {
    int last = Tools::get_last(s, trie);
    return ~last && trie[last].end;
}

int Trie::freq_prefix(string& s) {
    int last = Tools::get_last(s, trie);
    if (~last)
        return trie[last].freq;
    else
        return 0;
}

void Trie::dfs_search_fuzzy(int node, int ptr, string& s, set<string>& output, string& cur) {
    if (ptr == s.size()) {
        if (trie[node].end)
            output.insert(cur);
        return;
    }

    if (s[ptr] == '.') {
        for (int i = 0; i < Trie::Lim; i++) {
            if (Tools::exist(node, i, trie)) {
                cur.push_back(Tools::get_char(i));
                dfs_search_fuzzy(trie[node].children[i], ptr + 1, s, output, cur);
                cur.pop_back();
            }
        }
    }
    else if (s[ptr] == '*') {
        dfs_search_fuzzy(node, ptr + 1, s, output, cur); // leave
        // take
        for (int i = 0; i < Trie::Lim; i++) {
            if (Tools::exist(node, i, trie)) {
                cur.push_back(Tools::get_char(i));
                dfs_search_fuzzy(trie[node].children[i], ptr, s, output, cur);
                cur.pop_back();
            }
        }
    }
    else {
        int Next = Tools::get_id(s[ptr]);
        if (Tools::exist(node, Next, trie)) {
            cur.push_back(Tools::get_char(Next));
            dfs_search_fuzzy(trie[node].children[Next], ptr + 1, s, output, cur);
            cur.pop_back();
        }
    }
}

set<string> Trie::search_fuzzy(string& s) {
    string tru;
    char prv = '#';
    for (char c : s) {
        if (c == '*' && prv == c)
            continue;
        tru += c;
        prv = c;
    }
    set<string> output;
    string cur = "";
    dfs_search_fuzzy(0, 0, tru, output, cur);
    return output;
}

unordered_map<string, int>& Trie::get_searched_words() {
    return searched_words;
}