#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T,N,M,i,a;
	
	cin >> T;
		
	while(T--)
	{
		cin >> N >> M;
		
		for(i=0; i<M*2; i++)
			cin >> a;
		
		cout << N-1 << endl;
	}
}
