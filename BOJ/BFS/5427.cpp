#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 1000;

int w,h;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
char Map[MAX+1][MAX+1];
bool visited[MAX][MAX];
vector<pair<int,int>> fire;
pair<int,int> start;

bool IsSafe(int x, int y);
int BFS();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T,i,j;
	
	cin >> T;
	
	while(T--)
	{
		fire.clear();
		memset(visited,false,sizeof(visited));
		
		cin >> w >> h;
		
		for(i=0; i<h; i++)
		{
			cin >> Map[i];
			for(j=0; j<w; j++)
			{
				if(Map[i][j] == '@')
					start = make_pair(j,i);
                
				else if(Map[i][j] == '*')
					fire.push_back(make_pair(j,i));
			}
		}
		
		int ans = BFS();
		
		if(ans == -1)	cout << "IMPOSSIBLE\n";
		else			cout << ans << "\n";
	}
}

bool IsSafe(int x, int y)
{
	return x >= 0 && y >= 0 && x < w && y < h;
}

int BFS()
{
	int i,j,x,y,nx,ny,psize,fsize,sec=0;
	queue<pair<int,int>> p;
	queue<pair<int,int>> f;
	
	p.push(start);
	
	for(i=0; i<fire.size(); i++)
		f.push(fire[i]);
	
	while(!p.empty())
	{
		fsize = f.size();
		
		for(i=0; i<fsize; i++)
		{
			x = f.front().first;
			y = f.front().second;
			f.pop();
			
			for(j=0; j<4; j++)
			{
				nx = x + dx[j];
				ny = y + dy[j];
				
				if(!IsSafe(nx,ny))	continue;
				if(Map[ny][nx] == '.')
				{
					Map[ny][nx] = '*';
					f.push(make_pair(nx,ny));
				}
			}
		}
		
        psize = p.size();
        
		for(i=0; i<psize; i++)
		{
			x = p.front().first;
			y = p.front().second;
			p.pop();
            
			for(j=0; j<4; j++)
			{
				nx = x + dx[j];
				ny = y + dy[j];
				
				if(!IsSafe(nx,ny))	return sec+1;
				if(!visited[ny][nx] && Map[ny][nx] != '*' && Map[ny][nx] != '#')
				{
					visited[ny][nx] = true;
					p.push(make_pair(nx,ny));
				}
			}
		}
		
		sec++;
	}
	
	return -1;
}