#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using Activity = struct Activity{int s,e,num;};

int N;
int Schedule[1441][2];
vector<Activity> A;

char Who[2] = {'C','J'};
char str[1001];

bool Scheduling();
bool Compare(const Activity &a , const Activity &b);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T,i,s,e,t=0;
		
	cin >> T;
	
	while(t<T)
	{
		t++;
		A.clear();
		
		memset(Schedule,0,sizeof(Schedule));
		
		cin >> N;
		
		for(i=0; i<N; i++)
		{
			cin >> s >> e;
			A.push_back({s,e,i});
		}
		
		sort(A.begin(),A.end(),Compare);
		
		cout << "Case #" << t << ": ";
		
		if(Scheduling())
			for(i=0; i<N; i++)
				cout << str[i];
		
		else
			cout << "IMPOSSIBLE";
		
		cout << "\n";
	}

}
bool Scheduling()
{
	int i,j,pos,start_time,end_time;
	bool printed;
	
	Schedule[A[0].s][0] = A[0].e;
	str[A[0].num] = 'C';
	
	for(i=1; i<N; i++)
	{
		printed = false;
		start_time = A[i].s;
		end_time = A[i].e;
		
		for(j=0; j<=1; j++)
		{
			for(pos=0; pos<=end_time; pos++)
			{
				if(!Schedule[pos][j])	continue;
				
				else
				{
					if(Schedule[pos][j] > start_time)
						break;
					
					else
						pos = Schedule[pos][j] - 1;
				}
			}
			
			if(pos == (end_time+1))
			{
				Schedule[start_time][j] = end_time;
				str[A[i].num] = Who[j];
				printed = true;
			}
			
			if(printed)	break;
		}
		
		if(!printed)	return false;
	}
	
	return true;
}

bool Compare(const Activity& a, const Activity& b)
{
	return a.s < b.s;
}