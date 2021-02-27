n, m, k = map(int, input().split())
fact = [1 for _ in range(n + 2)]
for i in range(1, n + 2):
    fact[i] = fact[i - 1] * i
ch = [[1 for _ in range(n + 2)] for _ in range(n + 2)]
for i in range(n + 2):
    for j in range(1, i):
        ch[i][j] = ch[i - 1][j - 1] + ch[i - 1][j]
g = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    g[i][0] = fact[i]
    for j in range(1, i + 1):
        g[i][j] = (j - 1) * g[i - 1][j - 2] + (i - j) * g[i - 1][j - 1]


def getG(a, b, c):
    if b > c or b > a or a < 0 or b < 0 or c < 0:
        return 0
    return ch[c][b] * g[a - b][c - b]


def getVal(ans):
    a = n - len(ans)
    b = m
    c = a
    for i, x in enumerate(ans):
        if i == x:
            b -= 1
        if x >= len(ans):
            c -= 1
    return getG(a, b, c)


ans = []
for i in range(n):
    for j in range(0, n):
        if j in ans:
            continue
        ans.append(j)
        val = getVal(ans)
        if k > val:
            ans.pop()
            k -= val
        else:
            break

if len(ans) == n:
    ans = [str(a + 1) for a in ans]
    print(' '.join(ans))
else:
    print(-1)
