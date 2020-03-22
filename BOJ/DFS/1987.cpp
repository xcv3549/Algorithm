#include <iostream>
#include <algorithm>

using namespace std;

int R,C;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char Board[21][21];
bool visited[26];

bool IsAvailable(int x , int y);
int DFS(int x , int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i,j,k,MaxMove;
	string s;
	
	cin >> R >> C;
	
	for(i=1; i<=R; i++)
	{
		cin >> s;
		k = 1;
		
		for(auto j : s)
			Board[i][k++] = j;
	}

	MaxMove = DFS(1,1);
	
	cout << MaxMove << endl;
	
}

bool IsAvailable(int x , int y)
{
	return x >= 1 && y >= 1 && x<= C && y <= R && !visited[Board[y][x] - 65];
}

int DFS(int x , int y)
{
	int ret = 0;
	int pos = Board[y][x] - 65;
	
	if(visited[pos])	return 0;
	else
	{
		visited[pos] = 1;
		
		for(int i=0; i<4; i++)
			if(IsAvailable(x+dx[i] , y+dy[i]))
				ret = max(ret , DFS(x+dx[i] , y+dy[i]));
		
		visited[pos] = 0;
		
		return ret + 1;
	}
}