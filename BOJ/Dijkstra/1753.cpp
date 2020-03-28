#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PII = pair<int,int>;

const int INF = 987654321;
vector<int> Dist(20001,INF);
vector<pair<int,int>> adj[20001];

void Dijkstra(int start);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int V,E,S,i,j,u,v,w;
	
	cin >> V >> E >> S;
	
	for(i=0; i<E; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
	}
	
	Dijkstra(S);
	
	for(i=1; i<=V; i++)
	{
		if(Dist[i] == INF)	cout << "INF\n";
		else				cout << Dist[i] << "\n";
	}
}

void Dijkstra(int start)
{
	priority_queue<PII,vector<PII>,greater<PII>> q;
	
	q.push({0,start});
	Dist[start] = 0;
	
	while(!q.empty())
	{
		auto [d,u] = q.top();
		q.pop();
		
		if(Dist[u] < d) continue;
		
		for(auto i : adj[u])
		{
			auto [nu,nd] = i;
			nd += d;
			
			if(Dist[nu] > nd)
			{
				Dist[nu] = nd;
				q.push({nd,nu});
			}
		}
	}
}