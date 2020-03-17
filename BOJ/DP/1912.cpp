#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,i,tmp,max;
	int Seq[100000];
	
	cin >> N;
	
	for(i=0; i<N; i++)
		cin >> Seq[i];
	
	max = Seq[0];
	
	for(i=1; i<N; i++)
	{
		tmp = Seq[i] + Seq[i-1];
		if(tmp > Seq[i])	Seq[i] = tmp;
		if(Seq[i] > max)	max = Seq[i];
	}
	
	cout << max << endl;
}
