#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using T = struct T{int edge,cost;};
using PII = pair<int,int>; // cost , node

const int INF = 987654321;
int cost[1002][2];
//int graph[1001][2];
vector<T> adj[1001];
vector<T> reverse_adj[1001];

void Dijkstra(int N , int X);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M,X,i,n,e,c,ret=0;
		
	cin >> N >> M >> X;
	
	for(i=0; i<M; i++)
	{
		cin >> n >> e >> c;
		adj[n].push_back({e,c});
		reverse_adj[e].push_back({n,c});
	}
	
	fill(&cost[0][0] , &cost[N+1][1] , INF);
	
	Dijkstra(N,X);
	
	for(i=1; i<=N; i++)
		ret = max(ret , cost[i][0] + cost[i][1]);

	cout << ret << endl;
}

void Dijkstra(int N , int X)
{
	int nd,nv;
	
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push({0,X});
	cost[X][0] = 0;
	
	while(!q.empty())
	{
		auto [d,v] = q.top();
		q.pop();
		
		if(cost[v][0] < d)	continue;
		
		for(auto i : adj[v])
		{
			nd = d + i.cost;
			nv = i.edge;
			
			if(cost[nv][0] > nd)
			{
				cost[nv][0] = nd;
				q.push({nd,nv});
			}
		}
	}
	
	q.push({0,X});
	cost[X][1] = 0;
	
	while(!q.empty())
	{
		auto [d,v] = q.top();
		q.pop();
		
		if(cost[v][1] < d)	continue;
		
		for(auto i : reverse_adj[v])
		{
			nd = d + i.cost;
			nv = i.edge;
			
			if(cost[nv][1] > nd)
			{
				cost[nv][1] = nd;
				q.push({nd,nv});
			}
		}
	}
	
}