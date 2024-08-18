M = int(input())  # 行
N = int(input())  # 列
grid = [list(map(int, (input().split()))) for _ in range(M)]

from pprint import pprint
# pprint(grid)

def find_element(element, grid):
    index_list = []
    for i, sublist in enumerate(grid):
        for j, num in enumerate(sublist):
            if num == element:
                index_list.append((i + 1, j + 1))
    return index_list

stack = find_element(M * N, grid)
searched_stack = {(M, N)}

result = False

while stack:
    print(stack)
    print(f"searched: {searched_stack}")
    if (1, 1) in stack:
        result = True
        break
    x, y = stack.pop()
    if (x, y) in searched_stack:
        continue
    searched_stack.add((x, y))
    next_num = x * y
    stack.extend(find_element(next_num, grid))

if result:
    print("yes")
else:
    print("no")