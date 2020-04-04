#include <iostream>
#include <cstring>

using namespace std;

int Map[100][100];
int checked[101];

int Trace(int N);
pair<int,int> Repeated(int N);

int main()
{
	int N,T,i,j,k,t=0;
	
	scanf("%d",&T);
	
	while(t<T)
	{
		t++;
		
		scanf("%d",&N);
		
		for(i=0; i<N; i++)
			for(j=0; j<N; j++)
				scanf("%d",&Map[i][j]);
		
		k = Trace(N);
		
		pair<int,int> cnt = Repeated(N);
		
		printf("Case #%d: %d %d %d\n",t,k,cnt.first,cnt.second);
	}
	
	return 0;
}

int Trace(int N)
{
	int i,sum=0;
	
	for(i=0; i<N; i++)
		sum += Map[i][i];
	
	return sum;
}

pair<int,int> Repeated(int N)
{
	int i,j,num;
	int r=0,c=0;
	
	for(i=0; i<N; i++)
	{
		memset(checked,0,sizeof(checked));
		
		for(j=0; j<N; j++)
		{
			num = Map[i][j];
			
			if(checked[num])
			{
				r++;
				break;
			}
			
			checked[num]++;
		}
	}
	
	for(i=0; i<N; i++)
	{
		memset(checked,0,sizeof(checked));
		
		for(j=0; j<N; j++)
		{
			num = Map[j][i];
			
			if(checked[num])
			{
				c++;
				break;
			}
			
			checked[num]++;
		}
	}
	
	return {r,c};
}
