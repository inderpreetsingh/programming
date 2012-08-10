#include"sine.h"

void SineWave :: input()
{ int choice;
cout<<"Press\t"<< "1 for horizontal wave, 2 for vertical wave ";
cin>>choice;

switch(choice)
    {
    case 1: horizontalWave();
		    break;
    case 2: verticalWave();
		    break;
    default: cout<<"Invalid number you entered\n";
    }
}

//>>>>>>>>>>>>>function for horizontal wave>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void SineWave ::horizontalWave()
{
char sine[150][150];
int i,j,SF,nCycles,sineWidth,sineHeight,sineWidth1,sineHeight1,originX,originY;
cout<<"Enter width and height of sine wave: ";
cin>>sineWidth>>sineHeight;
cout<<"Enter number of cycles you want: ";
cin>>nCycles;
cout<<"Enter origin points x y of sine graph: ";
cin>>originX>>originY;
cout<<"Enter scaling factor you want (1 to 5): ";
cin>>SF; 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
sineWidth1=(sineWidth/5)*SF;
sineHeight1=(sineHeight/5)*SF;
double midY=sineHeight/2;
double graphStart=0.;
double graphEnd=360.*nCycles;
graphStart*=M_PI/180;
graphEnd*=M_PI/180;
double range=graphEnd-graphStart;
double unitStepX=range/sineWidth1;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for(int i=0;i<=sineHeight;i++)
	    { 
	    for(int j=0;j<=sineWidth;j++)
	    sine[i][j]='a';
	    }

	i=originY;                   
	for(int j=originX;j<=originX+sineWidth1;j++)  
	    {
	    sine[i][j]='-'; 
	    }
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	double x=graphStart;
	for(int s=originX;s<=originX+sineWidth1;s++)      
	    {
	    double y=sin(x);
        double Y=-y*((midY/5)*SF)+originY;                
        int t=round(Y);
        sine[t][s]='*';
        x+=unitStepX;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for(int i=0;i<=sineHeight;i++)
	    {
	    for(int j=0;j<=sineWidth;j++)
	        { 
	        cout<<sine[i][j];
	        }
	    cout<<"\n";
	    }
}
	
//>>>>>>>>>>>>>>>function for vertical wave>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void SineWave::verticalWave()
{ 
char sine[150][150];
int i,j,SF,nCycles,sineWidth,sineHeight,sineWidth1,sineHeight1,originX,originY;
cout<<"Enter width and height of sine wave: ";
cin>>sineWidth>>sineHeight;
cout<<"Enter number of cycles you want: ";
cin>>nCycles;
cout<<"Enter origin points x y of sine graph: ";
cin>>originX>>originY;
cout<<"Enter scaling factor you want (1 to 5): ";
cin>>SF;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
sineWidth1=(sineWidth/5)*SF;
sineHeight1=(sineHeight/5)*SF;
int midX=sineWidth/2;
double graphStart=0.,graphEnd=360.*nCycles;
graphStart*=M_PI/180.;
graphEnd*=M_PI/180.;
double range=graphEnd-graphStart;
double unitStepY=range/sineHeight1;
cout<<unitStepY<<"\n";
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for(i=0;i<=sineHeight;i++)
	    {
	    for(j=0;j<=sineWidth;j++)
	    sine[i][j]='a';
	    }
	
	int b=originX;               
	for(int a=originY;a<=originY+sineHeight1;a++)
        {
        sine[a][b]='|';
        }	    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int Y=originY;
    for(double s=graphStart;s<=graphEnd;s+=unitStepY)
		{ 
		double x=sin(s);
		double x1=x*((midX/5)*SF)+originX;                                  
		int X=round(x1);
		sine[Y][X]='*';
		Y++;
		}
	
    
////////////////////////////////////////////////////////////////////////
	for(i=0;i<=sineHeight;i++)
	    {
	    for(j=0;j<=sineWidth;j++)
	        {
	        cout<<sine[i][j];
	        }
	    cout<<endl;
	    } 
}

