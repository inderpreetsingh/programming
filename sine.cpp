#include"sine.h"

void SineWave :: input ()
{ 
/* Function to input value from user
and to check its validity
*/  
    cout<<"Press sineWaveY"<< "1 for horizontal wave, 2 for vertical wave ";
    cin>>choice;

    switch (choice)
    {
        case 1: horizontalWave();
		        break;
        case 2: verticalWave();
		        break;
        default: cout<<"Invalid number you entered\n";
    }
}



void SineWave :: horizontalWave ()
{
/* Function to represent horizontal Wave

*/
    startWave();
    for(row = 0; row <= sineHeight; row++)
	{ 
	    for(column = 0; column <= sineWidth; column++)
	    sine[row][column] = ' ';
	}

	row = originY;                   
	for(column = originX; column <= originX + sineWidth1; column++)  
	{
	    sine[row][column] = '-'; 
	}
	
	double pointStartX = graphStart;
	for(int sineWaveX = originX; sineWaveX <= originX + sineWidth1; sineWaveX++)      
	{
	    double sineWaveY = sin(pointStartX);
        double sineWaveY1 = - sineWaveY * (( middleOfGraphHeight / 5 ) * SCALING_FACTOR ) + originY;                
        int sineWaveY2 = round(sineWaveY1);
        sine[sineWaveY2][sineWaveX] = '*';
        pointStartX += unitStepX;
    }

	for(row = 0; row <= sineHeight; row++)
	{
	    for(column = 0; column <= sineWidth; column++)
	    { 
	        cout<<sine[row][column];
	    }
	    cout<<"\n";
	}
}
	


void SineWave :: verticalWave ()
{ 
/* Function to represent vertical wave

*/
    startWave();
	for(row = 0; row <= sineHeight; row++)
	{
	    for(column = 0; column <= sineWidth; column++)
	    sine[row][column] = ' ';
	}
	
	column = originX;               
	for(row = originY; row <= originY + sineHeight1; row++)
    {
        sine[row][column] = '|';
    }	    

    int sineWaveY = originY;
    for(double sineWaveX = graphStart; sineWaveX <= graphEnd; sineWaveX += unitStepY)
    { 
		double pointStartX = sin(sineWaveX);
		double pointStartX1 = pointStartX * ( ( middleOfGraphWidth / 5 ) * SCALING_FACTOR ) + originX;                                  
		int pointStartX2 = round(pointStartX1);
		sine[sineWaveY][pointStartX2] = '*';
		sineWaveY++;
    }
	
    for(row = 0; row <= sineHeight; row++)
	{
	    for(column = 0; column <= sineWidth; column++)
	    {
	        cout<<sine[row][column];
	    }
	    cout<<endl;
    } 
}

    
       
void SineWave :: startWave ()  
{
/* Function to input value from user

*/
    cout<<"Enter width and height of sine wave: ";
    cin>>sineWidth>>sineHeight;
    cout<<"Enter number of cycles you want: ";
    cin>>numberOfCycles;
    cout<<"Enter origin points pointStartX sineWaveY of sine graph: ";
    cin>>originX>>originY;
    cout<<"Enter scaling factor you want (1 to 5): ";
    cin>>SCALING_FACTOR;
    
    sineWidth1 = ( sineWidth / 5 ) * SCALING_FACTOR;
    sineHeight1 = ( sineHeight /5 ) * SCALING_FACTOR;
    middleOfGraphHeight = sineHeight / 2;
    graphStart = 0.;
    graphEnd = 360. * numberOfCycles;
    graphStart *= M_PI / 180;
    graphEnd *= M_PI / 180;
    range = graphEnd - graphStart;
    unitStepX = range / sineWidth1;
    unitStepY = range / sineHeight1;
    middleOfGraphWidth = sineWidth / 2;
}
