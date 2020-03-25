#include <iostream>
#include <algorithm>
#include <deque>
#include <tuple>

using namespace std;

int N;
int Test_tube[201][201];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
deque<tuple<int,int,int,int>> V_pos;

void BFS(int S);
bool IsSafe(int x, int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int K,i,j,S,X,Y;
	
	cin >> N >> K;
	
	for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
		{
			cin >> Test_tube[i][j];
			
			if(Test_tube[i][j])
				V_pos.push_back(make_tuple(Test_tube[i][j],i,j,0));
		}
	
	cin >> S >> X >> Y;
	
	if(Test_tube[X][Y])	
		cout << Test_tube[X][Y] << endl;

	else
	{
		sort(V_pos.begin(),V_pos.end());
	
		BFS(S);

		cout << Test_tube[X][Y] << endl;
	}
}

void BFS(int S)
{	
	int i,x,y,nx,ny,v,now_sec;
	
	while(!V_pos.empty())
	{
		v = get<0>(V_pos.front());
		x = get<2>(V_pos.front());
		y = get<1>(V_pos.front());
		now_sec = get<3>(V_pos.front());
		V_pos.pop_front();
		
		if(now_sec == S)	return;
		
		for(i=0; i<4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			
			if(!IsSafe(nx,ny) || Test_tube[ny][nx] != 0)	continue;
			
			Test_tube[ny][nx] = v;
			
			V_pos.push_back(make_tuple(v,ny,nx,now_sec+1));
		}
	}
}

bool IsSafe(int x, int y)
{
	return x >= 1 && y >= 1 && x <= N && y <= N;
}
