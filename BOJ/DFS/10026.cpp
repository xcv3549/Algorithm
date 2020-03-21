#include <iostream>
#include <cstring>

using namespace std;

bool IsSafe(int x, int y);
void DFS(int x, int y, char Root);
void w_DFS(int x, int y, char Root);

int N;
char Picture[100][100];
int visited[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i,j;
	int cnt1=0 , cnt2=0;
	
	string s;
	
	cin >> N;
	
	for(i=0; i<N; i++)
	{
		cin >> s;
		
		for(j=0; j<s.size(); j++)
			Picture[i][j] = s[j];
	}
	
	memset(visited,0,sizeof(visited));
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(!visited[i][j])
			{
				DFS(j,i,Picture[i][j]);
				cnt1++;
			}
		}
	}		
	cout << cnt1 << " ";

	memset(visited,0,sizeof(visited));
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(!visited[i][j])
			{
				w_DFS(j,i,Picture[i][j]);
				cnt2++;
			}
		}
	}		
	
	cout << cnt2 << endl;
}

bool IsSafe(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < N;
}

void DFS(int x, int y, char Root)
{
	if(!IsSafe(x,y))			return;	
	if(visited[y][x])			return;
	if(Picture[y][x] != Root)	return;
		
	visited[y][x] = 1;
	
	for(int i=0; i<4; i++)
		DFS(x+dx[i] , y+dy[i], Root);
}

void w_DFS(int x, int y, char Root)
{
	if(!IsSafe(x,y))				return;	
	if(visited[y][x])				return;
	if((Root != 'B') && (Picture[y][x] == 'B'))	return;
	if((Root == 'B') && (Picture[y][x] != 'B'))	return;
	
	visited[y][x] = 1;
	
	for(int i=0; i<4; i++)
		w_DFS(x+dx[i] , y+dy[i], Root);
}