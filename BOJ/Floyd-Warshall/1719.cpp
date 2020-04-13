#include <iostream>

using namespace std;

const int INF = 987654321;
int Path[201][201];
int Next_V[201][201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n,m,i,j,k,node,edge,cost;
	
	cin >> n >> m;
	
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
		{
			if(i==j)	Path[i][j] = 0;
			else		Path[i][j] = INF;
		}
	
	for(i=0; i<m; i++)
	{
		cin >> node >> edge >> cost;
		Path[node][edge] = Path[edge][node] = cost;
		Next_V[node][edge] = edge;
		Next_V[edge][node] = node;
	}
	
	for(k=1; k<=n; k++)
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				if(Path[i][j] > Path[i][k] + Path[k][j])
				{
					Path[i][j] = Path[i][k] + Path[k][j];
					Next_V[i][j] = Next_V[i][k];
				}
					
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(i==j)	cout << "- ";
			else		cout << Next_V[i][j] << " ";
		}
		cout << "\n";
	}
}
