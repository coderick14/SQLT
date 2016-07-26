//Implementation of stacks in backtracking algorithms

#include <iostream>
#include <vector>
#define n 4
using namespace std;

struct points	{
	int x,y;
};

const int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
char maze[n+2][n+2];
vector<points> path;
points p;

int findPath()	{
	if(path.empty())	{

		return 0;
	}
	int flag = 0;
	int curX = path.back().x;
	int curY = path.back().y;
	//check if path exists in DOWN,UP,RIGHT or LEFT
	for(int i=0;i<4;i++)	{
		//if path exists, move ahead recursively
		if(maze[curX+dx[i]][curY+dy[i]] == '0')	{
			p.x = curX + dx[i];
			p.y = curY + dy[i];
			path.push_back(p);
			maze[curX][curY] = '1';	//make it a wall so that the mouse doesn't go back
			flag = 1;
			if(findPath())
				return 1;
			else
				flag = 0;	//unset flag as this direction could not yield a path
		}
		else if(maze[curX+dx[i]][curY+dy[i]] == 'd')	{
			p.x = curX + dx[i];
			p.y = curY + dy[i];
			path.push_back(p);
			flag = 1;
			return 1;
		}
		
	}
	//if no path found, pop the present position and go back
	if(!flag)	{
		maze[path.back().x][path.back().y] = '0';
		path.pop_back();
		return 0;
	}
}

int main()	{
	int i,j;
	
	//Dimension of maze is N X N
	//1's represent walls and 0's represent paths 
	for(i=0;i<n+2;i++)	{
		//mark the edges as walls to prevent checking for boundary conditions
		maze[i][0]=maze[i][n+1]=maze[0][i]=maze[n+1][i]='1';
	}
	cout<<"Enter maze"<<endl;	//Enter 's' for source and 'd' for destination
	for(i=1;i<=n;i++)	{
		for(j=1;j<=n;j++)	{
			cin>>maze[i][j];
			if(maze[i][j] == 's')	{
				p.x = i;
				p.y = j;
			}
		}	
	}
	path.push_back(p);
	int res = findPath();

	if(path.empty())	{
		cout<<"No path exists"<<endl;
	}
	else	{
		for(i=0;i<path.size();i++)	{
			cout<<path[i].x<<" "<<path[i].y<<endl;
		}
	}

	return 0;
}
