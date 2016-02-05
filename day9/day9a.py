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


shortest_distance = None

# Go through every permutation and find the shortest path!
for path in itertools.permutations(locations):
    last_town = len(path) - 1
    current_distance = 0

    for i in range(len(path)):
        if i == last_town:
            if current_distance < shortest_distance or shortest_distance is None:
                shortest_distance = current_distance
        else:
            current_distance += distances[path[i]][path[i+1]]

# Answer is 207
assert shortest_distance == 207