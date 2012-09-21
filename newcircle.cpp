#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    char circle[150][150];
    int graphWidth;
    double graphHeight1,angle,radius;
    cout<<"Enter Height of a graph: ";
    cin>>graphHeight1;
    cout<<"Enter Width of a graph: ";
    cin>>graphWidth;
    cout<<"Radius of circle you want: ";
    cin>>radius;
    cout<<"Angle of arc: ";
    cin>>angle;
    int graphHeight = ( graphHeight1 / 2.0 ) + 0.5;
   
   
        while(angle > 360)
        {
            angle = angle - 360;
        }
   
    
    //define graph
    for(int row = 0; row <= graphHeight; row++)
    {
        for(int column = 0; column <= graphWidth; column++)
        circle[row][column]= ' ';
    }
        
    //horizontal axis     
    int row = graphHeight/2;
    for(int column = 0;column <= graphWidth; column++)
    {
        circle[row][column] = '-';
    }
            
    //vertical axis              
    int column = graphWidth/2;
    for(int row = 0; row <= graphHeight; row++)
    {
        circle[row][column]= '|';
    }
            
    //draw circle            
    if(angle >= 0 && angle <= 90)
    {   
        angle *= M_PI/180.;
        //sin(theeta)=perpendicular/hypotenous
        double perpendicular = radius * sin(angle);                   
        double baseTriangle = sqrt(radius * radius - perpendicular * perpendicular);
        int baseX1 = (radius - baseTriangle) + .5;
        for(int column = graphWidth/2 + radius, CX = radius;
            column >= graphWidth/2 - radius, CX >= radius - baseX1;
            column--,CX--)
        {
            //equation of circle i.e x*x+y*y=radius*radius
            double CY = (sqrt(radius * radius - CX * CX))/2.0;  
            int upperarc = graphHeight/2 - CY+.5;
            circle[upperarc][column] = '.';
         }
    }
    
    else if(angle > 90 && angle <= 180)
    {
        angle = angle - 90;
        angle *= M_PI/180.;
        //sin(theeta)=perpendicular/hypotenous
        double perpendicular1 = radius * sin(angle);                   
        int perpendicular = perpendicular1 + .5;
            
        for(int column = graphWidth/2 + radius,CX = radius;
            column >= graphWidth/2 - perpendicular, CX >= - perpendicular;
            column--, CX--)
        {
            double CY = (sqrt(radius * radius - CX * CX))/2.0;  
            int upperarc = graphHeight/2 - CY + .5;
            circle[upperarc][column] = '.';
        }
    }
        
    else if(angle > 180 && angle <= 270)
    { 
        //upper curve
        for(int column = graphWidth/2 + radius, CX=radius;
        column >= graphWidth/2 - radius, CX >= - radius;
        column--, CX--)
        {
            double CY = (sqrt(radius * radius - CX * CX))/2.0;  
            int upperarc = graphHeight/2 - CY + .5;
            circle[upperarc][column] = '.';
        }  
            
                         
         angle = angle - 180.;
         angle *= M_PI/180.;
         double perpendicular1 = radius * sin(angle);
         double baseTriangle = sqrt(radius * radius - perpendicular1 * perpendicular1);
         int base = radius - baseTriangle;
                          
         for(int column = graphWidth/2 - radius, CX = - radius;
             column <= (graphWidth/2 - radius) + base, CX <= - baseTriangle;
             CX++, column++)
         { 
             double CY = (sqrt(radius * radius - CX * CX))/2.0;
             int lowerarc = graphHeight/2 + CY + .5;
             circle[lowerarc][column] = '.';
         }  
                          
    }
         
    else if(angle > 270 && angle <= 360)
    {   
         //upper curve
         for(int column = graphWidth/2 + radius, CX = radius;
         column >= graphWidth/2 - radius, CX >= - radius;
         column--, CX--)
         {
             double CY = (sqrt(radius * radius - CX * CX))/2.0;  
             int upperarc = graphHeight/2 - CY + .5;
             circle[upperarc][column] = '.';
         }  
         
                         
         angle = angle - 180.;
         angle *= M_PI/180.;
         double perpendicular1 = radius * sin(angle);
         int perpendicular = perpendicular1;
         for(int column = graphWidth/2 - radius, CX=-radius;
            column <= (graphWidth/2-radius) + radius - perpendicular, CX <= radius - perpendicular;
            CX++, column++)
         {
              double CY = (sqrt(radius * radius - CX * CX))/2.0;
              int lowerarc = graphHeight/2 + CY + .5;
              circle[lowerarc][column] = '.';
         }  
     }   
    
    //print circle        
    for(int row = 0; row <= graphHeight; row++)
    {
         for(int column = 1; column <= graphWidth; column++)
         cout<<circle[row][column];
         cout<<endl;
    }
}           
