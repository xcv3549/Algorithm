#include <iostream>
#include <queue>

using namespace std;

int N,M;
int Maze[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

bool IsSafe(int x, int y);
void BFS();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i,j;
	string s;
	
	cin >> N >> M;
	
	for(i=1; i<=N; i++)
	{
		cin >> s;
		
		for(j=1; j<=M; j++)
			Maze[i][j] = s[j-1] - '0';
	}
	
	BFS();
	
	cout << Maze[N][M] << endl;
	
}

bool IsSafe(int x, int y)
{
	return x >= 1 && y >= 1 && x <= M && y <= N;
}

void BFS()
{
	int i,x,y,nx,ny;
	queue<pair<int , int>> q;
	
	q.push(make_pair(1,1));
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		if(x == M && y == N)	break;
		
		for(i=0; i<4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(!IsSafe(nx,ny) || Maze[ny][nx] != 1)	continue;
			
			Maze[ny][nx] = Maze[y][x] + 1;
			q.push(make_pair(nx,ny));
		}
	}
}
