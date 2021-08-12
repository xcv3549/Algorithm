//
//  main.cpp
//  BOJ_1976
//
//  Created by 경민 on 2021/08/12.
//

#include <iostream>
#include <algorithm>

using namespace std;

int g[201] = {0,};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N,M,linked,city;
    int group = 0, can_travel = 1;
    
    
    cin >> N >> M;
    
    for(int st=0; st<N; st++){
        for(int end=0; end<N; end++){
            
            cin >> linked;
            
            if(linked){
                
                if(g[st] && g[end]){
                    if(g[st] == g[end]) continue;
                    else{
                        int find_group = min(g[st], g[end]);
                        
                        for(int city=0; city<=end; city++)
                            if(g[city] == find_group)   g[city] = group;
                    }
                }
                
                else if(g[st] == 0 && g[end] == 0){
                    group++;
                    g[st] = group;
                    g[end] = group;
                }
                
                else if(g[st])      g[end] = g[st];
                else if(g[end])     g[st] = g[end];
            }
        }
    }
    
    for(int i=0; i<M; i++){
        
        cin >> city;
        
        if(i==0)
            group = g[city-1];
        
        else if(can_travel && group != g[city-1])
            can_travel = 0;
    }
    
    if(can_travel)  cout << "YES";
    else            cout << "NO";
    
    return 0;
}
