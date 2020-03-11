#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,M,i,j;
	int DP[1001][1001] = {0,};
	int Candy[1001][1001] = {0,};
	
	cin >> N >> M;
	
	for(i=1; i<=N; i++)
	{
		for(j=1; j<=M; j++)
		{
			cin >> Candy[i][j];
			DP[i][j] = max(DP[i-1][j] , DP[i][j-1]) + Candy[i][j];
		}
	}
		
	cout << DP[N][M] << endl;
}