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


def findVal(lines, wires, wire):
    if wire in wires:
        return wires[wire]

    if wire.isdigit():
        return int(wire)

    for line in lines:
        words = line.split()

        # Simple assignment
        if words[1] == '->':
            if words[2] != wire:
                continue

            wires[wire] = findVal(lines, wires, words[0])
            return wires[wire]

        elif words[0] == 'NOT':
            if words[3] != wire:
                continue

            wires[wire] = shortNOT(findVal(lines, wires, words[1]))
            return wires[wire]

        else:
            if words[4] != wire:
                continue

            lhs = findVal(lines, wires, words[0])
            rhs = findVal(lines, wires, words[2])

            if words[1] == 'AND':
                wires[wire] = shortAND(lhs, rhs)
            elif words[1] == 'OR':
                wires[wire] = shortOR(lhs, rhs)
            elif words[1] == 'LSHIFT':
                wires[wire] = shortLSHIFT(lhs, rhs)
            elif words[1] == 'RSHIFT':
                wires[wire] = shortRSHIFT(lhs, rhs)

            return wires[wire]

    return None

wires = {}

with open('input.txt') as f:
    lines = f.readlines()

tmp = findVal(lines, wires, 'a')

print wires['a']
