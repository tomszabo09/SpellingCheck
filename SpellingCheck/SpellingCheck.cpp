#include "trie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int main()
{
    Trie trie;
    shared_ptr<Trie> head = nullptr;
    ifstream inputFile("wordsEn.txt");
    while (!inputFile.eof())
    {
        string line;
        getline(inputFile, line);
        if (line != "")
        {
            const char* word = line.c_str();
            trie.Insert(head, word);
        }
    }

    cout << "Please type some English words:" << endl;

    string s;
    vector<string> segList;
    getline(cin, s);
    stringstream text(s);
    string segment;
    while (getline(text, segment, ' '))
        segList.push_back(segment);

    for (size_t i = 0; i < segList.size(); ++i)
    {
        for (size_t j = 0; j < segList[i].size(); ++j)
        {
            if (!((segList[i][j] >= 65 && segList[i][j] <= 90) || (segList[i][j] >= 97 && segList[i][j] <= 122)))
                segList[i].erase(segList[i].begin() + j);
        }

        transform(segList[i].begin(), segList[i].end(), segList[i].begin(), tolower);

        const char* word = segList[i].c_str();
        if (trie.Search(head, word))
        {
            cout << "'" << word << "' is a VALID English word!" << endl;
        }
        else
            cout << "'" << word << "' is an INVALID English word!" << endl;
    }
}