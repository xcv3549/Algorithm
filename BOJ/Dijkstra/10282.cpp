#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using PII = pair<int,int>;

const int INF = 987654321;
int costs[10002];
vector<PII> adj[10001];

void Dijkstar(int start);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int T,n,d,c,i,node,edge,cost,ret,cnt;
	
	cin >> T;
	
	while(T--)
	{
		cnt = ret = 0;
			
		cin >> n >> d >> c;
		
		for(i=1; i<=n; i++)
			adj[i].clear();
		
		fill(&costs[0],&costs[n+1],INF);
		
		for(i=0; i<d; i++)
		{
			cin >> edge >> node >> cost;
			adj[node].push_back({edge,cost});
		}
				
		Dijkstar(c);
		
		for(i=1; i<=n; i++)
			if(costs[i] != INF)
			{
				cnt++;
				ret = max(ret , costs[i]);
			}
		
		cout << cnt << " " << ret << endl;
	}
}

void Dijkstar(int start)
{
	int ns,nv;
	priority_queue<PII,vector<PII>,greater<PII>> q;
	
	q.push({0,start});
	costs[start] = 0;
	
	while(!q.empty())
	{
		auto [s,v] = q.top();
		q.pop();
		
		if(costs[v] < s)	continue;
		
		for(auto i : adj[v])
		{
			ns = s + i.second;
			nv = i.first;
			
			if(costs[nv] > ns)
			{
				costs[nv] = ns;
				q.push({ns,nv});
			}
		}
	}
}