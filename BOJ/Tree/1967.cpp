#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int>> adj[10001];
int ans = 0;

int solve(int i);

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n,i,node,edge,cost;
	
	cin >> n;
	
	for(i=1; i<n; i++)
	{
		cin >> node >> edge >> cost;
		adj[node].push_back({edge,cost});
	}
	
	solve(1);
	
	cout << ans << endl;
}

int solve(int i)
{
	int a=0,b=0;
	
	for(auto E : adj[i])
	{
		int tmp = solve(E.first) + E.second;
		if(a < tmp)			b = a , a = tmp;
		else if(b < tmp)	b = tmp;
	}
	
	ans = max(ans , a+b);
	
	return a;
}
