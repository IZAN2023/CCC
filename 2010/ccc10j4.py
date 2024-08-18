def find_shortest_cycle(temperature_diffs):
    n = len(temperature_diffs)
    for length in range(1, n + 1):
        if n % length == 0:
            cycle = temperature_diffs[:length]
            valid_cycle = True
            for i in range(length, n):
                if temperature_diffs[i] != cycle[i % length]:
                    valid_cycle = False
                    break
            if valid_cycle:
                return length
    return n

while True:
    line = input()
    if line == '0':
        break
    
    data = list(map(int, line.split()))
    n = data[0]
    temperatures = data[1:]
    
    if n == 1:
        print(1)
        continue
    print(find_shortest_cycle([temperatures[i + 1] - temperatures[i] for i in range(n - 1)]))