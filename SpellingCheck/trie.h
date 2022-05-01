#pragma once
#include <map>
#include <memory>

using namespace std;

class Trie
{
public:
	Trie() = default;

	shared_ptr<Trie> GetNode();
	void Insert(shared_ptr<Trie>& head, const char* word);
	bool Search(const shared_ptr<Trie>& head, const char* word) const;

private:
	map<char, shared_ptr<Trie>> _map;
	bool _leaf = false;
};

