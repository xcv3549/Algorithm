#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PII = pair<int,int>;
using PPII = pair<int,pair<int,int>>;

const int INF = 987654321;
int Path[202];
int Next_V[201];

vector<PII> adj[201];

void Dijkstra(int s);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n,m,i,j,node,edge,cost;
	
	cin >> n >> m;
	
	for(i=0; i<m; i++)
	{
		cin >> node >> edge >> cost;
		adj[node].push_back({edge,cost});
		adj[edge].push_back({node,cost});
	}
	
	for(i=1; i<=n; i++)
	{
		fill(&Path[0] , &Path[n+1] , INF);
		
		Dijkstra(i);
		
		for(j=1; j<=n; j++)
		{
			if(i==j)	cout << "- ";
			else		cout << Next_V[j] << " ";
		}
		cout << "\n";
	}
}

void Dijkstra(int s)
{
	int d,v,nv,nd,sr;
	priority_queue<PPII, vector<PPII>, greater<PPII>> q;
	
	Path[s] = 0;
	
	for(auto i : adj[s])
	{
		q.push({i.second,{i.first,i.first}});
		
		Next_V[i.first] = i.first;
		Path[i.first] = i.second;
	}
	
	while(!q.empty())
	{
		d = q.top().first;
		v = q.top().second.first;
		sr = q.top().second.second;
		
		q.pop();
		
		if(Path[v] < d)	continue;
		
		for(auto i : adj[v])
		{
			nv = i.first;
			nd = i.second + d;
			
			if(Path[nv] > nd)
			{
				Path[nv] = nd;
				Next_V[nv] = sr;
				
				q.push({nd,{nv,sr}});
			}
		}
	}
}
