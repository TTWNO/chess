#include <iostream>
#include <stdio.h>
#include <string>
#include "chessPieces/rook.cpp"
#include "chessPieces/knight.cpp"
#include "chessPieces/bishop.cpp"
#include "chessPieces/queen.cpp"
#include "chessPieces/king.cpp"
#include "chessPieces/pawn.cpp"

using namespace std;

class Chess
{
  int board[64] = {0,1,0,1,0,1,0,1,
                   1,0,1,0,1,0,1,0,
                   0,1,0,1,0,1,0,1,
                   1,0,1,0,1,0,1,0,
                   0,1,0,1,0,1,0,1,
                   1,0,1,0,1,0,1,0,
                   0,1,0,1,0,1,0,1,
                   1,0,1,0,1,0,1,0};
  public:
    string square(int x, string piece, string player)
    {
       if (board[x] == 1)
       {
          return "B-"+ player + piece +" ";
       }
       else
       {
          return "W-"+ player + piece +" ";
       }
    }
};

int main()
{
  Chess chs;

  Rook rb1, rb2;
  rb1.white = false;
  rb2.white = false;

  Knight kb1, kb2;
  kb1.white = false;
  kb2.white = false;

  Bishop bb1, bb2;
  bb1.white = false;
  bb2.white = false;

  Queen Qb;
  Qb.white = false;

  King Kb;
  Kb.white = false;

  Pawn pb1,pb2,pb3,pb4,pb5,pb6,pb7,pb8;
  pb1.white = false;
  pb2.white = false;
  pb3.white = false;
  pb4.white = false;
  pb5.white = false;
  pb6.white = false;
  pb7.white = false;
  pb8.white = false;

  Rook rw1, rw2;
  rw1.white = true;
  rw2.white = true;

  Knight kw1, kw2;
  kw1.white = true;
  kw2.white = true;

  Bishop bw1, bw2;
  bw1.white = true;
  bw2.white = true;

  Queen Qw;
  Qw.white = true;

  King Kw;
  Kw.white = true;

  Pawn pw1,pw2,pw3,pw4,pw5,pw6,pw7,pw8;
  pw1.white = true;
  pw2.white = true;
  pw3.white = true;
  pw4.white = true;
  pw5.white = true;
  pw6.white = true;
  pw7.white = true;
  pw8.white = true;

  for (int i = 0; i < 8; ++i)
  {
    for (int j = 0; j < 8; ++j)
    {
      int sqNum = (8 * i) + j;

      if      (sqNum == 0)  { cout << chs.square(sqNum, rb1.player(), rb1.piece()); }
      else if (sqNum == 1)  { cout << chs.square(sqNum, kb1.player(), kb1.piece()); }
      else if (sqNum == 2)  { cout << chs.square(sqNum, bb1.player(), bb1.piece()); }
      else if (sqNum == 3)  { cout << chs.square(sqNum, Qb.player() , Qb.piece());  }
      else if (sqNum == 4)  { cout << chs.square(sqNum, Kb.player() , Kb.piece());  }
      else if (sqNum == 5)  { cout << chs.square(sqNum, bb2.player(), bb2.piece()); }
      else if (sqNum == 6)  { cout << chs.square(sqNum, kb2.player(), kb2.piece()); }
      else if (sqNum == 7)  { cout << chs.square(sqNum, rb2.player(), rb2.piece()); }
      else if (sqNum == 8)  { cout << chs.square(sqNum, pb1.player(), pb1.piece()); }
      else if (sqNum == 9)  { cout << chs.square(sqNum, pb2.player(), pb2.piece()); }
      else if (sqNum == 10) { cout << chs.square(sqNum, pb3.player(), pb3.piece()); }
      else if (sqNum == 11) { cout << chs.square(sqNum, pb4.player(), pb4.piece()); }
      else if (sqNum == 12) { cout << chs.square(sqNum, pb5.player(), pb5.piece()); }
      else if (sqNum == 13) { cout << chs.square(sqNum, pb6.player(), pb6.piece()); }
      else if (sqNum == 14) { cout << chs.square(sqNum, pb7.player(), pb7.piece()); }
      else if (sqNum == 15) { cout << chs.square(sqNum, pb8.player(), pb8.piece()); }
      else if (sqNum == 63) { cout << chs.square(sqNum, rw1.player(), rw1.piece()); }
      else if (sqNum == 62) { cout << chs.square(sqNum, kw1.player(), kw1.piece()); }
      else if (sqNum == 61) { cout << chs.square(sqNum, bw1.player(), bw1.piece()); }
      else if (sqNum == 59) { cout << chs.square(sqNum, Qw.player() , Qw.piece());  }
      else if (sqNum == 60) { cout << chs.square(sqNum, Kw.player() , Kw.piece());  }
      else if (sqNum == 58) { cout << chs.square(sqNum, bw2.player(), bw2.piece()); }
      else if (sqNum == 57) { cout << chs.square(sqNum, kw2.player(), kw2.piece()); }
      else if (sqNum == 56) { cout << chs.square(sqNum, rw2.player(), rw2.piece()); }
      else if (sqNum == 55) { cout << chs.square(sqNum, pw1.player(), pw1.piece()); }
      else if (sqNum == 54) { cout << chs.square(sqNum, pw2.player(), pw2.piece()); }
      else if (sqNum == 53) { cout << chs.square(sqNum, pw3.player(), pw3.piece()); }
      else if (sqNum == 52) { cout << chs.square(sqNum, pw4.player(), pw4.piece()); }
      else if (sqNum == 51) { cout << chs.square(sqNum, pw5.player(), pw5.piece()); }
      else if (sqNum == 50) { cout << chs.square(sqNum, pw6.player(), pw6.piece()); }
      else if (sqNum == 49) { cout << chs.square(sqNum, pw7.player(), pw7.piece()); }
      else if (sqNum == 48) { cout << chs.square(sqNum, pw8.player(), pw8.piece()); }
      else { cout << chs.square(sqNum, " ", " "); }
    }
    cout << endl;
  }

  return 0;
}
