def num(l):
    st = ""
    pro = 1
    for i in l:
        if i == '0' and l.index(i) == 0:
            continue
        st += i
        pro *= int(i)
    return (int(st), pro)

def max(L,R):
    ans = R
    right = [i for i in str(R)]
    for i in range(0, len(right)):
        curr = right
        curr[i] = str(int(curr[i])-1)
        for j in range(i+1, len(right)):
            curr[j] = '9'
        print(curr, num(curr)[0], num(curr)[1])
        if(num(curr)[0] > L and num(curr)[1] > num([i for i in str(ans)])[1]):
            ans = num(curr)[0]
    return ans

print("Max: "+max(1, 20000))
