import collections
import itertools

__author__ = 'aestrada'

locations = set()
distances = collections.defaultdict(dict)

# Build up a dictionary of distances
with open('input-a.txt') as f:
    for line in f:
        words = line.split()

        dest1 = words[0]
        dest2 = words[2]
        distance = int(words[4])

        locations.update([dest1, dest2])

        distances[dest1][dest2] = distance
        distances[dest2][dest1] = distance


longest_distance = None

# Go through every permutation and find the longest path!
for path in itertools.permutations(locations):
    last_town = len(path) - 1
    current_distance = 0

    for i in range(len(path)):
        if i == last_town:
            if current_distance > longest_distance or longest_distance is None:
                longest_distance = current_distance
        else:
            current_distance += distances[path[i]][path[i+1]]

# Answer is 804
assert longest_distance == 804
