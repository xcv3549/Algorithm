#include <iostream>
#include <vector>

using namespace std;

vector<int> DP;
int Div_Count(int Size);

int main() {
    int N,M,Size;
    
    cin >> N >> M;
    
    Size = N * M;
    
    DP.assign(Size+1,0);
    DP[2] = 1 ;
    
    cout << Div_Count(Size);
    //Div_Count = N * M - 1
}

int Div_Count(int Size)
{
    if(!(DP[Size]))
    {
        if(Size%2 == 0)
        {
            DP[Size] = Div_Count(Size/2) * 2 + 1;
            return DP[Size];
        }
        
        else
        {
            DP[Size] = Div_Count(Size-1) + 1;
            return DP[Size];
        }
    }
    
    return DP[Size];
}
