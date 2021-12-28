#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N,num,arrowCount = 0;
    int arrows[1000001];
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> num;
        
        if(arrows[num])
            arrows[num]--;
        else
            arrowCount++;
        
        arrows[num-1]++;
    }

    cout << arrowCount << "\n";
    
    return 0;
}
