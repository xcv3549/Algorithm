def solution(enter, leave):
    room = set()
    answer = [0] * len(enter)
    
    for l in leave:
        while l not in room:
            room.add(enter.pop(0))
        room.remove(l)
        
        for p in room:
            answer[p-1] += 1
        answer[l-1] += len(room)

    return answer