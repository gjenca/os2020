#!/usr/bin/env python3

import math

def eratosthenes(n):

    s=set(range(2,n))
    for k in range(2,int(math.sqrt(n))+1):
        if k not in s:
            continue
        for l in range(2*k,n,k):
            s.discard(l)
    return sorted(s)

print(eratosthenes(100))
