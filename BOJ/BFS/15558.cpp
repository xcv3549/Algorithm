#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int Map[100001][2];
int visited[100001][2];
int dx[3] = {1,-1,0};
int dy[3] = {0,0,1};
int BFS(int N, int j);
bool IsAvailable(int x, int y , int s);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,k,i,j;
	string s;
	
	cin >> N >> k;
	dx[2] = k;
	
	for(i=0; i<2; i++)
	{
		cin >> s;
		for(j=0; j<N; j++)
			Map[j+1][i] = s[j] - '0';
	}
	
	cout << BFS(N,k) << endl;
}

int BFS(int N, int j)
{
	queue<tuple<int,int,int>> Game;
	int x,y,s,i,nx,ny;
	
	Game.push(make_tuple(1,0,1));
	visited[1][0] = 1;
	
	while(!Game.empty())
	{
		x = get<0>(Game.front());
		y = get<1>(Game.front());
		s = get<2>(Game.front());
		Game.pop();
		for(i=0; i<3; i++)
		{
			nx = x + dx[i];
			ny = (y + dy[i])%2;
			
			if(nx > N) return 1;
			
			if(!IsAvailable(nx,ny,s))	continue;
			
			Game.push(make_tuple(nx,ny,s+1));
			visited[nx][ny] = 1;
		}
	}
	
	return 0;
}

bool IsAvailable(int x, int y , int s)
{
	return !visited[x][y] && Map[x][y] && x > s;
}