#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PPII = pair<int,pair<int,int>>;

const int INF = 987654321;
int N;
int Map[125][125];
int Dist[125][125];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool IsSafe(int x, int y);
void Dijkstra();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int i,j,test=0;
	
	do
	{
		test++;
		cin >> N;
		if(N == 0)	break;
		
		fill(&Dist[0][0],&Dist[124][125],INF);
		
		for(i=0; i<N; i++)
			for(j=0; j<N; j++)
				cin >> Map[i][j];
		
		Dijkstra();
		
		cout << "Problem " << test << ": " << Dist[N-1][N-1] << endl;
		
	}while(true);
}

bool IsSafe(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < N;
}

void Dijkstra()
{
	int i,nx,ny,d,x,y;
	priority_queue<PPII,vector<PPII>,greater<PPII>> q;
	q.push({Map[0][0],{0,0}});
	
	while(!q.empty())
	{
		d = q.top().first;
		x = q.top().second.first;
		y = q.top().second.second;
		
		q.pop();
		
		if(Dist[y][x] < d)	continue;
		
		for(i=0; i<4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(!IsSafe(nx,ny))	continue;
			
			if(Dist[ny][nx] > d + Map[ny][nx])
			{
				Dist[ny][nx] = d + Map[ny][nx];
				q.push({Dist[ny][nx] , {nx , ny}});
			}
		}
	}
}
