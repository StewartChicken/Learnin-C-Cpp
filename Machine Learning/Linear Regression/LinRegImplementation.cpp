#include <iostream>
#include <cmath>
#include "LinearRegression.h"

using namespace std;

int xPoints[] = {1, 2, 2, 4, 5, 6, 10, 11};
int yPoints[] = {2, 3, 4, 3, 7, 5, 8, 12};
int s = sizeof(xPoints) / sizeof(xPoints[0]);

int main(){
    
    LinearRegression linreg;
    
    float x = linreg.predictYcoor(xPoints, yPoints, s, 3);

    cout << x;
    return 0;
}  