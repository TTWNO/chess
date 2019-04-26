from position import position

class board():
    def __init__(self, PiecePositions):
        self.piecePositions = PiecePositions

    def positions(self):
        lst = []
        i = 0
        while (i < 8):
            j = 0
            while (j < 8):
                lst.append(position(j, i))
                j = j + 1
            i = i + 1
        return lst

    def printBoard(self):
        print("           [0] [1] [2] [3] [4] [5] [6] [7] ")
        print("           ------------------------------- ")
        i = 0
        while (i < 64):
            if (self.positions()[i].x == 0):
                print("      ["+ str(self.positions()[i].y) +"] "),
            if ((self.piecePositions["B_Rk01"].x == self.positions()[i].x) and
                (self.piecePositions["B_Rk01"].y == self.positions()[i].y)):
                print("bR1"),
            elif ((self.piecePositions["W_Rk01"].x == self.positions()[i].x) and
                (self.piecePositions["W_Rk01"].y == self.positions()[i].y)):
                print("wR1"),
            elif ((self.piecePositions["B_Kt01"].x == self.positions()[i].x) and
                (self.piecePositions["B_Kt01"].y == self.positions()[i].y)):
                print("bN1"),
            elif ((self.piecePositions["W_Kt01"].x == self.positions()[i].x) and
                (self.piecePositions["W_Kt01"].y == self.positions()[i].y)):
                print("wN1"),
            elif ((self.piecePositions["B_Bp01"].x == self.positions()[i].x) and
                (self.piecePositions["B_Bp01"].y == self.positions()[i].y)):
                print("bB1"),
            elif ((self.piecePositions["W_Bp01"].x == self.positions()[i].x) and
                (self.piecePositions["W_Bp01"].y == self.positions()[i].y)):
                print("wB1"),
            elif ((self.piecePositions["B_Qn01"].x == self.positions()[i].x) and
                (self.piecePositions["B_Qn01"].y == self.positions()[i].y)):
                print("bQN"),
            elif ((self.piecePositions["W_Qn01"].x == self.positions()[i].x) and
                (self.piecePositions["W_Qn01"].y == self.positions()[i].y)):
                print("wQN"),
            elif ((self.piecePositions["B_Kg01"].x == self.positions()[i].x) and
                (self.piecePositions["B_Kg01"].y == self.positions()[i].y)):
                print("bKG"),
            elif ((self.piecePositions["W_Kg01"].x == self.positions()[i].x) and
                (self.piecePositions["W_Kg01"].y == self.positions()[i].y)):
                print("wKG"),
            elif ((self.piecePositions["B_Bp02"].x == self.positions()[i].x) and
                (self.piecePositions["B_Bp02"].y == self.positions()[i].y)):
                print("bB2"),
            elif ((self.piecePositions["W_Bp02"].x == self.positions()[i].x) and
                (self.piecePositions["W_Bp02"].y == self.positions()[i].y)):
                print("wB2"),
            elif ((self.piecePositions["B_Kt02"].x == self.positions()[i].x) and
                (self.piecePositions["B_Kt02"].y == self.positions()[i].y)):
                print("bN2"),
            elif ((self.piecePositions["W_Kt02"].x == self.positions()[i].x) and
                (self.piecePositions["W_Kt02"].y == self.positions()[i].y)):
                print("wK2"),
            elif ((self.piecePositions["B_Rk02"].x == self.positions()[i].x) and
                (self.piecePositions["B_Rk02"].y == self.positions()[i].y)):
                print("bR2"),
            elif ((self.piecePositions["W_Rk02"].x == self.positions()[i].x) and
                (self.piecePositions["W_Rk02"].y == self.positions()[i].y)):
                print("wR2"),
            elif ((self.piecePositions["B_Pn01"].x == self.positions()[i].x) and
                (self.piecePositions["B_Pn01"].y == self.positions()[i].y)):
                print("bP1"),
            elif ((self.piecePositions["B_Pn02"].x == self.positions()[i].x) and
                (self.piecePositions["B_Pn02"].y == self.positions()[i].y)):
                print("bP2"),
            elif ((self.piecePositions["B_Pn03"].x == self.positions()[i].x) and
                (self.piecePositions["B_Pn03"].y == self.positions()[i].y)):
                print("bP3"),
            elif ((self.piecePositions["B_Pn04"].x == self.positions()[i].x) and
                (self.piecePositions["B_Pn04"].y == self.positions()[i].y)):
                print("bP4"),
            elif ((self.piecePositions["B_Pn05"].x == self.positions()[i].x) and
                (self.piecePositions["B_Pn05"].y == self.positions()[i].y)):
                print("bP5"),
            elif ((self.piecePositions["B_Pn06"].x == self.positions()[i].x) and
                (self.piecePositions["B_Pn06"].y == self.positions()[i].y)):
                print("bP6"),
            elif ((self.piecePositions["B_Pn07"].x == self.positions()[i].x) and
                (self.piecePositions["B_Pn07"].y == self.positions()[i].y)):
                print("bP7"),
            elif ((self.piecePositions["B_Pn08"].x == self.positions()[i].x) and
                (self.piecePositions["B_Pn08"].y == self.positions()[i].y)):
                print("bP8"),
            elif ((self.piecePositions["W_Pn01"].x == self.positions()[i].x) and
                (self.piecePositions["W_Pn01"].y == self.positions()[i].y)):
                print("wP1"),
            elif ((self.piecePositions["W_Pn02"].x == self.positions()[i].x) and
                (self.piecePositions["W_Pn02"].y == self.positions()[i].y)):
                print("wP2"),
            elif ((self.piecePositions["W_Pn03"].x == self.positions()[i].x) and
                (self.piecePositions["W_Pn03"].y == self.positions()[i].y)):
                print("wP3"),
            elif ((self.piecePositions["W_Pn04"].x == self.positions()[i].x) and
                (self.piecePositions["W_Pn04"].y == self.positions()[i].y)):
                print("wP4"),
            elif ((self.piecePositions["W_Pn05"].x == self.positions()[i].x) and
                (self.piecePositions["W_Pn05"].y == self.positions()[i].y)):
                print("wP5"),
            elif ((self.piecePositions["W_Pn06"].x == self.positions()[i].x) and
                (self.piecePositions["W_Pn06"].y == self.positions()[i].y)):
                print("wP6"),
            elif ((self.piecePositions["W_Pn07"].x == self.positions()[i].x) and
                (self.piecePositions["W_Pn07"].y == self.positions()[i].y)):
                print("wP7"),
            elif ((self.piecePositions["W_Pn08"].x == self.positions()[i].x) and
                (self.piecePositions["W_Pn08"].y == self.positions()[i].y)):
                print("wP8"),
            else:
                if (self.positions()[i].y % 2 == 0):
                    if (self.positions()[i].x % 2 == 0):
                        print("   "),
                    else:
                        print("|||"),
                else:
                    if (self.positions()[i].x % 2 == 0):
                        print("|||"),
                    else:
                        print("   "),
            if (board(["hello", "world"]).positions()[i].x == 7):
                print(" ["+ str(self.positions()[i].y) +"]\n")
            i = i + 1
        print("           ------------------------------- ")
        print("           [0] [1] [2] [3] [4] [5] [6] [7] ")
        return ""


