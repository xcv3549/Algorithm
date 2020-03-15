#include <iostream>

using namespace std;

int64_t Finding_Route(int x, int y);

int64_t cache[101][101];
int Map[101][101] = {0,};
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i,j;
	
	cin >> N;
	
	for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
		{
			cin >> Map[i][j];
			cache[i][j] = -1;
		}

	cout << Finding_Route(1,1) << endl;
}

int64_t Finding_Route(int x, int y)
{
	if(x > N || y > N)	return 0;
	if(x==N && y==N)	return 1;
	
	if(cache[x][y] != -1)	return cache[x][y];
	
	else
	{
		int move = Map[x][y];
		cache[x][y] = 0;
		
		cache[x][y] = Finding_Route(x+move,y) + Finding_Route(x,y+move);
	}
	
	return cache[x][y];
}