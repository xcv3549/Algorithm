def solution(weights, head2head):
    boxer_table = []
    
    for i, record in enumerate(head2head):
        win = lose = win_heavy = 0
        
        for j, result in enumerate(record):
            if(result == 'L'):
                lose += 1
            if(result == 'W'):
                win += 1
                if(weights[i] < weights[j]):
                    win_heavy += 1
                    
        if win + lose == 0:
            win_rate = 0
        else:
            win_rate = win / (win + lose)
            
        boxer_table.append([-win_rate, -win_heavy, -weights[i], i+1])
        
    boxer_table.sort()
    answer = list(zip(*boxer_table))[-1]
    
    return answer