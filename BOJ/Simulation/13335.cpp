#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n,w,L,cost;
int nowTime = 0;
int bridgeWeight = 0;
queue<int> onWating;
queue<pair<int,int>> onBridge;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> w >> L;
    for(int i=0; i<n; i++){
        cin >> cost;
        onWating.push(cost);
    }
        
    while(!onWating.empty() || !onBridge.empty()){
        nowTime++;
        
        if(!onBridge.empty()){
            pair<int,int> truck = onBridge.front();
            if(w <= nowTime - truck.second){
                bridgeWeight -= truck.first;
                onBridge.pop();
            }
        }
        
        if(!onWating.empty()){
            int tWeight = onWating.front();
            if(L >= bridgeWeight + tWeight){
                bridgeWeight += tWeight;
                onBridge.push(make_pair(tWeight, nowTime));
                onWating.pop();
            }
        }
        
    }
    
    cout << nowTime;
    
    return 0;
}
