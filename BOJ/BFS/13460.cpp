#include <iostream>
#include <queue>

using namespace std;
using pos = struct pos{int rx,ry,bx,by,time;};
using xy = struct T{int rx,ry,bx,by;};
	
int N,M;
int RB[4];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char Map[11][11];

int BFS();
xy Marble_move(int rx, int ry, int bx, int by, int dir);
bool IsSafe(int x, int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int i,j,ans;
	string s;
	
	cin >> N >> M;
	
	for(i=0; i<N; i++)
	{
		cin >> s;
		for(j=0; j<M; j++)
		{
			Map[i][j] = s[j];
			
			if(Map[i][j] == 'R')
			{
				RB[0] = j, RB[1] = i;
				Map[i][j] = '.';
			}
			
			else if(Map[i][j] == 'B')
			{
				RB[2] = j, RB[3] = i;
				Map[i][j] = '.';
			}
		}
	}
	
	cout << BFS() << endl;
}

int BFS()
{
	int i,dir;
	queue<pos> Pos;
	queue<int> Direction;
	
	Pos.push({RB[0],RB[1],RB[2],RB[3],0});
	Direction.push(-1);
	
	while(!Pos.empty())
	{
		auto [rx,ry,bx,by,sec] = Pos.front();
		dir = Direction.front();
		
		Pos.pop();
		Direction.pop();
		
		for(i=0; i<4; i++)
		{
			if(dir>0 && (dir + 2)%2 == i)	continue;
			
			auto [nrx,nry,nbx,nby] = Marble_move(rx,ry,bx,by,i);
			int nsec = sec + 1;
			
			if(nsec > 10)
				return -1;
			
			if(nbx == -1)
				continue;
			
			if(nrx == rx && nry == ry && nbx == bx && nby == by)
				continue;
			
			if(Map[nry][nrx] == 'O')
				return nsec;
			
			Pos.push({nrx,nry,nbx,nby,nsec});
			Direction.push(i);
		}
	}
	
	return -1;
}

xy Marble_move(int rx, int ry, int bx, int by, int dir)
{
	bool R_falled, Moved;
	
	Moved = true;
	R_falled = false;
	
	while(Moved)
	{
		Moved = false;
		
		if(!R_falled)
		{
			rx += dx[dir];
			ry += dy[dir];
			
			if(Map[ry][rx] == 'O')
				R_falled = true;
			
			if(!IsSafe(rx,ry) || Map[ry][rx] == '#' || (rx == bx && ry == by))
			{
				rx -= dx[dir];
				ry -= dy[dir];
			}
			
			else if(Map[ry][rx] == '.')
				Moved = true;
		}
		
		bx += dx[dir];
		by += dy[dir];

		if(Map[by][bx] == 'O')
			return {rx,ry,-1,-1};

		else if(!IsSafe(bx,by) || Map[by][bx] == '#' || (rx == bx && ry == by))
		{
			bx -= dx[dir];
			by -= dy[dir];
		}

		else if(Map[by][bx] == '.')
			Moved = true;
	}
	
	return {rx,ry,bx,by};
}

bool IsSafe(int x, int y)
{
	return x >= 1 && y >= 1 && x < M-1 && y < N-1;
}