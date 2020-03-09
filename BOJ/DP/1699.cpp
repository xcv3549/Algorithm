#include <iostream>

using namespace std;

int main()
{
	int N,i,j;
	int DP[100001] = {0,};
	
	cin >> N;
	
	for(i=1; i<=N; i++)
	{
		for(j=1; j*j<=i; j++)
		{
			if(DP[i] > DP[i-j*j]+1 || DP[i] == 0)
				DP[i] = DP[i-j*j] + 1;
		}
	}
	
	cout << DP[N] << endl;
	
}
