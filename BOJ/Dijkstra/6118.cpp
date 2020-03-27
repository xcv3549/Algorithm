#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;
int N,M;
int Dist[20001];
vector<int> adj[20001];

void BFS();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int i,node,edge,ans=0,cnt=0;
	
	cin >> N >> M;
	
	for(i=1; i<=N; i++)	Dist[i] = INF;
	
	for(i=0; i<M; i++)
	{
		cin >> node >> edge;
		adj[node].push_back(edge);
		adj[edge].push_back(node);
	}
	
	BFS();
	
	for(i=1; i<=N; i++)
	{
		if(Dist[ans] < Dist[i])
		{
			cnt = 1;
			ans = i;
		}
		
		else if(Dist[ans] == Dist[i])
			cnt++;
	}
	
	cout << ans << " " << Dist[ans] << " " << cnt << endl;
	
}

void BFS()
{
	int y,d;
	queue<int> q;
	
	q.push(1);
	Dist[1] = 0;
	
	while(!q.empty())
	{
		y = q.front();
		d = Dist[y]+1;
		q.pop();
		
		for(int& i : adj[y])
		{
			if(Dist[i] > d)
			{
				q.push(i);
				Dist[i] = d;
			}
		}
	}
}