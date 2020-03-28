#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;
int N,M,S,E;
vector<int> Dist(1001,INF);
vector<pair<int,int>> adj[1001];

void Dijkstra();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int i,node,edge,cost;
	
	cin >> N >> M;
	
	for(i=1; i<=M; i++)
	{
		cin >> node >> edge >> cost;
		adj[node].push_back({edge,cost});
	}
	
	cin >> S >> E;
	
	Dijkstra();
	
	cout << Dist[E] << endl;
}

void Dijkstra()
{
	int i,x,d,nx,nd;
	priority_queue<pair<int,int>> q;
	
	q.push({0,S});
	Dist[S] = 0;
	
	while(!q.empty())
	{
		d = -q.top().first;
		x = q.top().second;
		q.pop();
		
		for(auto i : adj[x])
		{
			nd = d + i.second;
			nx = i.first;
			
			if(Dist[nx] > nd)
			{
				Dist[nx] = nd;
				q.push({-nd,nx});
			}
		}
	}
}