
def memoize(f):

    d={}

    def to_ret(x):

        if x in d:
            return d[x]
        else:
            d[x]=f(x)
            return d[x]

    return to_ret
    
@memoize
def comb(pair):

    n,k=pair
    if k==0 or n==k:
        return 1
    else:
        return comb((n-1,k-1))+comb((n-1,k))

    

