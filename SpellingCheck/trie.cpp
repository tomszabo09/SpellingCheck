#include "trie.h"

shared_ptr<Trie> Trie::GetNode()
{
	const auto t = new Trie;
	shared_ptr<Trie> node(t);
	node->_leaf = false;
	return node;
}

void Trie::Insert(shared_ptr<Trie>& head, const char* word)
{
	if (head == nullptr)
		head = GetNode();

	shared_ptr<Trie> current = head;
	while (*word)
	{
		if (current->_map.find(*word) == current->_map.end())
			current->_map[*word] = GetNode();

		current = current->_map[*word];
		word++;
	}
	current->_leaf = true;
}

bool Trie::Search(const shared_ptr<Trie>& head, const char* word) const
{
	if (head == nullptr)
		return false;

	shared_ptr<Trie> current = head;
	while (*word)
	{
		current = current->_map[*word];
		if (current == nullptr)
			return false;

		word++;
	}
	return current->_leaf;
}
