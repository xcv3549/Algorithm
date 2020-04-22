#include <iostream>
#include <vector>

using namespace std;

int fibo_arr[41] = {0,};
vector<int> fix;

int fibo(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,fix_num,i,num,ret=1;
	int pre_idx = 0;
	fibo_arr[0] = 1;
	fibo_arr[1] = 1;
	
	cin >> N >> fix_num;
	
	for(i=0; i<fix_num; i++)
	{
		cin >> num;
		fix.push_back(num);
	}
	
	for(auto idx : fix)
	{
		ret *= fibo(idx - pre_idx - 1);
		pre_idx = idx;
	}
	
	ret *= fibo(N - pre_idx);
	
	cout << ret << endl;
}

int fibo(int n)
{
	if(fibo_arr[n] == 0)
		fibo_arr[n] = fibo(n-1) + fibo(n-2);
	
	return fibo_arr[n];
}