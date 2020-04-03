#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,M,i,j,k,n,e,ans,sum=0;
    int min = 987654321;
    int adj[101][101];
	
    cin >> N >> M;
    
	memset(adj,0x3f,sizeof(adj));
    
    for(i=0; i<M; i++)
    {
        cin >> n >> e;
        adj[n][e] = adj[e][n] =1;
    }
    
    for(k=1; k<=N; k++)
        for(i=1; i<=N; i++)
            for(j=1; j<=N; j++)
                if(adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
    
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
            sum += adj[i][j];
		
        if(sum < min)
		{
			min = sum;
			ans = i;
		}
		
		sum = 0;
    }
    
    cout << ans;
}