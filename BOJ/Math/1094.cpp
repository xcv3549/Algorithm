#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int X, count = 1;
    int stick = 64;
    int sum = 64;
    
    cin >> X;
    
    while(sum != X){
        stick /= 2;
        count++;
        
        if(X <= sum-stick){
            sum -= stick;
            count--;
        }
    }
    
    cout << count;
    return 0;
}
