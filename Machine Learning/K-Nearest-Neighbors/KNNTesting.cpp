#include <iostream>
#include <vector>
#include "NearestNeighbors.h" //HashTable.h is included in this import
using namespace std;

/*
vector methods:
push_back()
insert()
clear()
begin()
end()
shrink_to_fit()
capacity()
size()
*/

int main(){

    //Data points (unpaired)
    int classOneXValues[] = {1, 3, 2, 4, 4, 6};
    int classOneYValues[] = {2, 2, 1, 4, 2, 3};
    int classTwoXValues[] = {10, 12, 12, 15, 13, 16};
    int classTwoYValues[] = {4, 7, 4, 5, 8, 7};

    const int dataSize = 6;

    //Vectors (arrays) of vectors of numbers which represent the x, y, ..n coordinates of the data in each class
    vector<vector<int>> classOnePoints;
    vector<vector<int>> classTwoPoints;

    //Populates each vector
    for(int i{}; i < dataSize; i ++){
        vector<int> dataPointOne;
        vector<int> dataPointTwo;

        dataPointOne.push_back(classOneXValues[i]);
        dataPointOne.push_back(classOneYValues[i]);
        dataPointTwo.push_back(classTwoXValues[i]);
        dataPointTwo.push_back(classTwoYValues[i]);

        classOnePoints.push_back(dataPointOne);
        classTwoPoints.push_back(dataPointTwo);
    }

    classOnePoints.shrink_to_fit();
    classTwoPoints.shrink_to_fit();

    //Data set of classes and their data
    HashMap dataSet;
    dataSet.insertItem(0, classOnePoints);
    dataSet.insertItem(1, classTwoPoints);

    //to-be-classified point
    vector<int> myPoint;
    myPoint.push_back(7);
    myPoint.push_back(10);
    myPoint.shrink_to_fit();

    KNN k;

    int classification = k.classification(dataSet, myPoint);
    cout << classification;
    
    return 0;
}
