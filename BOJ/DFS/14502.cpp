#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

enum lab_element
{
	Safe,
	Wall,
	Virus
};

int N,M,lab_size,cnt=0;
int lab[8][8];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int visited[8][8];

bool V_IsAvailable(int x , int y);
void V_DFS(int x , int y);
bool SetWall(int w1,int w2,int w3);
void UnsetWall(int w1,int w2,int w3);
	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int i,j,w1,w2,w3;
	int ret = 0;
	
	cin >> N >> M;
	
	lab_size = N*M;
	
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
			cin >> lab[i][j];
	
	for(w1=0; w1<lab_size-2; w1++)
	{
		for(w2=w1+1; w2<lab_size-1; w2++)
		{
			for(w3=w2+1; w3<lab_size; w3++)
			{
				if(!SetWall(w1,w2,w3))	continue;

				cnt = 0;
				memset(visited,0,sizeof(visited));
				
				for(i=0; i<N; i++)
					for(j=0; j<M; j++)
						if(V_IsAvailable(j,i) && lab[i][j] == Virus)
							V_DFS(j,i);
				
				for(i=0; i<N; i++)
					for(j=0; j<M; j++)
						if(!visited[i][j] && lab[i][j] == Safe)
							cnt++;
				
				UnsetWall(w1,w2,w3);
				
				ret = max(ret , cnt);
			}
		}
	}
	
	cout << ret << endl;
}


bool V_IsAvailable(int x , int y)
{
	return x >= 0 && y >= 0 && x < M && y < N && visited[y][x] == 0;
}

void V_DFS(int x , int y)
{
	visited[y][x] = 1;
	
	if(lab[y][x] == Wall)	return;
		
	for(int i=0; i<4; i++)
		if(V_IsAvailable(x+dx[i] , y+dy[i]))
			V_DFS(x+dx[i] , y+dy[i]);
}

bool SetWall(int w1,int w2,int w3)
{
	if(lab[w1/M][w1%M] != Safe || lab[w2/M][w2%M] != Safe || lab[w3/M][w3%M] != Safe)
		return false;

	lab[w1/M][w1%M] = Wall;
	lab[w2/M][w2%M] = Wall;
	lab[w3/M][w3%M] = Wall;	
	
	return true;
}

void UnsetWall(int w1,int w2,int w3)
{
	lab[w1/M][w1%M] = Safe;
	lab[w2/M][w2%M] = Safe;
	lab[w3/M][w3%M] = Safe;	
}
