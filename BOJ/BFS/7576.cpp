#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int M,N;
int Box[1000][1000];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
queue<pair<int,int>> q;

bool IsSafe(int x , int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int i,j,ret=0;
	int x,y,nx,ny;
	
	cin >> M >> N;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			cin >> Box[i][j];
			
			if(Box[i][j] == 1)
				q.push(make_pair(j,i));
		}
	}
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for(i=0; i<4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(IsSafe(nx,ny) && Box[ny][nx] == 0)
			{
				q.push(make_pair(nx,ny));
				Box[ny][nx] = Box[y][x] + 1;
			}
		}
		
		ret = Box[y][x];
	}
	
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
			if(Box[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
	
	cout << ret-1 << endl;
}

bool IsSafe(int x , int y)
{
	return x >= 0 && y >= 0 && x < M && y < N;
}
