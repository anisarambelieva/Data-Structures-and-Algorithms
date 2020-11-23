#include <iostream>
using namespace std;

struct TrieNode
{
	TrieNode* children[26];
	bool isWordEnd;
};

struct TrieNode* getNode()
{
	TrieNode* pNode = new TrieNode;

	pNode->isWordEnd = false;

	for (int i = 0; i < 26; i++)
		pNode->children[i] = nullptr;

	return pNode;
}

void insert(TrieNode* root, string word)
{
	TrieNode* curr = root;

	for (int i = 0; i < word.length(); i++)
	{
		int index = word[i] - 'a';
		if (!curr->children[index])
		{
			curr->children[index] = getNode();
		}

		curr = curr->children[index];
	}

	curr->isWordEnd = true;
}

bool search(TrieNode* root, string word)
{
	TrieNode* curr = root;

	for (int i = 0; i < word.length(); i++)
	{
		int index = word[i] - 'a';
		if (!curr->children[index])
			return false;

		curr = curr->children[index];
	}

	return (curr != nullptr && curr->isWordEnd);
}

int main()
{
    int countWords;
    cin >> countWords;

	TrieNode* root = getNode();

	for (int i = 0; i < countWords; i++)
	{
		string wordToAdd;
		cin >> wordToAdd;
		insert(root, wordToAdd);
	}

	int countQueries;
	cin >> countQueries;

	for (int i = 0; i < countQueries; i++)
	{
		string wordToFind;
		cin >> wordToFind;

		bool res = search(root, wordToFind);
		
		if (res)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}
