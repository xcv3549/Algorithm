#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int Network[101];
vector<int> adj[101];

int DFS();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,E,i,n,e;
	
	cin >> N >> E;
	for(i=0; i<E; i++)
	{
		cin >> n >> e;
		adj[n].push_back(e);
		adj[e].push_back(n);
	}
	
	cout << DFS() << endl;
}

int DFS()
{
	int pos,cnt=-1;
	stack<int> s;
	s.push(1);
	Network[1] = 1;
	
	while(!s.empty())
	{
		pos = s.top();
		s.pop();
		cnt++;
		
		for(auto i : adj[pos])
		{
			if(!Network[i])
			{
				s.push(i);
				Network[i] = 1;	
			}
		}
	}
	
	return cnt;
}