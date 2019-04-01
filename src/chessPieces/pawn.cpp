class Pawn
{
  public:
    double points = 1;
    bool status;
    bool white = true;
    static std::string piece() { return "P"; }
    std::string player()
    {
       if (white == true) { return "w"; }
       else { return "b"; }
    }
};

