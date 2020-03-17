#include <iostream>
#include <cstring>

using namespace std;

int N;
int Box[1000];
int cache[1001];

int Box_LIS(int num);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i,j;
	
	cin >> N;
	
	for(i=0; i<N; i++)	cin >> Box[i];
	
	memset(cache,-1,sizeof(cache));
	
	cout << Box_LIS(-1) << endl;
	
}

int Box_LIS(int num)
{
	int &Val = cache[num+1];
	
	if(Val != -1)	return Val;
	
	Val = 0;
	
	for(int next = num+1; next<N; next++)
	{
		if(num == -1 || Box[num] < Box[next])
		{
			int max = Box_LIS(next) + 1;
			if(max > Val)	Val = max;
		}
	}
	
	return Val;
}