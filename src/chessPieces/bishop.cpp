class Bishop
{
  public:
    double points = 3;
    bool status;
    bool white = true;
    static std::string piece() { return "B"; }
    std::string player()
    {
       if (white == true) { return "w"; }
       else { return "b"; }
    }
};
