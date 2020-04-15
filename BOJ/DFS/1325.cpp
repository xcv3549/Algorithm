#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int computer_cnt[10001];
bool visited[10001];
vector<int> adj[10001];
vector<int> max_computer;

void DFS(int idx);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N,M,i,node,edge,ret = 0;
	vector<int> hacking_target;
	
	cin >> N >> M;
	
	for(i=0; i<M; i++)
	{
		cin >> node >> edge;
		adj[node].push_back(edge);
	}
	
	for(i=1; i<=N; i++)
	{
		memset(visited, false, sizeof(visited));
		DFS(i);
	}
	
	for(i=1; i<=N; i++)
	{
		if(ret < computer_cnt[i])
		{
			max_computer.clear();
			max_computer.push_back(i);
			ret = computer_cnt[i];
		}
		
		else if(ret == computer_cnt[i])
			max_computer.push_back(i);
		//cout << computer_cnt[i] << endl;
	}
	
	sort(max_computer.begin(), max_computer.end());
	
	for(i=0; i<max_computer.size(); i++)
	{
		cout << max_computer[i] << " ";
	}
	cout << endl;
}

void DFS(int idx)
{
	visited[idx] = true;
	
	for(auto next_idx : adj[idx])
	{
		if(!visited[next_idx])
		{
			computer_cnt[next_idx]++;
			DFS(next_idx);
		}
	}
}
