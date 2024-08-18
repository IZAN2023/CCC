n = int(input())

for _ in range(n):
    line = input()
    compress = []
    count = 1
    for i in range(1, len(line)):
        if line[i] == line[i - 1]:
            count += 1
        else:
            compress.append(f"{count} {line[i - 1]}")
            count = 1
    compress.append(f"{count} {line[-1]}")

    print(" ".join(compress))
    