#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    char circle[150][150];
    int row,column,radius,graphWidth;
    double graphHeight1;
    cout<<"Enter graph Width :";
    cin>>graphWidth;
    cout<<"Enter graph Height: ";
    cin>>graphHeight1;
    cout<<"Enter radius of circle you want: ";
    cin>>radius;
    int graphHeight = (graphHeight1/2) + 0.5;
    
    //define graph
    for(row = 0; row <= graphHeight; row++)
    {
        for(column = 0; column <= graphWidth; column++)
        circle[row][column] = ' ';
    }
    
    //Y-axis
    column = graphWidth/2;
    for(row = 0; row <= graphHeight; row++)
    {
        circle[row][column] = '|';
    }
   
    //X-axis
    row = graphHeight/2;
    for(column = 0; column <= graphWidth; column++)
    {
        circle[row][column] = '_';
    }
  
    //draw circle
    int circleLeft = graphWidth/2 - radius;
    for(int cX = - radius; cX <= radius; cX++)
    {
        double cY = (sqrt(radius * radius - cX * cX))/2.0;
        int lowerArc = (graphHeight/2) + round(cY);
        int upperArc = (graphHeight/2) - round(cY);
        circle[upperArc][circleLeft] = '.';
        circle[lowerArc][circleLeft] = '.';
     
        for(int upperFilled = upperArc + 1; upperFilled <= graphHeight/2; upperFilled++)
        circle[upperFilled][circleLeft] = '*';
        for(int lowerFilled = graphHeight/2; lowerFilled < lowerArc; lowerFilled++)
        circle[lowerFilled][circleLeft] = '*';
    
        circleLeft++;
    }
        
    //print circle
    
    for(row = 0; row <= graphHeight; row++)
    {
        for(column = 0; column <= graphWidth; column++)
        {
            cout<<circle[row][column];
        }
        cout<<endl;
    }
}
