#include <iostream>
#include <vector>
#include <map>
#define N 8
using namespace std;

struct square	{
	int x,y;
};
int board[N][N];
vector<square> positions;
square s;
//to check safe rows and diagonals
int row[N]={0},diagonal2[2*N-1]={0};
map<int,int> diagonal1;

bool placeQueens(int col)	{
	
	//if N queens have been placed, then return true
	if(positions.size() == N)	{
		return true;
	}
	int i,j,k,flag;
	for(i=0;i<N;i++)	{

		flag = 1;
		//check if there are any queens in attacking positions
		if(row[i] || diagonal1[i-col] || diagonal2[i+col])
			flag = 0;	
		//if no queens are there in attacking positions, then we can safely place the queen here
		if(flag)	{
			board[i][col] = row[i] = diagonal1[i-col] = diagonal2[i+col] = 1;
			s.x=i;s.y=col;
			positions.push_back(s);
			//if placing it here returns true, then we have been successful. Else backtrack.
			if(placeQueens(col+1))
				return true;
			else	{
				positions.pop_back();
				board[i][col] = row[i] = diagonal1[i-col] = diagonal2[i+col] = 0;
			}
		}
	}
	//if no queen can be placed in this column, return false
	if(i==N)	{
		return false;
	}
}

int main()	{
	int i,j;

	for(i=(-N+1);i<N;i++)	
		diagonal1[i] = 0;
	//initialize all squares to 0
	//Value of 1 stands for a queen
	for(i=0;i<N;i++)	{
		for(j=0;j<N;j++)
			board[i][j] = 0;
	}
	placeQueens(0);
	for(i=0;i<N;i++)	{
		for(j=0;j<N;j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

