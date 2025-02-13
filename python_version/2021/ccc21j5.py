#step 1 input
#input part , row,column and num(example:the sum of "R 1" "C 1")
r = int(input())
c = int(input())
n = int(input())
#make a grid 
grid = [[0 for _ in range(c)] for _ in range(r)]
#make total(dont need to do it at first, we use in step 3)
total = 0
#step 2 change 0 in grid to 1 and 1 to 0(change black to gold and change gold to black)
for k in range(n):
    axisandindex = input()
    axisandindex_list = axisandindex.split()#make "R 2" to R,2 
    index = int(axisandindex_list[1]) - 1 #we write R 2 and 2(1,2,3) in comupter is 1(0,1,2) so we change
    #write if and elif to ask if it's R or it's C and we change 0 to 1 or 1 to 0 in the grid
    if axisandindex_list[0] == 'R':
        for j in range(c):
            grid[index][j] = 1 - grid[index][j]
    elif axisandindex_list[0] == 'C':
        for i in range(r):
            grid[i][index] = 1 - grid[i][index]

#step 3 get the total
flattened_list = [item for l in grid for item in l]#change our 2D list to flat list
total += flattened_list.count(1)#count how many 1 in the list

#step 4 print
print(total)
