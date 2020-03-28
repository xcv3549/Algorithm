#include <iostream>
#include <queue>

using namespace std;
using T = struct T{int x,y;};

const int INF = 987654321;

int N,M;
int Map[101][101];
int Path[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool IsSafe(int x , int y);
void BFS();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int i,j;
	string s;
	
	cin >> N >> M;
	
	for(i=1; i<=M; i++)
	{
		cin >> s;
		
		for(j=1; j<=N; j++)
		{
			Map[i][j] = s[j-1] - '0';
			Path[i][j] = INF;
		}
	}
	
	BFS();
	
	if(N == 1 && M == 1)	Path[1][1] = 0;
	
	cout << Path[M][N] << endl;
}

bool IsSafe(int x , int y)
{
	return x >= 1 && y >= 1 && x <= N && y <= M;
}

void BFS()
{
	int i,nx,ny,room;
	queue<T> q;

	q.push({1,1});
	Path[1][1] = 0;
	
	while(!q.empty())
	{
		auto [x,y] = q.front();
		q.pop();
		
		for(i=0; i<4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
				
			if(!IsSafe(nx,ny))			continue;
			
			room = Path[y][x] + Map[ny][nx];
				
			if(Path[ny][nx] <= room)		continue;
			
			q.push({nx,ny});
			Path[ny][nx] = room;
		}
	}
}