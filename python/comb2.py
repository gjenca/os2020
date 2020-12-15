
from functools import cache
    
@cache
def comb(n,k):

    if k==0 or n==k:
        return 1
    else:
        return comb(n-1,k-1)+comb(n-1,k)

    

