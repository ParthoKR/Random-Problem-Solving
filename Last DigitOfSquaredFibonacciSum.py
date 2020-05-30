def sq_fib(n):
    n%=60
    a,b = 0,1
    last = [0,1]
    sum = 0
    for _ in range(2, n+1):
        c = a+b
        a,b = b,c
        last.append((c**2)%10)
    for i in range(0, n+1):
        sum += last[i]
    print(sum%10)
n = int(input())
sq_fib(n)
