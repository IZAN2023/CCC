def find_shortest_cycle(temperature_diffs):
    n = len(temperature_diffs)
    for length in range(1, n + 1):
        # Check if current length can be a valid cycle
        if n % length == 0:  # Length must divide the total number of differences
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
    # Read input
    line = input().strip()
    if line == '0':
        break
    
    data = list(map(int, line.split()))
    n = data[0]
    temperatures = data[1:]
    
    if n == 1:
        # If there is only one temperature, no change, hence no cycle
        print(1)
        continue
    
    # Compute the differences
    temperature_diffs = [temperatures[i + 1] - temperatures[i] for i in range(n - 1)]
    
    # Find the shortest cycle
    shortest_cycle = find_shortest_cycle(temperature_diffs)
    print(shortest_cycle)