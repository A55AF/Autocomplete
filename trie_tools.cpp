#include "trie_tools.h"
#include "trie.h"
#include <string>
#include <vector>
using namespace std;

int Tools::get_id(char c) {
    if (c >= 'a' && c <= 'z')
        c = toupper(c);
    return c - ' ';
}

char Tools::get_char(int id) {
    char c = id + ' ';
    if (c >= 'A' && c <= 'Z')
        c = tolower(c);
    return c;
}

bool Tools::exist(int node, int idx, vector<Node>& trie) {
    return trie[node].children[idx] && trie[trie[node].children[idx]].freq;
}

int Tools::get_last(string& s, vector<Node>& trie) {
    int cur_node = 0;
    for (int idx = 0; idx < s.size(); idx++) {
        int Next = get_id(s[idx]);
        if (!exist(cur_node, Next, trie))
            return -1;
        cur_node = trie[cur_node].children[Next];
    }
    return cur_node;
}

void Tools::dfs(int node, vector<pair<int, string>>& all, string& cur, bool freq, vector<Node>& trie) {
    if (trie[node].end)                                                       // and push {freq , word}
        all.push_back({ freq ? trie[node].end : 0, cur });
    for (int i = 0; i < Trie::Lim; i++) {
        if (exist(node, i, trie)) {
            cur.push_back(get_char(i));
            dfs(trie[node].children[i], all, cur, freq, trie);
            cur.pop_back();
        }
    }
}