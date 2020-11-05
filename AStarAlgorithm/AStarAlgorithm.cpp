#include <iostream>
#include <vector>

#include "Node.h"
#include "AStar.h"

using namespace std;

/*
* Adrian Wojciechowski
* A* algorithm
* 
* AStarAlgorithm.cpp contains example use of my implementation
* Need to use Node.h, Node.cpp and AStar.h file
* AStar class is a template which can use any data as array for map.
* Preferred types: short, int, char.
* 
* This implementation is usable for 2D tile map where colliders can be identified and put on map.
* 
* Remember that this algorithm needs a little bit of visible time for larger arrays.
* For games when there is a need to use algorithm continously its recomended to put algorithm in thread.
* Otherwise you may experience lag effect.
*/

int main()
{
	//example int array where 0 is path, 1 is collider, 2 is calculated path from beggining to the goal
	int map[20][20] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1
	};
	//Temporary array made to store map as int**
	int** temp = new int*[20];
	for (int i = 0; i < 20; i++) {
		temp[i] = new int[20];
		for (int j = 0; j < 20; j++) {
			temp[i][j] = map[i][j];
		}
	}
	//Drawing map
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	//Initialization AStar algorithm for int 20x20 array where 0 is free path, 1 is collider and 2 is calculated path fromg beggining to the goal
	AStar<int> path(temp, 20, 20, 0, 1, 2);
	//Running method to calculate path from first node point to the second node point
	int** result = path.Calculate(new Node(0, 0), new Node(11, 11));
	//Drawing result array
	cout << endl << endl;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << result[i][j];
		}
		cout << endl;
	}
	//Finishing example
	for (int y = 0; y < 20; y++)
		delete temp[y];
	delete temp;
	for (int y = 0; y < 20; y++)
		delete result[y];
	delete result;
	cin.get();
}