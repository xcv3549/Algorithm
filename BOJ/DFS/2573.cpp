#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using T = struct T{int x,y,melt;};

vector<T> v;
int N,M;
int Map[300][300];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int visited[300][300];

void DFS(int x, int y);
bool IsSafe(int x, int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int i,j,cnt=0;
	int year=0;
	
	cin >> N >> M;
	
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
			cin >> Map[i][j];
	N--; M--;
	
	do
	{
		v.clear();
		cnt = 0;
		memset(visited,0,sizeof(visited));
		
		for(i=1; i<N; i++)
			for(j=1; j<M; j++)
				if(!visited[i][j] && Map[i][j])
				{
					DFS(i,j);
					cnt++;
				}
		
		if(cnt > 1)	break;
		
		for(i=0; i<v.size(); i++)
		{
			auto [x,y,melt] = v[i];
			
			Map[x][y] -= melt;
			if(Map[x][y] < 0)	Map[x][y] = 0;
		}
		
		year++;
		
	}while(v.size());
	
	if(cnt > 1)	cout << year << endl;
	else		cout << 0 << endl;
}

void DFS(int x, int y)
{
	int nx,ny,melt=0;
	
	visited[x][y] = true;
	
	for(int i=0; i<4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		
		if(!Map[nx][ny])
		{
			melt++;
			continue;
		}
		
		if(!IsSafe(nx,ny) || visited[nx][ny])	continue;
		DFS(nx,ny);
	}
	v.push_back({x,y,melt});
}

bool IsSafe(int x, int y)
{
	return x >= 1 && y >= 1 && x < N && y < M;
}