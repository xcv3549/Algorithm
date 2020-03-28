#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int S,E;
int Relation[101];
vector<int> adj[101];

void BFS();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M,n,e,i;
	
	cin >> N >> S >> E >> M;
	
	for(i=0; i<M; i++)
	{
		cin >> n >> e;
		adj[n].push_back(e);
		adj[e].push_back(n);
	}
	
	BFS();
	
	if(Relation[E])	cout << Relation[E]-1 << endl;
	else			cout << -1 << endl;
}

void BFS()
{
	int pos;
	queue<int> q;
	
	q.push(S);
	Relation[S] = 1;
	
	while(!q.empty())
	{
		pos = q.front();
		q.pop();
		
		for(auto i : adj[pos])
		{
			if(!Relation[i])
			{
				q.push(i);
				Relation[i] = Relation[pos]+1;	
			}
		}
	}
}