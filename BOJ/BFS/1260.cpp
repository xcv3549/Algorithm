#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[1001];
bool visited[1001];

void DFS(int S);
void BFS(int S);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int N,M,S,i,n,e;
	
	cin >> N >> M >> S;
	
	for(i=0; i<M; i++)
	{
		cin >> n >> e;
		adj[n].push_back(e);
		adj[e].push_back(n);
	}
	
	for(i=1; i<=N; i++)
		sort(adj[i].begin(), adj[i].end());
	
	DFS(S);
	cout << endl;
	
	fill(visited, visited + N + 1, false);
	BFS(S);
}

void DFS(int S)
{
	cout << S << " ";
	visited[S] = true;
	
	for(int i : adj[S])
		if(!visited[i])	DFS(i);
}

void BFS(int S)
{
	int pos;
	queue<int> q;
	q.push(S);
	visited[S] = true;
	
	while(!q.empty())
	{
		pos = q.front();
		q.pop();
		cout << pos << " ";
		
		for(int i : adj[pos])
			if(!visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
	}
	cout << endl;
}

