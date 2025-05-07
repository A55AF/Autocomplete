#pragma once
#include<vector>
#include<string>
using namespace std;

struct Node {
	int children[60]{};
	int freq = 0, end = 0;
};

class Trie {
private:
	vector<Node> trie;
public:
	static const int Lim = 60;
	Trie();
	void add(string&, int);
	void search_default(string&, bool);
	void search_shortest(string&);
	void search_lexicographical_order(string&, bool);
	void search();
	void erase_interface();
	void erase(string&, bool);
};