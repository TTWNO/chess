class Rook
{
  public:
    double points = 5;
    bool status;
    bool white = true;
    static std::string piece() { return "R"; }
    std::string player()
    {
       if (white == true) { return "w"; }
       else { return "b"; }
    }
};

