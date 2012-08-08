#include<iostream>
#include<cmath>

using namespace std;
int main()
{
char circle[130][130];
int i,j,radius,graphHeight,graphWidth;
cout<<"Enter radius of circle you want: ";
cin>>radius;
cout<<"Enter graphWidth,graphHeight: ";
cin>>graphWidth>>graphHeight;
for(i=0;i<=graphHeight;i++)
    {
    for(j=0;j<=graphWidth;j++)
    circle[i][j]=' ';
    }


//vertical line
for(int y=0;y<=graphHeight;y++)
{ int x=graphWidth/2;                        
circle[y][x]='|';
}

//horizontal line
for(int x=0;x<=graphWidth;x++)
{ int y=graphHeight/2;
circle[y][x]='_';
}

////////circle/////////////////

int x1=graphHeight/2-radius;
for(int cx=-radius;cx<=radius;cx++) 
 {
 double cy=sqrt(radius*radius-cx*cx);
 int u=graphHeight/2-round(cy);
 circle[u][x1]='.';
 x1++;
 }
 

x1=graphHeight/2-radius;
for(int cx=-radius;cx<=radius;cx++) 
 {
 double cy=sqrt(radius*radius-cx*cx);
 int l=(graphHeight/2)+round(cy);
 circle[l][x1]='.';
 x1++;
 }
 
 
/////////////////////////////////

for(i=0;i<=graphHeight;i++)
    {
    for(j=0;j<=graphWidth;j++)
    { cout<<circle[i][j];
    }
    cout<<endl;
    }
}
    
    
    
    
