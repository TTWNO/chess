class Queen
{
  public:
    double points = 9;
    bool status;
    bool white = true;
    static std::string piece() { return "Q"; }
    std::string player()
    {
       if (white == true) { return "w"; }
       else { return "b"; }
    }
};

