#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T,N,M,i;
    uint64_t count,D1,D2;
    
    cin >> T;
    
    for(i=0; i<T; i++)
    {
        cin >> N >> M;
        
        D1 = 1;
        D2 = 1;

        N = min(N,M-N);
        
        while(N)
        {
            D1 = D1 * (M-N+1);
            D2 = D2 * N;
            N--;
        }
        
        count = D1 / D2;
        
        cout << count << endl;
    }
    
}
