#include <cmath>
#include "HashTable.h"
#include <iostream>

using namespace std;

class KNN{

    public:

        float euclideanDistance(vector<int>, vector<int>); //Vectors representing n-dimensional points
        unsigned int classification(HashMap, vector<int>);
};


//"point" parameter is the to-be-classified point
unsigned int KNN::classification(HashMap map, vector<int> point){
    int k = map.getNumElements();   
    if (k % 2 == 0){
        k ++;
    }else{
        k += 2;
    }

    //Vector of pairs which contain the class of a point as well as its distance to the to-be-classified point
    vector<pair<int, float>> distances;

    // Code assumes that classes start at 0 and increment up. Will break if a user inputs data to a key of '5'
    //without having input data to the keys of 0-4 prior
    for(int i{}; i < map.getNumElements(); i ++){ // Acceses each class data (vector)
        for(int j{}; j < map.findItemSize(i); j ++){ // Accesses each data point (pair within the vector)
            
            //Distance between to-be-classified point and the current nested-for-loop's iteration point
            float euclidDist = euclideanDistance(point, map.findItem(i)[j]);
            
            //Contains the class and the distance of each point
            pair<int, float> distance;

            distance.first = i; 
            distance.second = euclidDist;

            distances.push_back(distance);
        }
    }

    distances.shrink_to_fit();

    for(int i{}; i < distances.size(); i ++){
        cout << "Class: " << distances[i].first << " Distance: " << distances[i].second << endl;
    }

    float *closestClasses = new float(k); // Array of the 'k' nearest neighbors (nearest datasets)

    int tracker = 0;
    while(tracker < k){
        float currSmallest = distances[0].second;
        int removalIndex = 0;
        for(int i = 1; i < distances.size() - tracker; i ++){
            if(distances[i].second < currSmallest){
                removalIndex = i;
                currSmallest = distances[i].second; 
            }
        }

        closestClasses[tracker] = distances[removalIndex].first;
        distances.erase(distances.begin() + removalIndex);
        
        tracker ++;
    }
    
    // Detects which classification makes the most appearances, or which one has the most "neighbors" nearby
    int maxNumAppearances = 0;
    int mostFreqClass = 0;
    for(int i{}; i < map.getNumElements(); i ++){
        int numAppearances = 0;
        for(int j{}; j < k; j ++){
            if(closestClasses[j] == i){
                numAppearances ++;
            }
        }
        if(numAppearances > maxNumAppearances){
            maxNumAppearances = numAppearances;
            mostFreqClass = i;
        }
    }

    return mostFreqClass;

}


//This method takes two arguments, each of with are a pair of both the point value and the size of the point array
//Returns the euclidean distance between two points of n-dimension
float KNN::euclideanDistance(vector<int> p1, vector<int> p2){

    if(p1.size() != p2.size()){
        cout << "[WARNING] dimensions do not match!";
        return -99999;
    }

    float sum{};
  
    for(int i{}; i < p1.size(); i ++){
        sum += pow((p1[i]) - p2[i], 2);
    }

    return sqrt(sum);
}
