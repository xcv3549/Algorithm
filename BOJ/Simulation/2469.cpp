#include <iostream>

using namespace std;

void climbLadder(int first, int step, char* data, char* _result);
bool isPossible(char* before, char* after);

int n,k;
char ladder[1000][27];

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    char depart[27];
    char arrive[27];
    char before[27];
    char after[27];
    
    cin >> n >> k;
    cin >> arrive;
    for(int i=0; i<k; i++){
        cin >> ladder[i];
    }
    
    for(int i=0; i<n; i++){
        depart[i] = char(i+65);
    }
    
    //get Before
    climbLadder(0,1,depart, before);
    
    //get After
    climbLadder(k-1,-1,arrive, after);
    
    //check possiblity to make ladder
    bool check = isPossible(before, after);
    
    if(check){
        char ans[27];
        for(int i=0; i<n-1; i++){
            if((before[i] == after[i] or before[i+1] == after[i+1]) or (i>0 and ans[i-1] == '-')){
                ans[i] = '*';
            }
            
            else{
                ans[i] = '-';
            }
        }
        
        for(int i=0; i<n-1; i++){
            cout << ans[i];
        }
        cout << "\n";
    }
    else{
        for(int i=0; i<n-1; i++){
            cout << 'x';
        }
        cout << "\n";
    }
    
    return 0;
}

void climbLadder(int first, int step, char* data, char* _result){
    int floor = first;
    bool questionMarkFlag = false;
    char result[2][27];
    int index = (floor) % 2;
    int nextIndex = (floor + 1) % 2;
    
    for(int i=0; i<n; i++){
        result[index][i] = data[i];
    }
    
    while(!questionMarkFlag){
        for(int j=0; j<n; j++){
            int dest;
            if(ladder[floor][j] == '?'){
                questionMarkFlag = true;
                break;
            }
            else if(ladder[floor][j] == '-')
                dest = j + 1;
            else if(j-1 >= 0 && ladder[floor][j-1] == '-')
                dest = j - 1;
            else
                dest = j;
            
            result[nextIndex][dest] = result[index][j];
        }
        
        floor += step;
        index = (floor) % 2;
        nextIndex = (floor + 1) % 2;
    }
    
    for(int i=0; i<n; i++){
        _result[i] = result[nextIndex][i];
    }

    return;
}

bool isPossible(char* before, char* after){
    int count = 0;
    
    for(int i=0; i<n; i++){
        for(int step=-1; step<=1; step++){
            int idx = i + step;
            if(idx>=0 and idx<n){
                if(before[i] == after[idx]){
                    count++;
                    break;
                }
            }
        }
    }
    
    if(count == n)  return true;
    return false;
}
