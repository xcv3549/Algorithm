#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[51];
int leaf[51];
int cnt,rm;

void DFS(int idx);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int i,n,parent,root;
	
	cin >> n;
	
	for(i=0; i<n; i++)
	{
		cin >> parent;
			
		if(parent < 0)
			root = i;
		
		else
		{
			adj[parent].push_back(i);
			leaf[parent]++;
		}
	}
	
	cin >> rm;
	
	
	if(root != rm)
		DFS(root);
	
	cout << cnt << endl;
}

void DFS(int idx)
{
	for(int i : adj[idx])
	{
		if(i != rm)
			DFS(i);
		
		else
			if(adj[idx].size() == 1)
				cnt++;
	}
	
	if(leaf[idx] == 0)	cnt++;
}