#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Clustering{

	public:

		//Returns a data point's classification based on input data
		//Three arguments: data, number classes, to-be-classified data point
		int classify(vector<vector<int>>, int, vector<int>);
		float distance(vector<int>, vector<int>);

};

int Clustering::classify(vector<vector<int>> data, int k, vector<int> point){

	return 0;
}

//Returns distance between two points (vectors)
float Clustering::distance(vector<int> p1, vector<int> p2){
	int size = p1.size();
	float sum{};

	for(int i{}; i < size; i ++){
		sum += pow((p1[i] - p2[i]), 2);
	}

	return sqrt(sum);
}
