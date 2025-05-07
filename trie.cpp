#include "trie.h"
#include "trie_tools.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

Trie::Trie() {
    trie.emplace_back(); // create root
}

void Trie::add(string& s, int cnt) {
    int cur_node = 0;
    for (int idx = 0; idx < s.size(); idx++) {
        int Next = Tools().get_id(s[idx]);
        if (!Tools().exist(cur_node, Next, trie)) {
            trie[cur_node].children[Next] = trie.size();
            trie.emplace_back();
        }
        cur_node = trie[cur_node].children[Next];
        trie[cur_node].freq += cnt;
    }
    trie[cur_node].end += cnt;
}

void Trie::search_default(string& s, bool inc) {
    vector<pair<int, string>>all;
    int last = Tools().get_last(s, trie);
    if (~last)
        Tools().dfs(last, all, s, 1, trie);
    inc ? sort(all.begin(), all.end()) : sort(all.rbegin(), all.rend());
    cout << "Words : \n";
    for (auto [fr, str] : all)
        cout << str << '\n';
    cout << "--------------------\n";
}

void Trie::search_shortest(string& s) {
    int last = Tools().get_last(s, trie);
    vector<string>all;
    if (~last) {
        queue<pair<int, string>> q;
        q.push({ last ,s });
        while (q.size()) {
            auto [node, str] = q.front();
            if (trie[node].end)
                all.push_back(str);
            q.pop();
            for (int i = 0; i < Trie().Lim; i++) {
                if (Tools().exist(node, i, trie))
                    q.push({ trie[node].children[i] , str + Tools().get_char(i) });
            }
        }
    }
    cout << "Words : \n";
    for (auto str : all)
        cout << str << '\n';
    cout << "--------------------\n";
}

void Trie::search_lexicographical_order(string& s, bool inc) {
    int last = Tools().get_last(s, trie);
    vector<pair<int, string>>all;
    if (~last)
        Tools().dfs(last, all, s, 0, trie);
    cout << "Words : \n";
    for (int i = 0; i < all.size(); i++)
        cout << all[inc ? i : all.size() - i - 1].second << '\n';
    cout << "--------------------\n";
}

void Trie::search() {
    cout << "Choose :\n";
    cout << "1:- ";
    cout << "2:- ";
    cout << "3:- ";
    int choice;cin >> choice;
    bool inc;cin >> inc;
    if (choice == 1 || choice == 3) {
        cout << " inc ?";
    }
    cout << " ";
    string inp;cin >> inp;
    switch (choice) {
    case 1:
        search_default(inp, inc);
        break;

    case 2:
        search_shortest(inp);
        break;

    case 3:
        search_lexicographical_order(inp, inc);
        break;

    default:cout << "invalid\n";
    }
}

void Trie::erase(string& s, bool all) {
    int cur_node = 0;
    int last = Tools().get_last(s, trie);
    int fr_me = trie[last].end;
    for (int idx = 0; idx < s.size(); idx++) {
        int Next = Tools().get_id(s[idx]);
        cur_node = trie[cur_node].children[Next];
        trie[cur_node].freq -= all ? fr_me : 1;
    }
    trie[cur_node].end -= all ? fr_me : 1;
}

void Trie::erase_interface() {
    while (true) {
        cout << "Enter the word : \n";
        string s;cin >> s;
        int last = Tools().get_last(s, trie);
        if (~last && trie[last].end) {
            bool all;
            cout << "Do you want to delete all occurrences ?\n";
            cin >> all;
            erase(s, all);
            break;
        }
        if (last == -1) {
            cout << "no words found\n";
        }
        else {
            cout << "choose the correct word\n";
            search_shortest(s);
        }
    }
}