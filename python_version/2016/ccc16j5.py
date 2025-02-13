choice = int(input())
n = int(input())
my_numbers = []
for x in range(2):
    my_numbers.append(input().split())
numbers = [item for sublist in my_numbers for item in sublist]
numbers = [int(x) for x in numbers]

if choice == 1:
    half = n
    first_half = numbers[:half]
    second_half = numbers[half:]
    total = 0
    matched_indices = set()
    for i in range(len(first_half)):
        min_difference = float('inf')
        best_match = None

        for j in range(len(second_half)):
            if j in matched_indices:
                continue
            difference = abs(first_half[i] - second_half[j])
            if difference < min_difference or (difference == min_difference and first_half[i] == second_half[j]):
                min_difference = difference
                best_match = j
        if best_match is not None:
            total += max(first_half[i], second_half[best_match])
            matched_indices.add(best_match)
    print(total)
elif choice == 2:
    largest = sorted(numbers, reverse=True)[:n]
    total_sum = sum(largest)
    print(total_sum)

