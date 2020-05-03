#include <iostream>

using namespace std;

int P[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,B,C,i,p_num;
    int64_t ans=0;
    
    cin >> N;
    
    for(i=0; i<N; i++)
        cin >> P[i];
    
    cin >> B >> C;
    
    ans += N;
    
    for(i=0; i<N; i++)
    {
        p_num = P[i] - B;
        
        if(p_num > 0)
        {
            if(p_num % C > 0)   ans += p_num/C + 1;
            else            ans += p_num/C;
        }
    }
    
    cout << ans << endl;
}