#include <iostream>
#include <cmath>
#include "LinearRegression.h"

using namespace std;

// Arrays of X and y data points
int xPoints[] = {1, 2, 2, 4, 5, 6, 10, 11};
int yPoints[] = {2, 3, 4, 3, 7, 5, 8, 12};

// Size of each array
int s = sizeof(xPoints) / sizeof(xPoints[0]);

int main(){
        
    // Creates LinearRegression object
    LinearRegression linreg;
    
    // Predicts the y-value of an input x-value based on the linear regression equation derived from the data
    float x = linreg.predictYcoor(xPoints, yPoints, s, 3);

    cout << x;
    return 0;
}  
