import sys
input = sys.stdin.readline
from collections import deque

N, K = map(int, input().split())
conveyor = deque(list(map(int, input().split())))
boxRobot = deque([0]*N)
count = 0

# def isArrivedRobot():
#     if boxRobot[N-1]:
#         return True
#     else:
#         return False

while(True):
    count += 1

    ## Step 1 : Move Conveyor
    conveyor.rotate(1)
    boxRobot.rotate(1)
    boxRobot[-1] = 0
    # conveyor = [conveyor[-1]] + conveyor[:-1]
    # boxRobot = [0] + boxRobot[:-1]
    # if(isArrivedRobot()):
    #     boxRobot[N-1] = 0


    ## Step 2 : Move Robots
    if sum(boxRobot):
        for idx in range(N-2, -1, -1):
            if(boxRobot[idx] and boxRobot[idx+1] == 0 and conveyor[idx+1]):
                boxRobot[idx] = 0
                boxRobot[idx+1] = 1
                conveyor[idx+1] -= 1
    boxRobot[-1] = 0
    # if (isArrivedRobot()):
    #     boxRobot[N - 1] = 0


    ## Step 3 : Put Robot on the first
    if(conveyor[0]):
        boxRobot[0] = 1
        conveyor[0] -= 1

    if(conveyor.count(0) >= K):
        break

print(count)