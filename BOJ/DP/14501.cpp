#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,i,j;
    int cost=0;

    cin >> N;
    
    vector<int> T(N+1);
    vector<int> P(N+1);
    vector<int> DP(N+1);
    
    for(i=1; i<=N; i++) cin >> T[i] >> P[i];
    
    for(i=1; i<=N; i++) DP[i] = P[i];
    
    for(i=2; i<=N; i++)
        for(j=1; j<N; j++)
            if(i-j >= T[j]) DP[i] = max(DP[i] , DP[j] + P[i]);
            
    for(i=1; i<=N; i++)
        if(i+T[i] <= N+1)   cost = max(cost , DP[i]);
        
    cout << cost;
}
