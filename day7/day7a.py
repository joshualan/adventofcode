import collections

def shortNOT(val):
    return (~(val & 65535) & 65535)

def shortLSHIFT(val, shift):
    return ((val & 65535) << shift) & 65535

def shortRSHIFT(val, shift):
    return ((val & 65535) >> shift) & 65535

def shortAND(val1, val2):
    return (val1 & 65535) & (val2 & 65535)

def shortOR(val1, val2):
    return (val1 & 65535) | (val2 & 65535)


wires = collections.defaultdict(int)

with open('input.txt') as f:
    for line in f:
        words = line.split()

        if words[1] == '->':
            if words[0].isdigit():
                wires[words[2]] = int(words[0])
            else:
                wires[words[2]] = wires[words[0]]

        if words[0] == 'NOT':
            wires[words[3]] = shortNOT(wires[words[1]])

        if words[1] == 'AND':
            if words[0].isdigit():
                wires[words[4]] = shortAND(int(words[0]), wires[words[2]])
            else:
                wires[words[4]] = shortAND(wires[words[0]], wires[words[2]])

        if words[1] == 'OR':
            wires[words[4]] = shortOR(wires[words[0]], wires[words[2]])

        if words[1] == 'LSHIFT':
            wires[words[4]] = shortLSHIFT(wires[words[0]], int(words[2]))

        if words[1] == 'RSHIFT':
            wires[words[4]] = shortRSHIFT(wires[words[0]], int(words[2]))
    

print wires['a']
