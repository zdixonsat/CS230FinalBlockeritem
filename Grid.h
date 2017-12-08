//Grid.h
//Author: Drew
//11/26/17

#include<string>
#include<vector>
#include <iostream>
#include <windows.h>

using namespace std;
#ifndef GRID_H
#define GRID_H
class Grid
{
      public:
          Grid(int x, int y);
          bool insert(char player, int col);
          int win(char player);
          string view();
          void clear(int col);
      private:
          vector< vector<char> > matrix;
          int rowCount[7];  //row count of the same letter in each column
          int xSize;
          int ySize;
          int pointCount;
};

Grid::Grid(int x, int y)
{
	pointCount = 0;
    xSize = x;
    ySize = y;
    matrix.resize(x);
     for(int i = 0 ; i < x ; ++i)
    {
        matrix[i].resize(y);
    }
    
     for(int row = 0; row < x; row++)
         for (int col = 0; col < y; col++)
              matrix[row][col] = ' '; 
     for (int i = 0; i < y; i++)
         rowCount[i] = 0;       
}

int Grid::win (char player) {
    int i,j,k,count;
    count = 0;
    //checks horizontal
    for(i=0;i<xSize;i++)
        for(j=0;j<ySize-3;j++)
            if(matrix[i][j] != ' ' && matrix[i][j]==matrix[i][j+1] && matrix[i][j]==matrix[i][j+2])
                count++;
    //checks vertical
    for(i=0;i<xSize-2;i++)
        for(j=0;j<ySize;j++)
            if(matrix[i][j] != ' ' && matrix[i][j]==matrix[i+1][j] && matrix[i][j]==matrix[i+2][j])
                count++;
    //checks right diagonal
    for(i=0;i<xSize-2;i++)
        for(j=0;j<ySize-2;j++)
            if(matrix[i][j] != ' ' && matrix[i][j]==matrix[i+1][j+1] && matrix[i][j]==matrix[i+2][j+2])
            	count++;
    //checks left diagonal
    for(i=0;i<xSize-2;i++)
        for(j=0;j<ySize-2;j++)
            if(matrix[i][j] != ' ' && matrix[i][j]==matrix[i+1][j-1] && matrix[i][j]==matrix[i+2][j-2])
                count++;
    if (count - pointCount != 0){
    	int temp;
    	temp = count - pointCount;
		pointCount = count;
    	return temp;
    }
    return 0;
}
bool Grid::insert(char player, int col)
{
     if (matrix[0][col -1] != ' ')  //check if column is full
     {
     	if(col>ySize)
     		cout<<"OOPs, COLUMN "<<col<<" IS OUT OF THE GRID, PLEASE TRY AGAIN\n";
     		cout<<"OOPS, COLUMN "<<col<<" IS OUT OF THE GRID, PLEASE TRY AGAIN\n";
     	else
     		cout<<"OOPs, COLUMN "<<col<<" IS FULL, PLEASE SELECT A DIFFERENT COLUMN\n";
     		cout<<"OOPS, COLUMN "<<col<<" IS FULL, PLEASE SELECT A DIFFERENT COLUMN\n";
        return false;
     }
     else
     
         for (int row = xSize-1; row >= 0; row--)
             if (matrix[row][col -1] == ' ')
             {
                matrix[row][col -1] = player;
                return true;
             }
}
string Grid::view()
{
     string str;
     
     for (int row = 0; row < xSize; row++)
     {
         for (int col = 0; col < ySize; col++)
         {
             str += " | ";
             str += matrix[row][col];
         }
         str += " |\n";
     }
     str += " _____________________________\n";
     str += " | 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
     return str;
}

void Grid::clear(int col){
	for (int i = 0; i < 6; i++)
		matrix[i][col - 1] = ' ';
}

#endif
