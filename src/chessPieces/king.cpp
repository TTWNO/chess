class King
{
  public:
    double points = 0;
    bool status;
    bool white = true;
    static std::string piece() { return "K"; }
    std::string player()
    {
       if (white == true) { return "w"; }
       else { return "b"; }
    }
};

