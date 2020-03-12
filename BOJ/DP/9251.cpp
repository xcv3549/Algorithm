#include <iostream>
#include <string>

using namespace std;
int max(int a, int b)
{	
	return a > b ? a : b;
}

int main()
{
	int i,j;
	int DP[1001][1001]={0,};
	string str1,str2;
	
	cin >> str1 >> str2;

	for(i=1; i<=str1.size(); i++)
	{
		for(j=1; j<=str2.size(); j++)
		{
			if(str1[i-1] == str2[j-1])
				DP[i][j] = DP[i-1][j-1] + 1;
			else
				DP[i][j] = max(DP[i-1][j] , DP[i][j-1]);
		}
	}
	
	cout << DP[str1.size()][str2.size()] << endl;
}