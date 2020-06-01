def min_refill(total, mileage, n):
    points = [0]+[int(i) for i in input().split()]+[total]
    points = sorted(points)
    tank = mileage
    count = 0
    for i in range(1, n+2):
        if(points[i]-points[i-1]<=tank):
            tank -= points[i]-points[i-1]
        else:
            tank = mileage
            tank -= points[i]-points[i-1]
            if(tank<0):
                break
            count += 1
    if(tank<0):
        return -1
    return count
total = int(input())
mileage = int(input())
n = int(input())

print(min_refill(total, mileage, n))
