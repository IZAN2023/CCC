from pprint import pprint

R = int(input())
C = int(input())
grid = [input() for _ in range(R)]
start_row = int(input())
start_column = int(input())
# 定义价格字典
prices = {"S": 1, "M": 5, "L": 10}
total = 0
# 四个移动方向
directions = [(0, 1), (1, 0), (-1, 0), (0, -1)]
# 收割地图，已收割的地方将被标记True，默认是False，难点是column和row不要搞反了
h_map = [[False for _ in range(C)] for _ in range(R)]
# pprint(grid)
# pprint(h_map)


def harvest(row, column):
    global total
    # 只要是未收割的格子，并且不是*，就收割，收割后在地图上标记True
    if not h_map[row][column] and grid[row][column] != "*":
        total += prices[grid[row][column]]
        h_map[row][column] = True
        # 试图往四个方向上移动
        for direction in directions:
            next_r = row + direction[0]
            next_c = column + direction[1]
            # 只要在合理的格子范围内，则继续尝试收割
            if 0 <= next_r < R and 0 <= next_c < C:
                harvest(next_r, next_c)


# 从起始地点开始收割
harvest(start_row, start_column)
print(total)

#
# def harvest(row, column):
#     global total
#     total += prices[grid[row][column]]
#     h_map[row][column] = True
#
#
# stack = [(start_row, start_column)]
# harvest(start_row, start_column)
# while stack:
#     current_r, current_c = stack.pop()
#     for direction in directions:
#         next_r = current_r + direction[0]
#         next_c = current_c + direction[1]
#         if 0 <= next_r < R and 0 <= next_c < C and not h_map[next_r][next_c] and grid[next_r][next_c] != "*":
#             harvest(next_r, next_c)
#             stack.append((next_r, next_c))
#
# print(total)

