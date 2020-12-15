#!/usr/bin/env python3
'''Dokumentácia k modulu
'''

import math
from closure import add_debug

@add_debug  #dekorator
def eratosthenes(n):
    '''Vráti zoznam všetkých prvočísel <= n
'''
    s=set(range(2,n))
    for k in range(2,int(math.sqrt(n))+1):
        if k not in s:
            continue
        for l in range(2*k,n,k):
            s.discard(l)
    return sorted(s)

#eratosthenes=closure.add_debug(eratosthenes)

