#pragma once

#include <math.h>

class Node {
private:
	int x;
	int y;
	int g;	//Between starting and this point
	int h;	//Between this and end (estimated);
	Node* parent;
public:
	//Constructor for most nodes
	Node(int i, int j, Node end, Node* parent);
	//Constructor for starting nodes
	Node(int i, int j);
	~Node();
	//Geters
	int getX() { return x; }
	int getY() { return y; }
	int getG() { return g; }
	int getH() { return h; }
	Node* getParent() { return parent; }
	//Operators
	const bool operator>(const Node& q) const;
	const bool operator<(const Node& q) const;
	const bool operator==(const Node& q) const;
};