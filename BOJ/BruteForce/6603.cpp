#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> S;
vector<int> Picked_num;

int Lotto(int index , int MAX);
void Print_Lotto();

int main()
{
	
	while(1)
	{
		cin >> k;
		
		if(k == 0)	break;
		
		S.assign(k,0);

		for(int i=0; i<k; i++)
			cin >> S[i];
		
		Lotto(-1 , k-6);
		
		cout << endl;
	}
}

int Lotto(int index , int MAX)
{	
	MAX+=1;
	if(MAX > k)	return 0;
	
	for(int i=index+1; i<MAX; i++)
	{
		Picked_num.push_back(S[i]);
		
		if(Picked_num.size() == 6)	Print_Lotto();
		
		Lotto(i , MAX);
		
		Picked_num.pop_back();
	}
	
	return 0;
}

void Print_Lotto()
{
	for(int i=0; i<6; i++)	
		cout << Picked_num[i] << " ";
	
	cout << endl;
}
