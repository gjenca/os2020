
class Obdlznik:

    def __init__(self,a,b):

        self.a=a
        self.b=b

    def plocha(self):
        
        return self.a*self.b

class Stvorec(Obdlznik):

    def __init__(self,x):

        self.a=x
        self.b=x


