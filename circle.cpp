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

int graphHeight=(graphHeight1/2)+0.5;
    for(row=0;row<=graphHeight;row++)
        {
        for(column=0;column<=graphWidth;column++)
        circle[row][column]=' ';
        }
    
///////////////vertical line/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int x=graphWidth/2;
    for(int y=0;y<=graphHeight;y++)
        {
        circle[y][x]='|';
        }
    
//////////////horizontal line////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int y=graphHeight/2;
    for(int x=0;x<=graphWidth;x++)
        {
        circle[y][x]='_';
        }
  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int x1=graphWidth/2-radius;
    for(int cX=-radius;cX<=radius;cX++)
        {
        double cY=(sqrt(radius*radius-cX*cX))/2.0;
        int lowerArc=(graphHeight/2)+round(cY);
        int upperArc=(graphHeight/2)-round(cY);
        circle[upperArc][x1]='.';
        circle[lowerArc][x1]='.';
     
            for(int upperFilled=upperArc+1;upperFilled<=graphHeight/2;upperFilled++)
            circle[upperFilled][x1]='*';
            for(int lowerFilled=graphHeight/2;lowerFilled<lowerArc;lowerFilled++)
            circle[lowerFilled][x1]='*';
    
        x1++;
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for(row=0;row<=graphHeight;row++)
        {
        for(column=0;column<=graphWidth;column++)
            {
            cout<<circle[row][column];
            }
        cout<<endl;
        }
}
