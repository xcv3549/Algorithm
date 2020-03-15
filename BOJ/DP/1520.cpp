#include <iostream>

using namespace std;

int Finding_Case(int row, int col);

static int dx[4] = {-1,0,1,0};
static int dy[4] = {0,-1,0,1};
int Map[501][501] = {0,};
int cache[501][501];
int M,N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i,j;
	
	cin >> M >> N;
	
	for(i=1; i<=M; i++)
		for(j=1; j<=N; j++)
		{
			cin >> Map[i][j];
			cache[i][j] = -1;
		}
	
	cout << Finding_Case(M,N) << endl;
}

int Finding_Case(int x, int y)
{
	if(x > M || y > N || x <= 0 || y <= 0)		return 0;
	if(x == 1 && y == 1)	return 1;
	
	if(cache[x][y] != -1)	return cache[x][y];
	
	else
	{
		int Pos_val = Map[x][y];
		int i,nextX,nextY;
		
		cache[x][y] = 0;
		
		for(i=0; i<4; i++)
		{
			nextX = x+dx[i];
			nextY = y+dy[i];
			
			if(Pos_val < Map[nextX][nextY])
				cache[x][y] += Finding_Case(nextX , nextY);
		}
	}

	return cache[x][y];
}