def few_points(sets):
    sets.sort(key=lambda x: x[1])
    points = list()
    point = sets[0][1]
    points.append(point)
    for i in range(1, len(sets)):
        if(point < sets[i][0] or point > sets[i][1]):
            point = sets[i][1]
            points.append(point)
    return points
n = int(input())
sets = []
for i in range(0, n):
    sets.append([int(i) for i in input().split()])
print(len(few_points(sets)))
for i in few_points(sets):
    print(i, end=' ')
