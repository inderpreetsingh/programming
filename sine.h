#include<iostream>
#include<cmath>
using namespace std;

class SineWave
{ 
    private:
        char sine[150][150];
        int row,column,SCALING_FACTOR,numberOfCycles,sineWidth,sineHeight,sineWidth1,sineHeight1,originX,originY,choice;
        double middleOfGraphWidth,middleOfGraphHeight,graphStart,graphEnd,range,unitStepX,unitStepY;
    
    public:
        void input();
        void horizontalWave();
        void verticalWave();
        void startWave();
};
