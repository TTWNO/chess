import math
from piece import piece
from position import position
from board import board

print("    +-------------------------------------------+")
print("    | WELCOME TO CHESS                          |")
print("    +-------------------------------------------+")
print("    Developer: Justin N. Pilon")
print("")

# Initial positions of all the pieces
P = [[0,0],[1,0],[2,0],[3,0],[4,0],[5,0],[6,0],[7,0],
     [0,1],[1,1],[2,1],[3,1],[4,1],[5,1],[6,1],[7,1],
     [0,6],[1,6],[2,6],[3,6],[4,6],[5,6],[6,6],[7,6],
     [0,7],[1,7],[2,7],[3,7],[4,7],[5,7],[6,7],[7,7]]

Wk = -2
Wb = -2
j = 0
while ((Wk or Bk) != -1):

    wR01 = piece("W_Rk01",position(P[24][0],P[24][1]))
    bR01 = piece("B_Rk01",position(P[0][0],P[0][1]))
    wN01 = piece("W_Kt01",position(P[25][0],P[25][1]))
    bN01 = piece("B_Kt01",position(P[1][0],P[1][1]))
    wB01 = piece("W_Bp01",position(P[26][0],P[26][1]))
    bB01 = piece("B_Bp01",position(P[2][0],P[2][1]))
    wQ01 = piece("W_Qn01",position(P[27][0],P[27][1]))
    bQ01 = piece("B_Qn01",position(P[3][0],P[3][1]))
    wK01 = piece("W_Kg01",position(P[28][0],P[28][1]))
    bK01 = piece("B_Kg01",position(P[4][0],P[4][1]))
    wB02 = piece("W_Bp02",position(P[29][0],P[29][1]))
    bB02 = piece("B_Bp02",position(P[5][0],P[5][1]))
    wN02 = piece("W_Kt02",position(P[30][0],P[30][1]))
    bN02 = piece("B_Kt02",position(P[6][0],P[6][1]))
    wR02 = piece("W_Rk02",position(P[31][0],P[31][1]))
    bR02 = piece("B_Rk02",position(P[7][0],P[7][1]))

    bP01 = piece("B_Pn01",position(P[8][0],P[8][1]))
    bP02 = piece("B_Pn02",position(P[9][0],P[9][1]))
    bP03 = piece("B_Pn03",position(P[10][0],P[10][1]))
    bP04 = piece("B_Pn04",position(P[11][0],P[11][1]))
    bP05 = piece("B_Pn05",position(P[12][0],P[12][1]))
    bP06 = piece("B_Pn06",position(P[13][0],P[13][1]))
    bP07 = piece("B_Pn07",position(P[14][0],P[14][1]))
    bP08 = piece("B_Pn08",position(P[15][0],P[15][1]))

    wP01 = piece("W_Pn01",position(P[16][0],P[16][1]))
    wP02 = piece("W_Pn02",position(P[17][0],P[17][1]))
    wP03 = piece("W_Pn03",position(P[18][0],P[18][1]))
    wP04 = piece("W_Pn04",position(P[19][0],P[19][1]))
    wP05 = piece("W_Pn05",position(P[20][0],P[20][1]))
    wP06 = piece("W_Pn06",position(P[21][0],P[21][1]))
    wP07 = piece("W_Pn07",position(P[22][0],P[22][1]))
    wP08 = piece("W_Pn08",position(P[23][0],P[23][1]))
    
    board({bR01.name : bR01.position,
           wR01.name : wR01.position,
           bN01.name : bN01.position,
           wN01.name : wN01.position,
           bB01.name : bB01.position,
           wB01.name : wB01.position,
           bQ01.name : bQ01.position,
           wQ01.name : wQ01.position,
           bK01.name : bK01.position,
           wK01.name : wK01.position,
           bB02.name : bB02.position,
           wB02.name : wB02.position,
           bN02.name : bN02.position,
           wN02.name : wN02.position,
           bR02.name : bR02.position,
           wR02.name : wR02.position,
           bP01.name : bP01.position,
           bP02.name : bP02.position,
           bP03.name : bP03.position,
           bP04.name : bP04.position,
           bP05.name : bP05.position,
           bP06.name : bP06.position,
           bP07.name : bP07.position,
           bP08.name : bP08.position,
           wP01.name : wP01.position,
           wP02.name : wP02.position,
           wP03.name : wP03.position,
           wP04.name : wP04.position,
           wP05.name : wP05.position,
           wP06.name : wP06.position,
           wP07.name : wP07.position,
           wP08.name : wP08.position}).printBoard()
    print("")
    if (j % 2 == 0):
        print("    +-------------------------------------------+")
        print("    | WHITE TO MOVE                             |")
        print("    +----------+----------+----------+----------+")
        print("    | 24  wR1  | 25  wN1  | 26  wB1  | 27  wQN  |")
        print("    +----------+----------+----------+----------+")
        print("    | 28  wKG  | 29  wB2  | 30  wN2  | 31  wR2  |")
        print("    +----------+----------+----------+----------+")
        print("    | 16  wP1  | 17  wP2  | 18  wP3  | 19  wP4  |")
        print("    +----------+----------+----------+----------+")
        print("    | 20  wP5  | 21  wP6  | 22  wP7  | 23  wP8  |")
        print("    +----------+----------+----------+----------+")
        print("")
        
        print("-1 to quit")
        Wk = int(raw_input("Choose a piece to move: "))
        if (Wk != -1):
            Wx = int(raw_input("x = "))
            Wy = int(raw_input("y = "))
            P[Wk][0] = Wx
            P[Wk][1] = Wy
            j = j + 1
        else:
            break
    else:
        print("    +-------------------------------------------+")
        print("    | BLACK TO MOVE                             |")
        print("    +----------+----------+----------+----------+")
        print("    |  0  bR1  |  1  bN1  |  2  bB1  |  3  bQN  |")
        print("    +----------+----------+----------+----------+")
        print("    |  4  bKG  |  5  bB2  |  6  bN2  |  7  bR2  |")
        print("    +----------+----------+----------+----------+")
        print("    |  8  bP1  |  9  bP2  | 10  bP3  | 11  bP4  |")
        print("    +----------+----------+----------+----------+")
        print("    | 12  bP5  | 13  bP6  | 14  bP7  | 15  bP8  |")
        print("    +----------+----------+----------+----------+")
        print("")

        print("-1 to quit")
        Bk = int(raw_input("Choose a piece to move: "))
        if (Bk != -1):
            Bx = int(raw_input("x = "))
            By = int(raw_input("y = "))
            P[Bk][0] = Bx
            P[Bk][1] = By
            j = j + 1
        else:
            break
