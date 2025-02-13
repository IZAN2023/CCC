word = input() 
R = int(input())
C = int(input())
grid = [input().split() for _ in range(R)]
total = 0
directions = [(1,0),(0,1),(-1,0),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1)]

def turn_90(direction):
    return (-direction[1], direction[0])
def turn_270(direction):
    return (direction[1], -direction[0])

def check_word(x, y, direction, index, turned):
    if (0 <= x < R) and (0 <= y < C):
        if grid[x][y] == word[index] and index == len(word) -1:
            return 1
        elif grid[x][y] == word[index]:
            return_data = check_word(x + direction[0], y + direction[1], direction, index + 1, turned)
            if not turned and index > 0:
                new_dirs = [turn_90(direction), turn_270(direction)]
                for new_d in new_dirs:
                    return_data += check_word(x + new_d[0], y + new_d[1], new_d, index + 1, True)
            return return_data
        else:
            return 0
    else:
        return 0

for i in range(R):
    for j in range(C):
        if grid[i][j] == word[0]:
            for d in directions:
                total += check_word(x=i, y=j, direction=d, index=0, turned=False)

print(total)






