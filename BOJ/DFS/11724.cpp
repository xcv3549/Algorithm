#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(int Node);

int nextNode;
vector<int> adj[1001];
bool Cache[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int Node,Edge,N,M,i;
	int count = 0;
	
	cin >> N >> M;
	
	for(i=1; i<=M; i++)
	{
		cin >> Node >> Edge;
		adj[Node].push_back(Edge);
		adj[Edge].push_back(Node);
	}
	
	for(i=1; i<=N; i++)
	{
		if(!Cache[i])
		{
			DFS(i);
			count++;
		}
	}
	
	cout << count << endl;
}

void DFS(int Node)
{
	Cache[Node] = true;
	
	for(int i=0; i<adj[Node].size(); i++)
	{
		nextNode = adj[Node][i];
		
		if(!Cache[nextNode])	DFS(nextNode);
	}
}