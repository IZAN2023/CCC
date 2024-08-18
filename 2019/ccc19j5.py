wordsrc = []
worddst = []
visited = [set() for _ in range(16)]

for _ in range(3):
    src = input().split()
    dst = input().split()
    wordsrc.append(src)
    worddst.append(dst)
#最大步数、初始字符串和目标字符串
steps = input().split()
src = input().split()
dst = input().split()
steps = int(steps)

def transform(cur_word, cur_step, path):
    #如果步数已经等于给定的步数
    if cur_step == steps:
        #如果字符串等于目标字符串
        if cur_word == dst:
            for p in path: print(*p)
            return True
        return False
    #如果已经访问过，防止重复
    if cur_word in visited[cur_step]:
        return False
    visited[cur_step].add(cur_word)

    for i in range(3):
        start = 0
        #在字符串中看wordsrc[i]的位置
        while (start := cur_word.find(wordsrc[i], start)) != -1:
            #只要找到赋给newword
            new_word = cur_word[:start] + worddst[i] + cur_word[start + len(wordsrc[i]):]
            #递归，用新字符串继续转换
            if transform(new_word, cur_step + 1, path + [(i + 1, start + 1, new_word)]):
                return True
            start += 1
    return False

transform(src, 0, [])
