using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long total_price = (long long)(count * (count+1) / 2) * price;
    
    if(total_price > money)
        answer = total_price - money;
    
    return answer;
}
