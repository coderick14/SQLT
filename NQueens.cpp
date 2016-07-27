#include <iostream>
#include <vector>
#define N 8
using namespace std;

struct square	{
	int x,y;
};
char board[N][N];
vector<square> positions;
square s;

bool placeQueens(int col)	{
	
	//if N queens have been placed, then return true
	if(positions.size() == N)	{
		return true;
	}
	int i,j,k,flag;
	for(i=0;i<N;i++)	{

		flag = 1;
		//check the row
		for(j=col-1;j>=0;j--)	{
			if(board[i][j] == '1'){
				flag = 0;
				break;
			}
		}
		//check the diagonal towards top-left
		for(j=i-1,k=col-1;j>=0 && k>=0;j--,k--)	{
			if(board[j][k] == '1')	{
				flag = 0;
				break;
			}
		}
		//check the diagonal towards bottom-left
		for(j=i+1,k=col-1;j<N && k>=0;j++,k--)	{
			if(board[j][k] == '1')	{
				flag = 0;
				break;
			}
		}
		//if no queens are there in attacking positions, then we can safely place the queen here
		if(flag)	{
			board[i][col] = '1';
			s.x=i;s.y=col;
			positions.push_back(s);
			//if placing it here returns true, then we have been successful. Else backtrack.
			if(placeQueens(col+1))
				return true;
			else	{
				positions.pop_back();
				board[i][col] = '0';
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

	//initialize all squares to 0
	//Value of 1 stands for a queen
	for(i=0;i<N;i++)	{
		for(j=0;j<N;j++)
			board[i][j] = '0';
	}
	placeQueens(0);
	for(i=0;i<N;i++)	{
		for(j=0;j<N;j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

