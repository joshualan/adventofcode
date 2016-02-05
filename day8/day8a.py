__author__ = 'aestrada'

import re

num_chars = 0
total_len = 0

with open('input-a.txt') as f:
    for line in f:

        # Remove the newline at the end
        line = line.rstrip()
        total_len += len(line)

        # Remove those pesky double slashes
        line = line.replace(r'\\', 'a')

        # Find every match
        regex1 = r'\\x[0-9a-f]{2}'
        regex2 = r'\\"'
        regex3 = r'^"|"$'

        hex = re.findall(regex1, line)
        quote = re.findall(regex2, line)
        string_quote = re.findall(regex3, line)

        # Subtract the extra characters
        # to get the actual number of characters
        hexes = len(hex) * 3
        quotes = len(quote)
        string_quotes = len(string_quote)

        num_chars += len(line) - hexes - quotes - string_quotes

# Answer is 1371
print total_len - num_chars
