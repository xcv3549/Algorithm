def solution(word):
    word_num = {'A':0,'E':1,'I':2,'O':3,'U':4}
    step = [0]
    MAX_LENGTH = 5
    
    for digit in range(0,5):
        step.insert(0, step[0] + (MAX_LENGTH ** digit))
    step.pop()
    
    answer = 0 
    for idx,w in enumerate(word):
        answer += word_num[w] * step[idx] + 1
        
    return answer