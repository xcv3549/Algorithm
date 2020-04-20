#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];
int visited[100001];
int relation[100001];

void DFS(int idx);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int N,i,node,edge;
	
	cin >> N;
	
	for(i=0; i<N-1; i++)
	{
		cin >> node >> edge;
		
		adj[node].push_back(edge);
		adj[edge].push_back(node);
	}
	
	DFS(1);
	
	for(i=2; i<=N; i++)
		cout << relation[i] << "\n";
}

void DFS(int idx)
{
	visited[idx] = 1;
	
	for(int i : adj[idx])
	{
		if(!visited[i])
		{
			relation[i] = idx;
			DFS(i);
		}
	}
}