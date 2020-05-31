def min_refill():
    L = 400
    n = 5
    points = [0,200,375,550,750,950]
    num_refills = 0
    current_refill = 0
    last_refil = 0
    while(current_refill <= n-1):
        last_refil = current_refill
        while(current_refill <= n-1 and points[current_refill+1] - points[last_refil] <= L):
            current_refill = current_refill + 1
        if current_refill == last_refil:
            print("Impossible")
        if current_refill <= n-1:
            num_refills += 1
    print(num_refills)

min_refill()
