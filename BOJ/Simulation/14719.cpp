#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int map[501][501] = {0,};
    int H,W,block;
    
    cin >> H >> W;
    for(int i=1; i<=W; i++) {
        cin >> block;
        for(int j=H; j>(H-block); j--) {
            map[j][i] = 1;
        }
    }
    
    int left_side, rain=0;
    
    for(int y=1; y<=H; y++) {
        left_side = 0;
        
        for(int x=1; x<=W; x++) {
            if(map[y][x] == 1) {
                if(left_side) {
                    rain += x - left_side - 1;
                    left_side = x;
                }
                
                else
                    left_side = x;
            }
        }
    }
    
    cout << rain;
    
    return 0;
}

