#include <iostream>

using namespace std;

int DP[12] = {1,};

int Find(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
			
	int T,n,i;
	
	cin >> T;
	
	for(i=0; i<T; i++)
	{
		cin >> n;
		cout << Find(n) << endl;
	}
	
}

int Find(int n)
{
	if(n >= 0)
	{
		if(DP[n])	return DP[n];
		else
		{
			DP[n] = Find(n-1) + Find(n-2) + Find(n-3);
			return DP[n];
		}
	}
		
	return 0;
}