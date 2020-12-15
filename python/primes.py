#!/usr/bin/env python3

import math

def primes(m):

    zoz=[]
    for n in range(2,m):
        for k in range(2,int(math.sqrt(n))+1):
            if n % k == 0:
                break
        else:
            zoz.append(n)
    return zoz

