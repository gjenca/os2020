
class SpreadSheet(dict):

    def __getitem__(self,key):

        value_d=dict.__getitem__(self,key)
        if type(value_d)==str:
            return eval(value_d,self)
        else:
            return value_d

