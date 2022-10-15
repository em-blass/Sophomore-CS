/**
	CS280 BST
	@file bst.h
	@author Emmet Blassingame
	@version 10/7/2020
*/

#ifndef BST_H_
#define BST_H_
#include <iostream>
using namespace std;

struct movie
{
	string title;
	int rating;
	int year;
	movie* parent;
	movie* leftChild;
	movie* rightChild;
};


class bst {
private:
	movie* root;
	void destroy(movie* node);
public:
	bst();
	~bst();
	movie* search(string title);
	void addMovie(string name, int rating, int year);
	void deleteMovie(string title);
	movie* findMin(movie* node);
	void findMovie(string title);
	void printMoviesRating(int rating);
	void printMoviesRating(movie* node, int rating);
	void printMovies();
	void printMovies(movie* node);
};


bst::bst() {
	root = NULL;
}


void bst::destroy(movie* node)
{
	if (node->leftChild != NULL) {
		destroy(node->leftChild);
	}

	if (node->rightChild != NULL) {
		destroy(node->rightChild);
	}

	// cout << "Deleting: " << node->title << endl;
	delete node;
}


bst::~bst() {
	destroy(root);
}


movie* bst::search(string title)
{
	movie* node = new movie;
	node = root;

	while (node != NULL) {
		if (title == node->title) {
			return node;
		}

		else if (title < node->title) {
			if (node->leftChild == NULL) {
				node = NULL;
			}

			else {
				node = node->leftChild;
			}
		}

		else if (title > node->title) {
			if (node->rightChild == NULL) {
				node = NULL;
			}

			else {
				node = node->rightChild;
			}
		}
	}

	return node;
}


void bst::addMovie(string title, int rating, int year)
{
	movie* s = new movie;
	s->parent = NULL;
	s->rating = rating;
	s->title = title;
	s->year = year;

	if (root == NULL) {
		root = s;
		root->parent = NULL;
		root->leftChild = NULL;
		root->rightChild = NULL;
	}

	else {
		movie* m = new movie;
		m = root;

		while (s->parent != m) {
			if (s->title > m->title && m->rightChild == NULL) {
				m->rightChild = s;
				s->parent = m;
				s->leftChild = NULL;
				s->rightChild = NULL;
			}

			else if (s->title < m->title && m->leftChild == NULL) {
				m->leftChild = s;
				s->parent = m;
				s->leftChild = NULL;
				s->rightChild = NULL;
			}

			else if (s->title > m->title && m->rightChild != NULL) {
				m = m->rightChild;
			}

			else if (s->title < m->title && m->leftChild != NULL) {
				m = m->leftChild;

			}

		}
	}
}


movie* bst::findMin(movie* node)
{
	if (node == NULL) {
		return NULL;
	}

	if (node->leftChild == NULL) {
		return node;
	}

	else {
		return findMin(node->leftChild);
	}
}


void bst::deleteMovie(string title)
{
	movie* node = search(title);

	if (node != NULL) {
		if (node->rightChild == NULL && node->leftChild == NULL) {
			if (node->parent->leftChild == node) {
				node->parent->leftChild = NULL;
			}

			else {
				node->parent->rightChild = NULL;
			}

			cout << "\n" << endl;
			cout << node->title << " was removed." << endl;
			cout << "\n" << endl;
			delete node;
		}

		else if (node->rightChild == NULL) {
			if (node->parent->leftChild == node) {
				node->parent->leftChild = node->leftChild;
				node->leftChild->parent = node->parent;
			}

			else {
				node->parent->rightChild = node->leftChild;
				node->leftChild->parent = node->parent;
			}

			cout << "\n" << endl;
			cout << node->title << " was removed." << endl;
			cout << "\n" << endl;
			delete node;
		}

		else if (node->leftChild == NULL) {
			if (node->parent->leftChild == node) {
				node->parent->leftChild = node->rightChild;
				node->rightChild->parent = node->parent;
			}

			else {
				node->parent->rightChild = node->rightChild;
				node->rightChild->parent = node->parent;
			}

			cout << "\n" << endl;
			cout << node->title << " was removed." << endl;
			cout << "\n" << endl;

			delete node;
		}

		else if (node->leftChild != NULL && node->rightChild != NULL) {
			movie* min = findMin(node->rightChild);

			cout << "\n" << endl;
			cout << node->title << " was removed." << endl;
			cout << "\n" << endl;

			node->title = min->title;
			node->rating = min->rating;
			node->year = min->year;

			if (min->rightChild != NULL) {
				min->rightChild->parent = min->parent;
			}

			if (min->parent->leftChild == min) {
				min->parent->leftChild = min->rightChild;
			}

			else {
				min->parent->rightChild = min->rightChild;
			}

			delete min;
		}
	}

	else {
		cout << "Movie not found." << endl;
	}
}


void bst::findMovie(string title)
{
	movie* node = new movie;
	node = search(title);

	if (node == NULL) {
		cout << "\n" << endl;
		cout << "Movie not found." << endl;
		cout << "\n" << endl;
	}

	else {
		cout << "\n" << endl;
		cout << "Movie Info:" << endl;
		cout << "===========" << endl;
		cout << "Title: " << node->title << endl;
		cout << "Ranking: " << node->rating << endl;
		cout << "Year: " << node->year << endl;
		cout << "\n" << endl;
	}
}


void bst::printMoviesRating(int rating)
{
	printMoviesRating(root, rating);
}


void bst::printMoviesRating(movie* node, int rating)
{
	if (node != NULL)
	{
		printMoviesRating(node->leftChild, rating);
		if (node->rating >= rating) {
			cout << "Title: " << node->title << ", Rating: " << node->rating << ", Year: " << node->year << endl;
		}
		printMoviesRating(node->rightChild, rating);
	}
}



void bst::printMovies()
{
	printMovies(root);
}


void bst::printMovies(movie* node)
{
	if (node != NULL)
	{
		printMovies(node->leftChild);
		cout << "Title: " << node->title << ", Rating: " << node->rating << ", Year: " << node->year << endl;
		printMovies(node->rightChild);
	}
}

#endif