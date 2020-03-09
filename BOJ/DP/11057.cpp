#include <iostream>

using namespace std;

int DP[1001][10]={0,};

int main()
{
    int N,i,j,sum=0;
    
    cin >> N;
    
    for(i=0; i<=9; i++) DP[1][i] = 1;
    for(i=1; i<=N; i++) DP[i][0] = 1;
    
    for(i=2; i<=N; i++)
        for(j=1; j<=9; j++)
            DP[i][j] = (DP[i][j-1] + DP[i-1][j]) % 10007;
   
    for(i=0; i<=9; i++) sum += DP[N][i];
    
    cout << sum%10007 << endl;
}
