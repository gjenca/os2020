
class Vector(list):

    def __add__(self,other):

        ret=Vector()
        for c1,c2 in zip(self,other):
            ret.append(c1+c2)
        return ret

    def __repr__(self):

        zoz_repr=list.__repr__(self)
        return f'Vector({zoz_repr})'


    
