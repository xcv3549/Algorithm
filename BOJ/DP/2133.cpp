#include <iostream>
using namespace std;

int main()
{
	int N,i,j;
	int DP[31] = {1,0,3};
	
	cin >> N;
	
	for(i=4; i<=N; i+=2)
	{
		DP[i] = DP[i-2] * 3;
		
		for(j=0; j<i-2; j+=2)
			DP[i] += DP[j]*2;
	}
	
	cout << DP[N] << endl;
}