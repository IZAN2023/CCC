N = int(input())
yard = [[0 for _ in range(N)] for _ in range(N)]
T = int(input())
for _ in range(T):
    row, column = map(int, input().split())
    yard[row - 1][column - 1] = 7

from pprint import pprint    # for test only
pprint(yard)                 # for test only

# dp 代表一个动态规划表，用于存储网格中每个位置作为右下角的最大正方形区域的边长。具体来说：
# dp[i][j] 表示以 (i, j) 作为右下角的最大正方形区域的边长。
# dp 表是一个与网格 yard 同样大小的二维数组，初始值为 0。
dp = [[0 for _ in range(N)] for _ in range(N)]

max_size = 0
for i in range(N):
    for j in range(N):
        if yard[i][j] == 0:  # 只有在没有树的位置才进行计算
            if i == 0 or j == 0:
                dp[i][j] = 1
                # 边界上的正方形边长为 1
            else:
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                # 我们通过查看它上方、左方和左上角的 dp 值来确定当前最大正方形的边长。
                # dp[i][j] 的值为这三者中的最小值加 1
            max_size = max(max_size, dp[i][j])
            #  更新当前找到的最大正方形边长

print(max_size)