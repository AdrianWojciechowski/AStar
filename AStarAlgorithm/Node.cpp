#include "Node.h"

Node::Node(int i, int j, Node end, Node* parent) {
	x = i;
	y = j;
	h = (int)pow(abs(end.x - x), 2) + (int)pow(abs(end.y - y), 2);
	this->parent = parent;
	if (parent)
		g = parent->g + (int)pow(abs(parent->x - x), 2) + (int)pow(abs(parent->y - y), 2);
	else
		g = -1;
}

Node::Node(int i, int j) {
	x = i;
	y = j;
	g = 0;
	h = 0;
	parent = NULL;
}

Node::~Node() {
	
}

const bool Node::operator>(const Node& q) const {
	return g + h > q.g + q.h;
}
const bool Node::operator<(const Node& q) const {
	return g + h < q.g + q.h;
}
const bool Node::operator==(const Node& q) const {
	return q.x == x && q.y == y;
}