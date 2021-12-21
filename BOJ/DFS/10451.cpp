#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T;
    int arr[1002] = {0,};
    int checked[1002] = {0,};
    cin >> T;
    
    for(int t=0; t<T; t++){
        int per_length;
        cin >> per_length;
        
        memset(checked, 0, (per_length + 1) * sizeof(int));
        
        for(int i=1; i<=per_length; i++){
            cin >> arr[i];
        }
        
        int cycle = 0;
        for(int i=1; i<=per_length; i++){
            int idx = i;
            if(!checked[idx]){
                do{
                    checked[idx] = 1;
                    idx = arr[idx];
                }while(!checked[idx]);
                cycle++;
            }
        }
        
        cout << cycle << "\n";
    }
    
    return 0;
}
