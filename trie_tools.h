#pragma once
#include "trie.h"

class Tools {
public:
    static int get_id(char);
    static char get_char(int id);
    static bool exist(int, int, vector<Node>&);
    static int get_last(string&, vector<Node>&);
    static void dfs(int, vector<pair<int, string>>&, string&, bool, vector<Node>&);
};