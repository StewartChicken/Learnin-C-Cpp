#include <cmath>
#include <iostream>

using namespace std;

//Public class that calculates the linear regression of a data set
class LinearRegression{
    public:

        //m = (  (  (avg(X) * avg(y))  - avg(X*y)  )  /  ( (avg(X) ^ 2) - (avg(X ^ 2)) )  )
        //float m;
        //b = avg(y) - m * (avg(X))
        //float b;
        
    //y = mx + b

    float predictYcoor(const int X[], const int y[], int size, float xCoor){
        float m = findM(X, y, size);
        float b = findB(X, y, size, m);

        return ((float)xCoor * m) + b;
    }

    //Prints the regression equation as well as the R squared value
    void getDataInfo(const int xPoints[], const int yPoints[], int size){
        float m = findM(xPoints, yPoints, size);
        float b = findB(xPoints, yPoints, size, m);

        float *predictedPoints = NULL;
        predictedPoints = new float[size];

        for(int i = 0; i < size; i ++){
            predictedPoints[i] = predictYcoor(xPoints, yPoints, size, xPoints[i]);
        }

        float R2 = r_squared(predictedPoints, yPoints, size);

        cout << "The linear regression equation is: y^ = " << m << "x + " << b << " with a coefficient of determination";
        cout << "of R^2 = " << R2;

    }

    //Calculates the y-intercept
    float findB(const int X[], const int y[], int size, float slope){
        return mean(y, size) - slope * (mean(X, size));
    }
    
    //Calculates the slope
    float findM(const int X[], const int y[], int size){
        return ((mean(X, size) * mean(y, size)) - meanMult(X, y, size)) / (pow(mean(X, size), 2) - meanPower(X, size));
    }

    //Returns the mean of all the X-values squared
    float meanPower(const int X[], int size){
        float productSum = 0;
        for(int i = 0; i < size; i ++){
            productSum += pow(X[i], 2);
        }

        return productSum / float(size);
    }

    //Returns the mean of the product of all the X and y values
    float meanMult(const int X[], const int y[], int size){
        float productSum = 0;

        for(int i = 0; i < size; i ++){
            productSum += X[i] * y[i];
        }

        return productSum / float(size);
    }

    //Returns the mean of any array of numbers
    float mean(const int points[], const int size){
        int sum = 0;
        for(int i = 0; i < size; i ++){
            sum += points[i];
        }

        return float(sum) / float(size);
    }

    //Returns the squared error between a predicted and observed array of data points
    float squaredError(const float predictedLine[], const int observedLine[], const int size){
        float sum = 0;
        for(int i = 0; i < size; i ++){
            sum += pow((observedLine[i] - predictedLine[i]), 2);
        }

        return sum;
    }

    //Returns the squared error between an observed array of data and a predicted average value for the observed data
    float squaredErrorMean(const float meanValue, const int observedLine[], int size){
        float sum = 0.0;

        for(int i = 0; i < size; i ++){
            sum += pow((observedLine[i] - meanValue), 2);
        }

        return sum;
    }

    //Calculates the R^2
    float r_squared(const float predictedLine[], const int observedLine[], const int size){
        float yHatSquaredError = squaredError(predictedLine, observedLine, size);
        float meanValue = mean(observedLine, size);
        
        float yMeanSquaredError = squaredErrorMean(meanValue, observedLine, size);

        return 1.0 - (yHatSquaredError / yMeanSquaredError);
        //return squaredError(predictedLine, observedLine, size);
    }

};
