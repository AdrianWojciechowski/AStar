#pragma once

#include "Node.h"
#include <vector>
#include <iostream>

template<typename T>
class AStar { 
private:
	T** map;
	T path;
	T wall;
	T way;
	int sizeX;
	int sizeY;

public:
	AStar(T** map, int sizeX, int sizeY, T path, T wall, T way) {
		this->map = new T*[sizeY];
		for (int y = 0; y < sizeY; y++) {
			this->map[y] = new T[sizeX];
		}
		for (int x = 0; x < sizeX; x++) {
			for (int y = 0; y < sizeY; y++) {
				this->map[y][x] = map[y][x];
			}
		}
		this->path = path;
		this->wall = wall;
		this->way = way;
		this->sizeX = sizeX;
		this->sizeY = sizeY;
	}

	~AStar() {
		for (int y = 0; y < sizeY; y++)
			delete map[y];
		delete map;
	}

	T** Calculate(Node* start, Node* end) {
		typename std::vector<Node*> open;
		typename std::vector<Node*> closed;
		T** result = new T*[sizeY];
		for (int i = 0; i < sizeX; i++) {
			result[i] = new T[sizeX];
		}
		for (int x = 0; x < sizeX; x++) {
			for (int y = 0; y < sizeY; y++) {
				result[y][x] = path;
			}
		}

		//Adding starting point to open
		open.push_back(start);

		while (!open.empty()) {
			//Declaring temporary best node
			Node* best = *(open.begin());
			//Searching best node in open
			for (std::vector<Node*>::iterator i = open.begin(); i < open.end(); i++) {
				if (*best > **i) {
					best = *i;
				}
			}
			//Swaping best node to the end
			for (std::vector<Node*>::iterator i = open.begin(); i < open.end(); i++) {
				if (**i == *best) {
					open.erase(i);
					open.push_back(best);
					break;
				}
			}
			//adding best node to the closed
			closed.push_back(open.back());
			if (*closed.back() == *end) break;
			open.pop_back();
			//opening new unique nodes
			int x = closed.back()->getX();
			int y = closed.back()->getY();
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					if ((i != 0 || j != 0) && i + y >= 0 && i + y < sizeY && j + x >= 0 && j + x < sizeX && map[i + y][j + x] == path) {
						Node temp = Node(j + x, i + y, *end, closed.back());
						bool exists = false;
						for (std::vector<Node*>::iterator i = open.begin(); i < open.end(); i++) {
							if (**i == temp) {
								exists = true;
							}
						}
						for (std::vector<Node*>::iterator i = closed.begin(); i < closed.end(); i++) {
							if (**i == temp) {
								exists = true;
							}
						}
						if (exists) continue;
						else open.push_back(new Node(j + x, i + y, *end, closed.back()));
					}
				}
			}
		}
		//getting path as parents from the end node to the first node without parent
		Node* path = closed.back();
		while (path->getParent() != NULL) {
			result[path->getY()][path->getX()] = 2;
			path = path->getParent();
		}

		delete start;
		delete end;
		return result;
	}

};