#ifndef DICTIONARYIMP_CPP
#define DICTIONARYIMP_CPP
#include "Dictionary.h"
#include "WordNode.h"
using namespace std;

//Dictionary::Dictionary()
//{
//	t = new WordNode();
//}

int height(WordNode *t)
{
	return t == NULL ? -1 : t->height;
}

int max(int lhs, int rhs)
{
	return lhs > rhs ? lhs : rhs;
}


int getSizee(WordNode * & t)
{
	if (t == NULL)
		return 0;
	if (t->left == NULL && t->right == NULL)
		return 1;
	return getSizee(t->left) + getSizee(t->right);
}
void printSort(WordNode *& t)
{
	if (t != NULL)
	{
		printSort(t->left);
		cout << t->word << endl;
		printSort(t->right);
	}
}

void removee(string word, WordNode *&t)
{
	if (t == NULL)
		cout << "Word not found";
	else if (word < t->word)
		removee(word, t->left);
	else if (t->word < word)
		removee(word, t->right);
	else
		t->lazy = false;
}

/**
* Rotate binary tree node with left child.
* For AVL trees, this is a single rotation for case 1.
* Update heights, then set new root.
*/
void rotateWithLeftChild(WordNode * & k2)
{
	WordNode *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;
	k2 = k1;
}

/**
* Rotate binary tree node with right child.
* For AVL trees, this is a single rotation for case 4.
* Update heights, then set new root.
*/
void rotateWithRightChild(WordNode * & k1)
{
	WordNode *k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->right), k1->height) + 1;
	k1 = k2;
}

/**
* Double rotate binary tree node: first left child.
* with its right child; then node k3 with new left child.
* For AVL trees, this is a double rotation for case 2.
* Update heights, then set new root.
*/
void doubleWithLeftChild(WordNode * & k3)
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

/**
* Double rotate binary tree node: first right child.
* with its left child; then node k1 with new right child.
* For AVL trees, this is a double rotation for case 3.
* Update heights, then set new root.
*/
void doubleWithRightChild(WordNode * & k1)
{
	rotateWithLeftChild(k1->right);
	rotateWithRightChild(k1);
}

void insertt(string word, WordNode * & t)
{

	if (t == NULL)
		t = new WordNode(word, NULL, NULL);

	else if (word == t->word)
	{
		cout << "Duplicate found, word not inserted" << endl;
		t->ta += 1;
	}
	else if (word < t->word)
	{
		insertt(word, t->left);
		if (height(t->left) - height(t->right) == 2)
		if (word < t->left->word)
			rotateWithLeftChild(t);
		else
			doubleWithLeftChild(t);
	}
	else if (t->word < word)
	{
		insertt(word, t->right);
		if (height(t->right) - height(t->left) == 2)
		if (t->right->word < word)
			rotateWithRightChild(t);
		else
			doubleWithRightChild(t);
	}
	t->height = max(height(t->left), height(t->right)) + 1;
}

bool Dictionary::isEmpty()
{
	return t == NULL;
}

int Dictionary::getSize()
{
	return getSizee(t);
}



void Dictionary::insert(string word)
{
	insertt(word, t);
}


bool Dictionary::find(string word, WordNode *& t)
{
	if (t == NULL)
		return false;
	else if (word < t->word)
		return find(word, t->left);
	else if (t->word < word)
		return find(word, t->right);
	else
	{
		if (t->lazy == true)
			return true;
		return false;
	}

}
void Dictionary::printSorted()
{
	printSort(t);
}


void Dictionary::remove(string word)
{
	removee(word, t);
}

#endif
