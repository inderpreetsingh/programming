#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;
int main()
{
int i,j,base,altitude,graphHeight,graphWidth,step;
char triangle[130][130];
cout<<"Enter graph height and graph Width: ";
cin>>graphHeight>>graphWidth;
cout<<"Enter base and altitude of triangle such that altitude is greater than base: ";
cin>>base>>altitude;
if(altitude>base)
{
double unit=double(altitude/(base/2));
cout<<unit<<"\n";
step=unit+.5;
cout<<step<<"\n";
}
else
{
cout<<"sorry,base is less than altitude\n";
exit (0);
}

for(i=0;i<=graphHeight;i++)
for(j=0;j<=graphWidth;j++)
    { triangle[i][j]=' ';
    }

//vertical line
for(int y=0;y<=graphHeight;y++)
{ int x=graphWidth/2;                        
triangle[y][x]='|';
}

//horizontal line
for(int x=0;x<=graphWidth;x++)
{ int y=graphHeight/2;
triangle[y][x]='_';
}
////////////////////////////////////////////////////////
{
int k=graphHeight/2+altitude/2;
for(int i=(graphWidth/2-base/2);i<=(graphWidth/2-base/2)+base;i++)
{ triangle[k][i]='.';
}
}

for(int p=(graphHeight/2-altitude/2),q=graphWidth/2;p<=(graphHeight/2-altitude/2)+altitude,q>=graphWidth/2-base/2;p+=step,q--)
{ triangle[p][q]='.';
}

for(int p=(graphHeight/2-altitude/2),q=graphWidth/2;p<=(graphHeight/2-altitude/2)+altitude,q<=graphWidth/2+base/2;p+=step,q++)
{ triangle[p][q]='.';
}





///////////////////////////////////////////////////////

for(i=0;i<=graphHeight;i++)
{ 
for(j=0;j<=graphWidth;j++)
    { cout<<triangle[i][j];
    }
cout<<endl;
}
}

