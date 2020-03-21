#include <iostream>
#include <cstring>

using namespace std;

int N;
int visit[100][100] = {0,};
int Map[100][100] = {0,};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool IsSafe(int x, int y);
void Check_Sinked(int x, int y, int Rain);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	int i,j;
	int Safety_count = 0 , Rain = 0;
	int min = 1 , ret = 1;
	
	cin >> N;
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
		{
			cin >> Map[i][j];
			
			if(min > Map[i][j])	min  = Map[i][j];
		}
	
	Rain = min - 1;
	
	do
	{
		Rain++;
		Safety_count = 0;
		memset(visit,0,sizeof(visit));
		
		for(i=0; i<N; i++)
			for(j=0; j<N; j++)
				if(!visit[i][j] && Map[i][j] > Rain)
				{
					Check_Sinked(j,i,Rain);
					Safety_count++;
				}
		
		ret = Safety_count > ret ? Safety_count : ret;
		
	}while(Safety_count);
	
	cout << ret << endl;
}

bool IsSafe(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < N;
}

void Check_Sinked(int x, int y, int Rain)
{
	if(!IsSafe(x,y))	return;
	
	if(!visit[y][x] && Map[y][x] > Rain)
	{
		visit[y][x] = 1;
		
		for(int i=0; i<4; i++)
			Check_Sinked(x+dx[i] , y+dy[i] , Rain);
	}
	
	return;
}
