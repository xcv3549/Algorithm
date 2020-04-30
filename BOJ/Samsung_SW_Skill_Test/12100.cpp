#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int cnt , int Map[][20]);

int N;
int Map[20][20];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int i,j,ret;
		
	cin >> N;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			cin >> Map[i][j];
	
	cout << solve(0,Map) << endl;
	
}

int solve(int cnt , int Map[][20])
{
	int i,j,k,dir,val,ret=0;
	int Array[20][20] = {0,};
		//  2
		// 0 1 
		//  3
	
	if(cnt == 5)
	{
		for(i=0; i<N; i++)
			for(j=0; j<N; j++)
				ret = max(ret , Map[i][j]);
		
		return ret;
	}
	
	for(dir=0; dir<4; dir++)
	{
		for(i=0; i<N; i++)
		{
			vector<int> line;
			for(j=0; j<N; j++)
			{
				val = (dir<2 ? Map[i][j] : Map[j][i]);
				if(val != 0)	line.push_back(val);
			}
			
			if(dir == 1 || dir == 3)
				reverse(line.begin(),line.end());
			
			vector<int> mix_line;
			for(k=0; k<line.size(); k++)
			{
				if(k+1 < line.size() && line[k+1] == line[k])
				{
					mix_line.push_back(line[k]*2);
					k++;
				}
				
				else
					mix_line.push_back(line[k]);
			}
			
			for(k=mix_line.size(); k<N; k++)
				mix_line.push_back(0);
			
			if(dir == 1 || dir == 3)
				reverse(mix_line.begin(),mix_line.end());
			
			for(j=0; j<N; j++)
				(dir<2 ? Array[i][j] : Array[j][i]) = mix_line[j];
		}
		
		ret = max(ret , solve(cnt+1 , Array));
	}
	
	return ret;
}