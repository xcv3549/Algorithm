#include <iostream>
#include <cstring>
#include <stack>
#include <map>
#include <utility>

using namespace std;

int board[7][13] = {0,};
int visit[7][13] = {0,};
const int mapX = 6;
const int mapY = 12;
const int VISITED = 1;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

map<char, int> colorToNum = {
    {'.',0},
    {'R',1},
    {'G',2},
    {'B',3},
    {'P',4},
    {'Y',5},
};

stack<pair<int, int>> checkBlock(int x, int y);
bool isSafe(int x, int y);
void removeBlock(stack<pair<int,int>> *checkedBlock);
void moveBlock();

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char block;
    for(int i=mapY-1; i>=0; i--){
        for(int j=0; j<mapX; j++){
            cin >> block;
            board[j][i] = colorToNum[block];
        }
    }
    
    int chain = -1;
    bool isChain;
    do{
        isChain = false;
        chain++;
        memset(visit, 0, sizeof(visit));
        
        for(int i=0; i<mapX; i++){
            for(int j=0; j<mapY; j++){
                if(board[i][j] && !visit[i][j]){
                    stack<pair<int,int>> checkedBlock = checkBlock(i, j);
                    
                    if(checkedBlock.size() >= 4){
                        isChain = true;
                        removeBlock(&checkedBlock);
                    }
                }
            }
        }
        
        moveBlock();
    }while(isChain);
    
    cout << chain << endl;
    
    return 0;
}

stack<pair<int, int>> checkBlock(int x, int y){
    stack<pair<int, int>> checkedBlock;
    checkedBlock.push(make_pair(x,y));
    
    stack<pair<int, int>> s;
    s.push(make_pair(x,y));
    visit[x][y] = VISITED;
    
    while(!s.empty()){
        int mx = s.top().first;
        int my = s.top().second;
        int mColor = board[mx][my];
        s.pop();
        
        for(int i=0; i<4; i++){
            int nx = mx + dx[i];
            int ny = my + dy[i];
            
            if(!isSafe(nx,ny) || visit[nx][ny] || board[nx][ny]!=mColor)  continue;
            
            visit[nx][ny] = VISITED;
            s.push(make_pair(nx,ny));
            checkedBlock.push(make_pair(nx,ny));
        }
    }
    
    return checkedBlock;
}

bool isSafe(int x, int y){
    return (x>=0 && x<mapX && y>=0 && y<mapY);
}

void removeBlock(stack<pair<int,int>> *checkedBlock){
    stack<pair<int,int>> s = *checkedBlock;
    while(!s.empty()){
        int mx = s.top().first;
        int my = s.top().second;
        s.pop();
        
        board[mx][my] = 0;
    }
}

void moveBlock(){
    for(int i=0; i<mapX; i++){
        int tmp[13] = {0,};
        int tmpIndex = 0;
        for(int j=0; j<mapY; j++){
            if(board[i][j]){
                tmp[tmpIndex++] = board[i][j];
            }
        }
        memcpy(board[i], tmp, sizeof(int) * 13);
    }
}

