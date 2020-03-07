#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> DP;
vector<vector<int>> Score;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T,n,t,i,j;
    
    cin >> T;
    
    for(t=0; t<T; t++)
    {
        cin >> n;
        
        DP.assign(n+1,vector<int>(2,0));
        Score.assign(n+1, vector<int>(2,0));
        
        for(i=0; i<2; i++)
            for(j=1; j<=n; j++)
                cin >> Score[j][i];
        
        DP[1][0] = Score[1][0];
        DP[1][1] = Score[1][1];
        
        for(i=2; i<=n; i++)
        {
            DP[i][0] = max(max(DP[i-1][0] , DP[i-1][1] + Score[i][0]) , DP[i-2][1] + Score[i][0]);
            DP[i][1] = max(max(DP[i-1][1] , DP[i-1][0] + Score[i][1]) , DP[i-2][0] + Score[i][1]);
        }
        
        cout << max(DP[n][0] , DP[n][1]) << endl;
    }
}
