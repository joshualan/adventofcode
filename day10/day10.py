def look_and_say(line, x):
    for i in range(x):
        prev_char = None
        count = 0
        new_line = ""

        for index, c in enumerate(line):
            if prev_char is None:
                prev_char = c
                count += 1
            # Increment count if char is still the same
            elif c == prev_char:
                count += 1
            # If we have a new char, update the string!
            elif c != prev_char:
                new_line += str(count)
                new_line += str(prev_char)
                prev_char = c
                count = 1

        # Add the last sequences of characters
        new_line += str(count)
        new_line += str(prev_char)

        line = new_line

    return len(line)

input = "1113122113"
output = look_and_say(input, 40)

assert output == 360154

output = look_and_say(input, 50)
assert output == 5103798