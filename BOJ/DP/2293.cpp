
#include <iostream>
#include <vector>

using namespace std;

vector<short> Coin;
vector<vector <short>> DP;

int Case_Count(int coin_num , int sum);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k,i;

    cin >> n >> k;

    Coin.assign(n+1,0);
    DP.assign(n+1,vector<short>(k+1,0));

    for(i=1; i<=n; i++)
        cin >> Coin[i];

    cout << Case_Count(n,k) << endl;
}

int Case_Count(int coin_num , int sum)
{
    if(coin_num == 0)   return 0;

    if(!DP[coin_num][sum])
    {
        if(coin_num == 1)
        {
            DP[coin_num][sum] = (sum % Coin[coin_num]) == 0 ? 1 : 0;
            return DP[coin_num][sum];
        }

        else
        {
            int coin_cnt = 0;
            int value = Coin[coin_num] * coin_cnt;

            while(value <= sum)
            {
                DP[coin_num][sum] += Case_Count(coin_num-1,sum - value);

                coin_cnt++;
                value = Coin[coin_num] * coin_cnt;
            }

            return DP[coin_num][sum];
        }
    }

    return DP[coin_num][sum];
}
