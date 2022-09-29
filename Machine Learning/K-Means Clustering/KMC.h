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

//Classifying method
int Clustering::classify(vector<vector<int>> data, int k, vector<int> point){

	//vector of pairs of distances and their respective indeces
	vector<pair<int, float>> distances;

	for(int i{}; i < k; i ++){ // For every classifiying point (to-be-created in this loop)

		for(int j{}; j < data.size(); j ++){ // Finds distance between every data point and the current classifying point

			pair<int, float> keyDistancePair;
			keyDistancePair.first = j;
			keyDistancePair.second = distance(data[j], point);

			distances.push_back(keyDistancePair);

			int numNeighbors = data.size() / k;
		}

	}

	for(int i{}; i < 12; i ++){
		cout << distances[i].first << ", " << distances[i].second << endl;
	}
	
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
