def optimal_summands(n):
    summands = []
    for i in range(1, n+1):
        if i*2 >= n:
            summands.append(n)
            break
        summands.append(i)
        n -= i
    print(len(summands))
    print(*summands)

n = int(input())
optimal_summands(n)
