#include <iostream>

using namespace std;

int main()
{
	int N,i;
	int DP[100001] = {1,3};
	
	cin >> N;
	
	for(i=2; i<=N; i++)
		DP[i] = (DP[i-1] * 2 + DP[i-2]) % 9901;
	
	cout << DP[N] << endl;
}