#include <cmath>
#include <iostream>

class LinearRegression{
    public:

        //m = (  (  (avg(X) * avg(y))  - avg(X*y)  )  /  ( (avg(X) ^ 2) - (avg(X ^ 2)) )  )
        float m;
        //b = avg(y) - m * (avg(X))
        float b;

    //y = mx + b

    float predictYcoor(const int X[], const int y[], int size, float xCoor){
        findB(X, y, size);

        //std::cout << m;

        return ((float)xCoor * m) + b;
    }

    void findB(const int X[], const int y[], int size){
        findM(X, y, size);
        b = mean(y, size) - m * (mean(X, size));
    }
    
    void findM(const int X[], const int y[], int size){
        m = ((mean(X, size) * mean(y, size)) - meanMult(X, y, size)) / (pow(mean(X, size), 2) - meanPower(X, size));
        //m = (mean(X, size) * mean(y, size)) - meanMult(X, y, size);
        //std::cout << m;
    }

    float meanPower(const int X[], int size){
        float productSum = 0;
        for(int i = 0; i < size; i ++){
            productSum += pow(X[i], 2);
        }

        return productSum / float(size);
    }
    float meanMult(const int X[], const int y[], int size){
        float productSum = 0;

        for(int i = 0; i < size; i ++){
            productSum += X[i] * y[i];
        }

        return productSum / float(size);
    }

    float mean(const int points[], const int size){
        int sum = 0;
        for(int i = 0; i < size; i ++){
            sum += points[i];
        }

        return float(sum) / float(size);
    }

};
