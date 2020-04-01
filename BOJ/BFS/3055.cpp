#include <iostream>
#include <queue>

using namespace std;
using T = struct T{int x,y;};

int R,C;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int Map[50][50];
queue<T> q;

int BFS();
bool IsSafe(int x, int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int i,j,Sx,Sy,ans;
	char pos;
	string s;
	
	cin >> R >> C;
	
	for(i=0; i<R; i++)
	{
		cin >> s;
		for(j=0; j<C; j++)
		{
			pos = s[j];
			
			switch(pos)
			{
				case 'S':
					Map[i][j] = 1;
					Sx = j;
					Sy = i;	
					break;
				
				case '*':
					Map[i][j] = -1;
					q.push({j,i});
					break;
				
				case 'X':
					Map[i][j] = -2;
					break;
					
				case 'D':
					Map[i][j] = -3;
					break;
			}
		}
	}
	
	q.push({Sx,Sy});
	
	ans = BFS();
	
	if(ans>0)	cout << ans << endl;
	else	cout << "KAKTUS" << endl;
	
}

int BFS()
{
	int i,nx,ny;
	char next;
	
	while(!q.empty())
	{
		auto [x,y] = q.front();
		q.pop();
			
		for(i=0; i<4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(!IsSafe(nx,ny))	continue;
			
			if(Map[ny][nx] < 0)
			{
				if(Map[ny][nx] == -3 && Map[y][x] > 0)	return Map[y][x];
				else								continue;
			}
			
			else if(Map[ny][nx] == 0)
			{
				if(Map[y][x] == -1)
				{
					Map[ny][nx] = -1;
					q.push({nx,ny});
				}

				else if(Map[y][x] > 0)
				{
					Map[ny][nx] = Map[y][x]+1;
					q.push({nx,ny});
				}	
			}
		}
	}
	
	return -1;
}

bool IsSafe(int x, int y)
{
	return x >= 0 && y >= 0 && x < C && y < R;
}