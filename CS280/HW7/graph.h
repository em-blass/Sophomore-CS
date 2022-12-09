/*
CS280 HW7 (graph.h)
@file graph.h
@author Emmet Blassingame
@version 11/28/2022
*/

#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
using namespace std;

#include <vector>
#include <queue>
#include <stack>
#include <climits>

struct adjCity;
struct city;

struct adjCity {
	city *v;
	int weight;
};

struct city {
	string key; // stores the name of the city
	vector<adjCity*> adjacent;
	bool visited; // for traversals (DFS/BFS)
	bool solved; // for Dijsktra's
	int distance; // for keeping track of distance in Dijkstra's
	city* parent; // for keeping track of parent in Dijkstra's
};

class graph {
private:
	vector<city*> vertices;
public:
	graph(); //constructor
	~graph(); //destructor
	void insertCity(string cityName); // inserts a new vertex (city)
	void insertEdge(string firstCity, string secondCity, int weight); // inserts edge with specified weight
	void printGraph(); // prints each vertex and it's adj vertices
	city* search(string cityName); // finds and returns city 
	void bft(string startCity); // prints out the vertices in a BF traversal from the starting city
	void dft(string startCity); // prints out the vertices in a DF traversal from the starting city
	city* dijkstras(string start, string end); // Dijkstra's algorithm!
	void printShortestPath(city* endV); // to be called after Dijkstra's
};

graph::graph() {
	cout << "Constructing." << endl;
}

graph::~graph() {
	cout << "Destructing..." << endl;

	for (int i = 0; i < vertices.size(); i++) {
		delete vertices[i];
	}
}

void graph::insertCity(string cityName) {
	cout << "Inserting " << cityName << endl;
	city* newCity = new city;
	newCity->key = cityName;
	newCity->visited = false;
	newCity->solved = false;
	newCity->distance = INT_MAX;
	newCity->parent = NULL;
	vertices.push_back(newCity);
}

void graph::insertEdge(string firstCity, string secondCity, int weight) {
	cout << "Inserting edges between " << firstCity << " and " << secondCity << " with weight " << weight << endl;
	city* first = search(firstCity);
	city* second = search(secondCity);

	if (first == NULL || second == NULL) {
		cout << "One or both towns not found" << endl;
		return;
	}

	adjCity* firstToSecond = new adjCity;
	firstToSecond->v = second;
	firstToSecond->weight = weight;
	first->adjacent.push_back(firstToSecond);

	adjCity* secondToFirst = new adjCity;
	secondToFirst->v = first;
	secondToFirst->weight = weight;
	second->adjacent.push_back(secondToFirst);
}

void graph::printGraph() {
	for(int i = 0; i < vertices.size(); i++) {
		cout << vertices[i]->key << "-->";

		for(int j = 0; j < vertices[i]->adjacent.size(); j++) {
			cout << vertices[i]->adjacent[j]->v->key << "(" << vertices[i]->adjacent[j]->weight << ") ";
		}

		cout << endl;
	}
}

city* graph::search(string cityName) {
	cout << "Searching for " << cityName << endl;

	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i]->key == cityName) {
			return vertices[i];
		}
	}
	 
	return NULL;
}

void graph::bft(string startCity) {
	cout << "Running BFT starting at " << startCity << endl;
	city* start = search(startCity);

	if (start == NULL) {
		cout << "City not found" << endl;
		return;
	}

	queue<city*> q;
	q.push(start);
	start->visited = true;

	while (!q.empty()) {
		city* current = q.front();
		q.pop();
		cout << current->key << endl;

		for (int i = 0; i < current->adjacent.size(); i++) {
			if (!current->adjacent[i]->v->visited) {
				q.push(current->adjacent[i]->v);
				current->adjacent[i]->v->visited = true;
			}
		}
	}

	for (int i = 0; i < vertices.size(); i++) {
		vertices[i]->visited = false;
	}
}

void graph::dft(string startCity) {
	cout << "Running DFT starting at " << startCity << endl;
	city* start = search(startCity);

	if (start == NULL) {
		cout << "City not found" << endl;
		return;
	}

	stack<city*> s;
	s.push(start);
	start->visited = true;

	while (!s.empty()) {
		city* current = s.top();
		s.pop();
		cout << current->key << endl;

		for (int i = 0; i < current->adjacent.size(); i++) {
			if (!current->adjacent[i]->v->visited) {
				s.push(current->adjacent[i]->v);
				current->adjacent[i]->v->visited = true;
			}
		}
	}

	for (int i = 0; i < vertices.size(); i++) {
		vertices[i]->visited = false;
	}
}

void graph::printShortestPath(city* endV) {
	if (endV->parent != NULL) {
		printShortestPath(endV->parent);
	}

	cout << endV->key << endl;
}

/*
* Method name: dijkstras
* Purpose: performs the book's description of Dijkstra's algorithm
*  to find the shortest path from start to end
* @param start - the city name we are starting from
* @param end - the city name that we are searching for
* @return - the pointer to the end vertex
* Notes - use the pseudocode from the book. You can feel free to create
*  another vector to use to keep track of solved vertices
*/
city* graph::dijkstras(string start, string end) {
	//implement here!
	return NULL;
}


#endif
