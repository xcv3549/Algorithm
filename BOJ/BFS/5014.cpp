#include <iostream>
#include <queue>

using namespace std;

int F,S,G,U,D;
int Floor[1000001];
int dy[2];

int BFS();

int main()
{
	cin >> F >> S >> G >> dy[0] >> dy[1];
	dy[1] *= -1;
	
	if(BFS() == -1)
		cout << "use the stairs" << endl;
	
	else
		cout << Floor[G]-1 << endl;
}

int BFS()
{
	int f,ny;
	queue<int> q;
	q.push(S);
	Floor[S] = 1;
	
	while(!q.empty())
	{
		f = q.front();
		q.pop();
		
		if(f == G)	return Floor[G]-1;
		
		for(int i : dy)
		{
			ny = f + i;
			
			if(ny < 1 || ny > F)	continue;
			if(Floor[ny] != 0)		continue;
			
			q.push(ny);
			Floor[ny] = Floor[f] + 1;
		}
	}
	return -1;
}