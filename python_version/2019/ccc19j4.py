grid = [[1, 2], [3, 4]]
flips = input()
for flip in flips:
    if flip == "H":
        grid[0],grid[1] = grid[1],grid[0]

    elif flip == "V":
        grid[0][0],grid[0][1] = grid[0][1],grid[0][0]
        grid[1][0],grid[1][1] = grid[1][1],grid[1][0]
for i in grid:
    print(f"{i[0]} {i[1]}")