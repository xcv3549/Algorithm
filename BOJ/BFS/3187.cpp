#include <iostream>
#include <queue>

using namespace std;

int R,C;
int Total_v = 0, Total_k =0;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char Map[251][251];
bool visited[251][251];
bool IsSafe(int x , int y);
void BFS(int sx, int sy);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int i,j;
	string s;
	
	cin >> R >> C;
	
	for(i=1; i<=R; i++)
	{
		cin >> s;
		for(j=0; j<C; j++)
			Map[i][j+1] = s[j];
	}
	
	for(i=1; i<=R; i++)
		for(j=1; j<=C; j++)
			if(!visited[i][j] && Map[i][j]!='#')
				BFS(i,j);
	
	cout << Total_k << " " << Total_v;
}

void BFS(int sx, int sy)
{
	int x,y,nx,ny;
	int v=0, k=0;
	queue<pair<int,int>> q;
	q.push({sx,sy});
	visited[sx][sy] = true;
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		if(Map[x][y] == 'k')	k++;
		if(Map[x][y] == 'v')	v++;

		for(int i=0; i<4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(!IsSafe(nx,ny) || visited[nx][ny])	continue;
			if(Map[nx][ny] == '#')					continue;
			
			q.push({nx,ny});
			visited[nx][ny] = true;
		}
	}
	
	if(k > v)	Total_k += k;
	else		Total_v += v;
	
}

bool IsSafe(int x , int y)
{
	return x >= 1 && y >= 1 && x <= R && y <= C;
}