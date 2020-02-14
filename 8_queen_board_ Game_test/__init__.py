import collections
from typing import List



def createboard():
    print("enter number of queen for the game: ")
    x=int(input())
    board=[[0 for i in range(x)] for j in range(x)]
    print("put the  queen on the board")
    for k in range(x):
       print("enter x"+str(k)+" :")
       x=int(input())
       print("enter y"+str(k)+" :")
       y=int(input())
       board[x][y]=1
    return board



def printboard(board):
    for raw in board:
        print(raw)

def checkrawattack(board):
    attack=0
    for raw in board:
        if raw.count(1)>1:
            attack=attack+(raw.count(1)-1)
    return attack

def checkcoloumattack(board):
    attack = 0
    for i in range(len(board)):
        col=[]
        for j in range(len(board)):

            queen=board[j][i]
            col.append(queen)


        if col.count(1) > 1:
            attack = attack + (col.count(1) - 1)
    return attack
def getcornercoloums(board):

    queenspositions=[]
    for m in range(len(board)):
        col=[]
        for n in range(len(board)):
            if board[m][n]==1:
                col = []
                if m==n:
                    rng=m
                else:
                    if m>n:
                        rng=m
                    else:
                        rng=n
                for i in range(len(board)-rng):
                    queen = board[m+i][n+i]
                    col.append(queen)
                print(col)

    return col


def checkcornerattacks(board,m,n):

        col = []
        if m == n:
            rng = m
        else:
            if m > n:
                rng = m
            else:
                rng = n
        for i in range(len(board) - rng):
            queen = board[m + i][n + i]
            col.append(queen)







Board=createboard()
printboard(Board)
print(checkrawattack(Board))
print(checkcoloumattack(Board))
print (checkcornerattack(Board))