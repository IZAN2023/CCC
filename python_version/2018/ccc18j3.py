d1, d2, d3, d4 = map(int, input().split())
d12 = d1
d13 = d1 + d2
d14 = d1 + d2 + d3
d15 = d1 + d2 + d3 + d4
d23 = d2
d24 = d2 + d3
d25 = d2 + d3 + d4
d34 = d3
d35 = d3 + d4
d45 = d4

distance_matrix = [
    [0, d12, d13, d14, d15],
    [d12, 0, d23, d24, d25],
    [d13, d23, 0, d34, d35],
    [d14, d24, d34, 0, d45],
    [d15, d25, d35, d45, 0]
]

for row in distance_matrix:
    print(' '.join(map(str, row)))

