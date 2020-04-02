#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using T = struct T{int x,y;};

int X,Y;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char Map[50][50];

int BFS(int sx , int sy);
bool IsSafe(int x, int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int i,j,ans = 0;
	string s;
	
	cin >> Y >> X;
	
	for(i=0; i<Y; i++)
	{	
		cin >> s;
		for(j=0; j<X; j++)
			Map[i][j] = s[j];
	}
	
	for(i=0; i<Y; i++)
		for(j=0; j<X; j++)
			if(Map[i][j]=='L')
				ans = max(ans,BFS(j,i));
				
	cout << ans;
}

int BFS(int sx , int sy)
{
	int Path[50][50]={0,};
	int i,nx,ny,x,y;
	queue<T> q;
	
	q.push({sx,sy});
	Path[sy][sx] = 1;
	
	while(!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		q.pop();
		
		for(i=0; i<4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(!IsSafe(nx,ny))							continue;
			if(Map[ny][nx] != 'L' || Path[ny][nx] != 0)	continue;
			
			q.push({nx,ny});
			Path[ny][nx] = Path[y][x] + 1;
		}
	}
	
	return Path[y][x] - 1;
}

bool IsSafe(int x, int y)
{
	return x>=0 && y>=0 && x<X && y<Y;
}