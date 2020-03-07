#include <iostream>

using namespace std;

unsigned int DP[31][31] ={0,};

unsigned int Count(int N, int M);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T,N,M,i;
    
    cin >> T;
    
    for(i=0; i<T; i++)
    {
        cin >> N >> M;

        cout << Count(N,M) << endl;
    }
}

unsigned int Count(int N, int M)
{
    if(!DP[N][M])
    {
        if(N==1)    return M;
        
        else
        {
            DP[N][M] = Count(N-1,M) * (M-N+1) / N;
            return DP[N][M];
        }
    }
    
    return DP[N][M];
}
