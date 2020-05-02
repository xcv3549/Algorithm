#include <iostream>
#include <queue>

using namespace std;
using PII = pair<int,int>;

const int Apple = 1;
const int Body = 2;
const int Left = 3;
const int Right = 1;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int Map[100][100];
int N;
queue<PII> Change_Dir;
//L = left , D = Right

int solve();
bool IsSafe(int x,int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int K,L,X,i,x,y,d;
	char C;
	cin >> N >> K;
	
	for(i=0; i<K; i++)
	{
		cin >> y >> x;
		Map[y-1][x-1] = Apple;
	}
	
	cin >> L;
	
	for(i=0; i<L; i++)
	{
		cin >> X >> C;
		d = (C == 'L' ? Left : Right);
		
		Change_Dir.push({X,d});
	}
	
	cout << solve() << endl;
}

int solve()
{
	// initialize
	queue<PII> Snake;
	int x = 0 , y = 0;
	int sec = 0 , dir = 1;
	int bx,by;
	
	Snake.push({0,0});
	Map[0][0] = Body;
	
	while(true)
	{
		//Move
		x += dx[dir];
		y += dy[dir];
		Snake.push({x,y});
		
		//Check Next Map
		if(!IsSafe(x,y) || Map[y][x] == Body)
			return sec + 1;
		
		else if(Map[y][x] == Apple)
			Map[y][x] = Body;
			
		
		else					
		{
			Map[y][x] = Body;
			
			bx = Snake.front().first;
			by = Snake.front().second;
			Snake.pop();
			Map[by][bx] = 0;
		}
		
		sec++;
		
		//Check Direction
		if(Change_Dir.front().first == sec)
		{
			dir = (dir + Change_Dir.front().second) % 4;
			Change_Dir.pop();
		}

	}
}

bool IsSafe(int x,int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}