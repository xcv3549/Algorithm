#include <iostream>
#define MAX 101

using namespace std;

int N;
int adj[MAX][MAX] = {0,};
int Route[MAX][MAX] = {0,};
int Cache[MAX] = {0,};

void DFS(int Node);

int main()	
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i,j;
		
	cin >> N;
	
	for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
			cin >> adj[i][j];
	
	for(i=1; i<=N; i++)
	{
		DFS(i);
		
		for(j=1; j<=N; j++)
			Route[i][j] = Cache[j];
		
		fill_n(Cache,MAX,0);
	}
		
	
	for(i=1; i<=N; i++)
	{
		for(j=1; j<=N; j++)
			cout << Route[i][j] << " ";
		
		cout << endl;
	}
	
}

void DFS(int Node)
{
	for(int i=1; i<=N; i++)
	{
		if(adj[Node][i] == 1 && !Cache[i])
		{
			Cache[i] = 1;
			DFS(i);
		}
	}
}