#include <iostream>
#include <queue>

using namespace std;
using xy = struct xy{int x,y;};

int dx[8] = {-2,-1,1,2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int Chess(int I, int sx, int sy, int ex, int ey);
bool IsSafe(int x, int y, int I);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int T,I,sx,sy,ex,ey,ret;
	
	cin >> T;
	
	while(T--)
	{
		cin >> I >> sx >> sy >> ex >> ey;
		ret = Chess(I,sx,sy,ex,ey);
		cout << ret << "\n";
	}
}

int Chess(int I, int sx, int sy, int ex, int ey)
{
	int i,nx,ny;
	int Map[I][I] = {0,};
	queue<xy> q;
	
	q.push({sx,sy});
	Map[sy][sx] = 1;
	
	if(sx == ex && sy == ey)	return 0;
	
	while(!q.empty())
	{
		auto [x,y] = q.front();
		q.pop();
		
		for(i=0; i<8; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(nx == ex && ny == ey)	return Map[y][x];
			
			if(!IsSafe(nx,ny,I) || Map[ny][nx] != 0)	continue;
			
			q.push({nx,ny});
			Map[ny][nx] = Map[y][x] + 1;
		}
	}
}

bool IsSafe(int x, int y, int I)
{
	return x>=0 && y>=0 && x<I && y<I;
}