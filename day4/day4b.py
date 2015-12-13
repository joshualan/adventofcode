#!/usr/bin/env python

"""day4a.py: Solution for the Day 4A puzzle.

I used Python instead of C because of easy md5 hashing
functionality.

"""

__author__      = "Alan Estrada"

import hashlib

currentNum = 0
input = "ckczppom"

while True:
    # Calculate the hash of input and currentNum 'til the first
    # 6 characters are "00000"
    hash_object = hashlib.md5(''.join([input,str(currentNum)]))
    
    if hash_object.hexdigest()[:6]  == "000000":
        print currentNum
        break

    currentNum += 1
    

