#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using xy = struct xy{int x,y,z;};

int L,R,C;
char Map[30][30][30];
int dx[6] = {0,-1,0,1,0,0};
int dy[6] = {1,0,-1,0,0,0};
int dz[6] = {0,0,0,0,1,-1};
xy S;

int BFS();
bool IsSafe(int x, int y, int z);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int i,j,k,ans;
    
    cin >> L >> R >> C;
    
    while((L+R+C)!=0)
    {
        for(i=0; i<L; i++)
        {
            for(j=0; j<R; j++)
                for(k=0; k<C; k++)
                {
                    cin >> Map[i][j][k];
                    
                    if(Map[i][j][k] == 'S')
                        S = {k,j,i};
                }
        }
        
        ans = BFS();
        
        if(ans==-1) cout << "Trapped!" << endl;
        else        cout << "Escaped in " << ans << " minute(s)." << endl;
        
        cin >> L >> R >> C;
    }
}

int BFS()
{
    int i,nx,ny,nz;
    int visited[L][R][C];
    queue<xy> q;
    
    memset(visited,0,sizeof(visited));
    
    q.push(S);
    visited[S.z][S.y][S.x] = 1;
    
    while(!q.empty())
    {
        auto [x,y,z] = q.front();
        q.pop();
        
        for(i=0; i<6; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            nz = z + dz[i];
            
            if(!IsSafe(nx,ny,nz))   continue;
            
            if(Map[nz][ny][nx] == 'E')  return visited[z][y][x];
            
            if(!visited[nz][ny][nx] && Map[nz][ny][nx] == '.')
            {
                q.push({nx,ny,nz});
                visited[nz][ny][nx] = visited[z][y][x] + 1;
            }
        }
    }
    
    return -1;
}

bool IsSafe(int x, int y, int z)
{
    return x>=0 && y>=0 && z>=0 && x<C && y<R && z<L;
}
