#include <iostream>
#include <cmath>
#include <vector>
#include "KMC.h"

using namespace std;

int xValues[] = {1, 3, 2, 4, 4, 6, 10, 12, 12, 15, 13, 16};
int yValues[] = {2, 2, 1, 4, 2, 3, 4, 7, 4, 5, 8, 7};

//size of data
const int s = sizeof(xValues) / sizeof(xValues[0]);

int main(){

	//creates and populates a vector of vectors containing the x and y valules
	vector<vector<int>> data;
	data.resize(s);

	for(int i = 0; i < s; i ++){
		data[i].push_back(xValues[i]);
		data[i].push_back(yValues[i]);
	}

	//

	Clustering cluster;

	vector<int> myPoint;
	myPoint.resize(2);

	myPoint.push_back(5);
	myPoint.push_back(4);

	myPoint.shrink_to_fit();

	cout << myPoint.size() << endl;

	return 0;
}