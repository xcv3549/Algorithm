#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int M,N,H;
int Box[100][100][100];
const int dh[6] = {1,-1,0,0,0,0};
const int dx[6] = {0,0,1,0,-1,0};
const int dy[6] = {0,0,0,1,0,-1};
queue<tuple<int,int,int>> q;

bool IsSafe(int h , int x , int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int i,j,k;
	int h,x,y,nh,nx,ny;
	
	cin >> M >> N >> H;
	
	for(k=0; k<H; k++)
	{
    	for(i=0; i<N; i++)
    	{
    		for(j=0; j<M; j++)
    		{
    			cin >> Box[k][i][j];
    			
    			if(Box[k][i][j] == 1)
    				q.push(make_tuple(k,j,i));
    		}
    	}
	}
	
	while(!q.empty())
	{
	    h = get<0>(q.front());
		x = get<1>(q.front());
		y = get<2>(q.front());
		q.pop();
		
		for(i=0; i<6; i++)
		{
		    nh = h + dh[i];
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(IsSafe(nh,nx,ny) && Box[nh][ny][nx] == 0)
			{
				q.push(make_tuple(nh,nx,ny));
				Box[nh][ny][nx] = Box[h][y][x] + 1;
			}
		}
	}
	
	for(k=0; k<H; k++)
    	for(i=0; i<N; i++)
    		for(j=0; j<M; j++)
    			if(Box[k][i][j] == 0)
    			{
    				cout << -1 << endl;
    				return 0;
    			}
	
	cout << Box[h][y][x]-1 << endl;
}

bool IsSafe(int h , int x , int y)
{
	return h >= 0 && h < H && x >= 0 && y >= 0 && x < M && y < N;
}
