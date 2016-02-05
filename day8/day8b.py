__author__ = 'aestrada'

num_chars = 0
total_len = 0
with open('input-a.txt') as f:
    for line in f:

        # Remove the newline at the end
        line = line.rstrip()
        total_len += len(line)

        # Double all backslashes
        line = line.replace('\\', '\\\\')
        # Turn all " into \"
        line = line.replace(r'"', r'\"')
        # Add new quotes
        line = '"' + line + '"'

        num_chars += len(line)

# Answer is 2117
print num_chars - total_len

