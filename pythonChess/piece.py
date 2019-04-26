class piece():
    def __init__(self, Name, Position):
        self.name = Name
        self.position = Position

    def status(self):
        if (self.Name == "NAN"):
            return "Captured"
        else:
            return "In play"

    def points(self):
        if (self.name[1] == "R"):
            return 5
        elif (self.name[1] == "N"):
            return 3
        elif (self.name[1] == "B"):
            return 3
        elif (self.name[1] == "Q"):
            return 9
        elif (self.name[1] == "P"):
            return 1
        else:
            return 100
            
