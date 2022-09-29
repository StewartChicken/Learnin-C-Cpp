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
	
	myPoint.push_back(1);
	myPoint.push_back(2);

	cluster.classify(data, 2, myPoint);

	return 0;
}