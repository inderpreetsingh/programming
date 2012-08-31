#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int row,column,graphWidth,length;
    double graphHeight1,height1;
    char rectangle[130][130];
    cout<<"Enter graphWidth: ";
    cin>>graphWidth;
    cout<<"Enter graphHeight: ";
    cin>>graphHeight1;
    cout<<"Enter length of rectangle: ";
    cin>>length;
    cout<<"Enter height of rectangle: ";
    cin>>height1;
    cout<<"\n";
    
    //scaling factor=2.0
    int height = (height1/2.0) + 0.5;     
    int graphHeight = (graphHeight1/2.0) + 0.5;
    for(row = 0; row <= graphHeight; row++)
    { 
        for(column = 0; column <= graphWidth; column++)
        {
            rectangle[row][column] = ' ';
        }
    }

    // Y-axis
    for(int y = 0; y <= graphHeight; y++)
    {
        int x = graphWidth/2;                        
        rectangle[y][x] = '|';
    }

    // X-axis
    for(int x = 0; x <= graphWidth; x++)
    {
        int y = graphHeight/2;
        rectangle[y][x] = '_';
    }

    // draw rectangle
    int heightSide1 = (graphWidth/2 - length/2);
    int heightSide2 = (graphWidth/2 - length/2) + length;
    for(row = (graphHeight/2) - height/2; row <= (graphHeight/2) - height/2 + height; row++)
    {
        rectangle[row][heightSide1] = '.';
        rectangle[row][heightSide2] = '.';
    }

    int lengthSide1 = graphHeight/2 - height/2;
    int lengthSide2 = (graphHeight/2 - height/2) + height;
    for(row = (graphWidth/2 - length/2); row <= (graphWidth/2 - length/2) + length; row++)
        {
        rectangle[lengthSide1][row] = '.';
        rectangle[lengthSide2][row] = '.';
        }

    // print rectangle
    for(row = 0; row <= graphHeight; row++)
        {
        for(column = 0; column <= graphWidth; column++)
            {
            cout<<rectangle[row][column];
            }
            cout<<endl;
        }
}   
