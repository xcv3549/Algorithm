#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Map[26][26] = {0,};
int Cache[26][26] = {0,};
static int dx[4] = {0,1,0,-1};
static int dy[4] = {-1,0,1,0};

int N;

int Numbering_Complex(int row, int col);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i,j,count;
	string tmp;
	vector<int> Complex_num;
	
	cin >> N;
	
	for(i=1; i<=N; i++)
	{
		cin >> tmp;
		
		for(j=0; j<N; j++)
			Map[i][j+1] = tmp[j] - '0';
	}
	
	for(i=1; i<=N; i++)
	{
		for(j=1; j<=N; j++)
		{
			count = Numbering_Complex(i,j);
			if(count != 0)	Complex_num.push_back(count);
		}	
	}
	
	cout << Complex_num.size() << endl;
	
	sort(Complex_num.begin() , Complex_num.end());
	
	for(i=0; i<Complex_num.size(); i++)
		cout << Complex_num[i] << endl;
}

int Numbering_Complex(int row, int col)
{
	if(row <= 0 || col <= 0 || row > N || col > N )	return 0;
	
	if(Cache[row][col] != 0)	return 0;
	
	else
	{
		Cache[row][col] = 1;
		
		if(!Map[row][col])	return 0;
		
		else
		{			
			int House_count = 0;
			
			for(int k=0; k<4; k++)
				House_count += Numbering_Complex(row+dx[k] , col+dy[k]);
			
			return House_count+1;
		}
	}
}