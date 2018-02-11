#ifndef WORDNODE_H
#define WORDNODE_H

#include <iostream>
#include <string>
using namespace std;

class WordNode
{

public:
	WordNode()
	{
		string word = NULL;
		left = NULL;
		right = NULL;
	}
	WordNode(string w, WordNode *l, WordNode *r)
	{
		word = w;
		left = l;
		right = r;
		lazy = true;
	}
	string word;
	int ta;
	bool lazy;
	int height;
	WordNode *left;
	WordNode *right;
}; 

#endif