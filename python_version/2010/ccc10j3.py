A = 0
B = 0

m = {'A': A, 'B': B}

while True:
    cmds = input().split(" ")
    if cmds[0] == '1':
      m[cmds[1]] = int(cmds[2])
    elif cmds[0] == '2':
      print(m[cmds[1]])
    elif cmds[0] == '3':
        m[cmds[1]] = m[cmds[1]] + m[cmds[2]]
    elif cmds[0] == '4':
        m[cmds[1]] = m[cmds[1]]*m[cmds[2]]
    elif cmds[0] == '5':
        m[cmds[1]] = m[cmds[1]] - m[cmds[2]]
    elif cmds[0] == '6':
        m[cmds[1]] = int(m[cmds[1]] / m[cmds[2]])
    elif cmds[0] == '7':
       break
