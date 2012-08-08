#include<iostream>
#include<cmath>

using namespace std;
int main()
{
int i,j,graphHeight,graphWidth,length,height;
char rectangle[130][130];
cout<<"Enter graphWidth and graphHeight: ";
cin>>graphWidth>>graphHeight;
cout<<"Enter length and height of rectangle: ";
cin>>length>>height;

for(i=0;i<=graphHeight;i++)
for(j=0;j<=graphWidth;j++)
    { rectangle[i][j]=' ';
    }
    
//vertical line
for(int y=0;y<=graphHeight;y++)
{ int x=graphWidth/2;                        
rectangle[y][x]='|';
}

//horizontal line
for(int x=0;x<=graphWidth;x++)
{ int y=graphHeight/2;
rectangle[y][x]='_';
}

///////////////rectangle/////////////////////
int l=(graphWidth/2-length/2);
int k=(graphWidth/2-length/2)+length;
for(i=(graphHeight/2)-height/2;i<=(graphHeight/2)-height/2+height;i++)
{ rectangle[i][l]='.';
  rectangle[i][k]='.';
}

int p=graphHeight/2-height/2;
int q=(graphWidth/2-height/2)+height;
for(i=(graphWidth/2-length/2);i<=(graphWidth/2-length/2)+length;i++)
{
rectangle[p][i]='.';
rectangle[q][i]='.';
}

 
////////////////////////////////////////////

for(i=0;i<=graphHeight;i++)
    {
    for(j=0;j<=graphWidth;j++)
    { cout<<rectangle[i][j];
    }
    cout<<endl;
    }
}
    
    
    
    
