#include <iostream>

using namespace std;

int Map[21][21];
int Move_Dir[1000];

int dice[7];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int N,M,K;

void solve(int x , int y);
bool IsSafe(int x , int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int x,y,i,j;
	
	cin >> N >> M >> y >> x >> K;
	
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
			cin >> Map[i][j];
	
	for(i=0; i<K; i++)
		cin >> Move_Dir[i];
	
	solve(x,y);
}

void solve(int x , int y)
{
	int i,dir,nx,ny,top;
	
	for(i=0; i<K; i++)
	{
		dir = Move_Dir[i];
		
		nx = x + dx[dir-1];
		ny = y +dy[dir-1];
		
		if(!IsSafe(nx,ny))	continue;
		
		x = nx;
		y = ny;
		
		top = dice[1];
		
		if(dir == 1)
		{
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = top;
		}
		
		else if(dir == 2)
		{
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = top;
		}
		
		else if(dir == 3)
		{
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = top;
		}
		
		else
		{
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = top;
		}
		
		if(Map[y][x] == 0)	Map[y][x] = dice[6];
		else
		{
			dice[6] = Map[y][x];
			Map[y][x] = 0;
		}
		
		cout << dice[1] << "\n";
	}
}

bool IsSafe(int x , int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}