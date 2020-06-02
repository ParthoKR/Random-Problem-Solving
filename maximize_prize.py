import math
def solve_quad(n):
    a = 1
    b = 1
    c = -2*n
    # res1 = (-b + (b**2-4*a*c)**.5)/2*a
    # res2 = (-b - (b**2-4*a*c)**.5)/2*a
    if((b**2-4*a*c)**.5 > - b):
        res = (-b + (b**2-4*a*c)**.5)/2*a
    else:
        res =  (-b - (b**2-4*a*c)**.5)/2*a
    # if res1 >= 0:
    #     return math.floor(res1)
    return math.floor(res)

def solve(n):
    res = solve_quad(n) - 1
    extra = n - int(res*(res+1)/2)
    lst = list(range(1, res+1)) + [extra]
    return (res+1, lst)
n = int(input())
r = solve(n)
print(r[0],'\n',*r[1])
