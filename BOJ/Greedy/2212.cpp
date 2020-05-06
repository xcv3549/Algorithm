#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int Spos[10001];
priority_queue<int> hp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,K,i,sum;
	
	cin >> N >> K;
	
	for(i=0; i<N; i++)
		cin >> Spos[i];
	
	sort(Spos, Spos+N);
	
	for(i=1; i<N; i++)
		hp.push(Spos[i] - Spos[i-1]);
	
	sum = Spos[N-1] - Spos[0];
	
	K--;
	
	while(!hp.empty() and K--)
	{
		int cur = hp.top(); hp.pop();
		sum -= cur;
	}
	
	cout << sum << endl;
}
