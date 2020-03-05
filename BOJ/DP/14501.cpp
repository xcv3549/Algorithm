#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,i,j;
    int cost = 0;
    vector<int> T;
    vector<int> P;
    vector<int> DP;

    cin >> N;
    
    T.assign(N+1,0);
    P.assign(N+1,0);
    DP.assign(N+1,0);
    
    for(i=1; i<=N; i++)
    {
        cin >> T[i] >> P[i];
        DP[i] = P[i];
    }
    
    for(i=2; i<=N; i++)
    {
        for(j=1; j<i; j++)
        {
            if((i-j) >= T[j])
                DP[i] = max(DP[i] , P[i] + DP[j]);
        }
    }

    for(i=1; i<=N; i++)
    {
        if(i+T[i] <= N+1)   cost = max(cost,DP[i]);
    }  

    cout << cost;
}
