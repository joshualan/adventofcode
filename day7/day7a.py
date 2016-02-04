#!/usr/bin/env python

"""day7a.py: Solution for the Day 7a puzzle.

That's enough practice for C++, time for Python.

"""

__author__      = "Alan Estrada"


import sys
from collections import defaultdict

# All these are short because 16 bits = 2 bytes = short...
# My C is showing...
def shortNOT(val):
    return ~(val & 65`535)

def shortLSHIFT(val, shift):
    return (val << shift) & 65535

def shortRSHIFT(val, shift):
    return (val >> shift) & 65535

def shortAND(val1, val2):
    return (val1 & 65535) & (val2 & 65535)

def shortOR(val1, val2):
    return (val1 & 65535) & (val2 & 65535)


if len(sys.argv) < 2:
    print "Feed me a file and Krampus stays away."
    sys.exit(0)

f = open(sys.argv[1], 'r')

# Initialize the wires
wires = defaultdict(int)
wires['a'] = 0

for line in f:
    words = line.split()

    # NOT statements are split: [NOT, gate, ->, gate]
    if words[0] == 'NOT':
        wires[words[3]] = shortNOT(wires[words[1]])
        continue

    if words[1] == '->':
        input = int(words[0]) if words[0].isdigit() else wires[words[0]]
        wires[words[2]] = input
        continue

    # 1st input
    input1 = int(words[0]) if words[0].isdigit() else wires[words[0]]
    # 2nd input
    input2 = int(words[2]) if words[2].isdigit() else wires[words[2]]
    # Gate
    gate = words[1]
    # Output
    output = words[4]

    if gate == 'AND':
        wires[output] = shortAND(input1, input2)
    elif gate == 'OR':
        wires[output] = shortOR(input1, input2)
    elif gate == 'LSHIFT':
        wires[output] = shortLSHIFT(input1, input2)
    elif gate == 'RSHIFT':
        wires[output] = shortRSHIFT(input1, input2)

#print wires['x']
#print wires['y']

#print wires['d']
#print wires['e']

#print wires['f']
#print wires['g']

#print wires['h']
print wires['a']
