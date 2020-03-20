#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M,N;
int Visit[100][100]={0,};
int Square[4][100]={0,};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void Square_visit(int x1, int y1, int x2, int y2);
int Searching(int x, int y);
bool IsSafe(int x, int y);
	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int K,i,j;
	int x1,x2,y1,y2;
	vector<int> Area;
	
	cin >> M >> N >> K;
	
	for(i=0; i<K; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		Square_visit(x1,y1,x2,y2);
	}
	
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)
			if(!Visit[i][j])	
				Area.push_back(Searching(j,i));
			
	sort(Area.begin(), Area.end());
	
	cout << Area.size() << endl;
	
	for(auto i : Area)	cout << i << " ";
	
}

bool IsSafe(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < M;
}

void Square_visit(int x1 , int y1 , int x2 , int y2)
{
	for(int i=y1; i<y2; i++)
		for(int j=x1; j<x2; j++)
			Visit[i][j] = 1;
}

int Searching(int x, int y)
{
	if(IsSafe(x,y) && !Visit[y][x])
	{
		int i,area = 1;
		Visit[y][x] = 1;
		
		for(i=0; i<4; i++)
			area += Searching(x+dx[i] , y+dy[i]);
		
		return area;
	}
	
	return 0;
}