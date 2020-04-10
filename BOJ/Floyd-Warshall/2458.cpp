#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 987654321;
int Map[501][501];
bool visited[501][501];
vector<int> adj[501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N,M,i,j,k,n,e,cnt=0;
	bool isVisted;
	
	cin >> N >> M;
	
	//memset(Map,0x3f,sizeof(Map));
	
	for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
			Map[i][j] = INF;
	
	for(i=0; i<M; i++)
	{
		cin >> n >> e;
		adj[n].push_back(e);
		Map[n][e] = 1;
		visited[n][e] = true;
		visited[e][n] = true;
	}
	
	for(i=1; i<=N; i++)
		visited[i][i] = true;
	
	for(k=1; k<=N; k++)
		for(i=1; i<=N; i++)
			for(j=1; j<=N; j++)
				if(Map[i][j] > Map[i][k] + Map[k][j])
				{
					Map[i][j] = Map[i][k] + Map[k][j];
					visited[i][j] = true;
					visited[i][k] = true;
					visited[k][j] = true;
					visited[j][i] = true;
					visited[k][i] = true;
					visited[j][k] = true;
				}
	
	
	for(i=1; i<=N; i++)
	{
		isVisted = true;
		
		for(j=1; j<=N; j++)
		{
			
			//cout << visited[i][j] << " ";
			
			if(!visited[i][j])
			{
				isVisted = false;
				break;
			}
		}
		
		//cout << endl;
		if(isVisted)	cnt++;
		
		
	}
	
	cout << cnt << endl;
}
