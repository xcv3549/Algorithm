#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M,K,i,j,x,y,sum;
	int Array[301][301] = {0,};
	int DP[301][301];
	
	cin >> N >> M;
	
	for(i=1; i<=N; i++)
	{
		for(j=1; j<=M; j++)
		{
			cin >> Array[i][j];
			DP[i][j] = DP[i][j-1] + Array[i][j];
		}
	}
	
	cin >> K;
	
	while(K--)
	{
		sum = 0;
		
		cin >> i >> j >> x >> y;
		
		for(i=i; i<=x; i++)
			sum += DP[i][y] - DP[i][j-1];
			
		cout << sum << endl;
	}
	
}
