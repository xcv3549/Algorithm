#include <string>
#include <vector>

using namespace std;

char get_grade(float score);

string solution(vector<vector<int>> scores) {
    int N = scores.size();
    string answer = "";
    
    for(int i=0; i<N; i++){
        int self_score = scores[i][i];
        int cnt = N;
        int min_cnt = 0, max_cnt = 0;
        float total = 0;
        
        for(int j=0; j<N; j++){
            
            if(scores[j][i] > self_score)   max_cnt++;
            if(scores[j][i] < self_score)   min_cnt++;
            total += scores[j][i];
        }
        
        if((min_cnt == cnt - 1) || (max_cnt == cnt - 1)) {
            total -= self_score;
            cnt--;
        }
        
        answer += get_grade(total/cnt);
    }
    
    return answer;
}

char get_grade(float score){
    char grade;
    
    if(score >= 90)         grade = 'A';
    else if(score >= 80)    grade = 'B';
    else if(score >= 70)    grade = 'C';
    else if(score >= 50)    grade = 'D';
    else                    grade = 'F';
    
    return grade;
}
