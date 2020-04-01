#include <iostream>

using namespace std;

int N,M;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};
int Map[50][50];
bool visited[50][50];

int Robot(int x, int y, int dir);
bool IsSafe(int x, int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int i,j,x,y,dir;
	
	cin >> N >> M;
	
	cin >> y >> x >> dir;
	
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
			cin >> Map[i][j];
		
	cout << Robot(x,y,dir+100000000) << endl;
}

bool IsSafe(int x, int y)
{
	return x >= 0 && y >= 0 && x < M && y < N;
}

int Robot(int x, int y, int dir)
{
	int i,nx,ny,cnt=0;
	bool All_clean;

	while(1)
	{
		if(!visited[y][x])
		{
			visited[y][x] = true;
			cnt++;
		}
		
		All_clean = true;
		
		for(i=dir; i>dir-4; i--)
		{
			nx = x + dx[(i-1)%4];
			ny = y + dy[(i-1)%4];
			
			if(!IsSafe(nx,ny))	continue;
			
			if(!visited[ny][nx] && !Map[ny][nx])
			{
				All_clean = false;
				x = nx;
				y = ny;
				dir = i-1;
				
				break;
			}
		}
		
		if(All_clean)
		{
			nx = x + dx[(dir+2)%4];
			ny = y + dy[(dir+2)%4];
			
			if(Map[ny][nx])	break;
			else
			{
				x = nx;
				y = ny;
				continue;
			}
		}
	}

	return cnt;
}