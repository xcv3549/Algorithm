#include <iostream>
#include <queue>

using namespace std;
using T = struct T{int y,x; bool dig;};

int N,M;
int Map[1000][1000];
int visited[1000][1000][2];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int BFS();
bool IsAvaliable(int x, int y , int dig);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i,j;
	string s;
	
	cin >> N >> M;
	
	for(i=0; i<N; i++)
	{
		cin >> s;
		for(j=0; j<M; j++)
			Map[i][j] = s[j] - '0';
	}
	
	N--; M--;
	
	cout << BFS() << endl;
}

int BFS()
{
	int i,ny,nx,depth;
	queue<T> pos;
	
	pos.push({0,0,0});
	visited[0][0][0] = 1;
	
	while(!pos.empty())
	{
		auto [y,x,dig] = pos.front();
		pos.pop();
		
		depth = visited[y][x][dig];
		
		if(Map[y][x])	dig = true;
		if(y==N && x==M)	return depth;
		
		for(i=0; i<4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			
			if(!IsAvaliable(nx,ny,dig))		continue;
			if((dig && Map[ny][nx]))	continue;
			
			visited[ny][nx][dig] = depth + 1;
			pos.push({ny,nx,dig});
		}
	}
	
	return -1;
}

bool IsAvaliable(int x, int y , int dig)
{
	return x >= 0 && x <= M && y >= 0 && y <= N && !visited[y][x][dig];
}