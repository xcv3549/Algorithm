#include <iostream>
#include <queue>

using namespace std;


const int MAX = 100001;
int N,k;
int Map[MAX];
queue<pair<int,int>> Pos;

void Move(int x, int s);

int main() {
    
    int x,s;
    
    cin >> N >> k;
    
    Map[N] = 1;
    
    Pos.push(make_pair(N,0));
    
    while(!Pos.empty())
    {
        x = Pos.front().first;
        s = Pos.front().second;
        Pos.pop();

        if(x == k)
        {
            cout << s << endl;
            return 0;
        }

        Move(x-1, s+1);
        Move(x+1, s+1);
        Move(x*2, s+1);
    }
}

void Move(int x, int s)
{
    if(x < MAX && x >= 0 && !Map[x])
    {
        Map[x] = s;
        Pos.push(make_pair(x , s));
    }
}