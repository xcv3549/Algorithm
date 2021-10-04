#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int princessCase = 0;
int connectCount = 0;
int somCount = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int visit[5][5] = {0,};
int selected[5][5] = {0,};
char map[5][5];
vector<pair<int,int>> princesses;

void make7Princess(int num);
bool isConnected();
void DFS(int y, int x);
bool isSomMoreThanFour();

int main(int argc, const char * argv[]) {
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> map[i][j];
        }
    }
    
    make7Princess(-1);
    
    cout << princessCase;
    return 0;
}

void make7Princess(int num){
    if(princesses.size() < 7){
        for(int i=num+1; i<25; i++){
            int y = i / 5;
            int x = i % 5;
        
            selected[y][x] = 1;
            princesses.push_back(make_pair(y,x));
            make7Princess(i);
            selected[y][x] = 0;
            princesses.pop_back();
        }
    }
    else{
        if(isConnected() && isSomMoreThanFour()){
            princessCase++;
        }
    }
}

bool isConnected(){
    memset(visit, 0, sizeof(visit));
    connectCount = 0;
    
    int y = princesses.front().first;
    int x = princesses.front().second;
    visit[y][x] = 1;
    connectCount++;
    DFS(y,x);
    
    if(connectCount >= 7)   return true;
    return false;
}

void DFS(int y, int x){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(!(nx>=0 && nx<5 && ny>=0 && ny<5))   continue;
        if(!selected[ny][nx])   continue;
        if(visit[ny][nx])       continue;
        
        visit[ny][nx] = 1;
        connectCount++;
        DFS(ny, nx);
    }
}

bool isSomMoreThanFour(){
    somCount = 0;
    for(int i=0; i<princesses.size(); i++){
        int y = princesses[i].first;
        int x = princesses[i].second;
        
        if(map[y][x] == 'S')    somCount++;
    }
           
    if(somCount >= 4){
        return true;
    }
    return false;
}

