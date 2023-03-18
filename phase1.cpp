#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    int matris1length, unitMatrisLength;
    cout<<"Enter the length of the first matris: ";
    cin>>matris1length;
 
    cout<<"Enter the length of the unit matris: ";
    cin>>unitMatrisLength;
    
    
   
    
  srand(time(0));

  int rastgeleMatris[matris1length][matris1length];

//matrix1length is generated randomly and printed on the screen
    for(int i = 0; i < matris1length; ++i)
    {
        for(int j = 0;  j < matris1length; ++j)
        {
            rastgeleMatris[i][j] = rand() % 10;
        }
    } 
  
  
    for(int i = 0; i < matris1length; ++i)
    {
      for(int j = 0; j < matris1length; ++j)
        cout<<rastgeleMatris[i][j]<<'\t';
        cout<<endl;
    }
    
    cout<<endl;
    
     int unitMatris[unitMatrisLength][unitMatrisLength];
    
    for (int i = 0;  i < unitMatrisLength; i++)
    {
        for (int j = 0; j < unitMatrisLength; j++)
        {
            if (i == j)
              unitMatris[i][j] = 1;
              
            else
                unitMatris[i][j] = 0;
             
            cout<<unitMatris[i][j]<<"  ";
        }
        cout << endl;
    }
        cout << endl;
    
   //calculating the size of the new matrix
    int newMatrisLength = matris1length + (unitMatrisLength - 1);
    int newMatris[newMatrisLength ][newMatrisLength ]; 
    
    //creating new matrix
    for(int i=0;i<newMatrisLength;i++)
    {
        for(int j=0;j<newMatrisLength;j++)
        {
            if(i > matris1length - 1)
                newMatris[i][j] = 0;
            else if(j > matris1length - 1)
                newMatris[i][j] = 0;
            else
                newMatris[i][j] = rastgeleMatris[i][j];
        }
    }
    
    //printing the new matrix to the screen
    for(int i=0;i<newMatrisLength;i++)
    {
        for(int j=0;j<newMatrisLength;j++)
        {
            cout<<newMatris[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;
    
   //multiplied matrix result
    int temporary = 0;
    int resultMatris[matris1length][matris1length];
    
    for(int k = 0; k < matris1length; k++)
    for(int i = 0; i < matris1length; i++)
    {
        for(int j = 0; j < unitMatrisLength; j++)
        {
            temporary += newMatris[k + j][i + j] *  unitMatris[j][j];
        }
        
        resultMatris[k][i] = temporary;
        
        temporary = 0;
    }
    
    for(int i = 0;i < matris1length; i++)
    {
        for(int j = 0; j < matris1length; j++)
        {
            cout << resultMatris[i][j];
            cout << "\t";
        }
        cout<<endl;
    }
    
    
    
    return 0;
}