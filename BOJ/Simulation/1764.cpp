#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N,M,i,sz;
    string input;
    vector<string> A;
    vector<string> B;
    
    cin >> N >> M;
    
    A.resize(N);
    
    for(i=0; i<N; i++)
        cin >> A[i];
    
    sort(A.begin(),A.end());
    
    for(i=0; i<M; i++)
    {
        cin >> input;
        if(binary_search(A.begin(),A.end(),input) == 1)
            B.push_back(input);
    }
    
    sz = B.size();
    
    sort(B.begin(),B.end());
    
    cout << sz << "\n";
    for(i=0; i<sz; i++)
        cout << B[i] << "\n";
}
