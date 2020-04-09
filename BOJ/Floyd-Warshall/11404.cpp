#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

int Map[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n,m,i,j,k,node,edge,cost;
    
    cin >> n >> m;
    
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            Map[i][j] = INF;
    
    for(i=0; i<m; i++)
    {
        cin >> node >> edge >> cost;
        
        if(Map[node][edge] > cost)
            Map[node][edge] = cost;
    }
    
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(Map[i][j] > Map[i][k] + Map[k][j])
                    Map[i][j] = Map[i][k] + Map[k][j];
                    
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==j)                cout << "0 ";
            else if(Map[i][j]==INF) cout << "0 ";
            else                    cout << Map[i][j] << " ";
        }
            
        cout << "\n";
    }
}
