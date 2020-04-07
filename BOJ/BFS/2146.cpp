#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using xy = struct xy{int x,y;};
using bridge = struct bridge{int x,y,dist,i;};

int N;
int Map[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool visited[100][100];
bool B_visited[100][100][100];

bool IsSafe(int x, int y);
void Find_Island(int x, int y,int Island_cnt);
int BFS();
	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int i,j,ans,Island_cnt=1,min=987654321;
	
	cin >> N;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			cin >> Map[i][j];
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			if(Map[i][j] && !visited[i][j])
			{
				Find_Island(j,i,Island_cnt);
				Island_cnt++;
			}
	
	cout << BFS() << endl;
}

bool IsSafe(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < N;	
}

void Find_Island(int x, int y,int Island_cnt)
{
	int nx,ny,i;
	queue<xy> q;
	q.push({x,y});
	
	Map[y][x] = Island_cnt;
	visited[y][x] = true;
	
	
	while(!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		q.pop();
		
		for(i=0; i<4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(!IsSafe(nx,ny))	continue;
			
			if(Map[ny][nx] && !visited[ny][nx])
			{
				Map[ny][nx] = Island_cnt;
				visited[ny][nx] = true;
				q.push({nx,ny});
			}
		}
	}
}

int BFS()
{
	int i,j,x,y,nx,ny;
	queue<bridge> q;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			if(Map[i][j])
				q.push({j,i,0,Map[i][j]}) , B_visited[i][j][Map[i][j]] = true;
	
	while(!q.empty())
	{
		auto pos = q.front();
		q.pop();
		
		for(i=0; i<4; i++)
		{
			nx = pos.x + dx[i];
			ny = pos.y + dy[i];
			
			if(!IsSafe(nx,ny))	continue;
			
			if(!B_visited[ny][nx][pos.i])
			{
				if(Map[ny][nx])	return pos.dist;
				
				else
				{
					B_visited[ny][nx][pos.i] = true;
					q.push({nx,ny,pos.dist+1,pos.i});
				}
			}
		}
	}
	
	return 0;
}