# The Fibonacci sequence is defined as a sequence of integers starting
# with 1 and 1, where each subsequent value is the sum of the preceding two. I.e
# f(0) = 1
# f(1) = 1
# f(n) = f(n-1) + f(n-2) where n >= 2
def fib(n):
    a,b,r = 0,1,1
    for i in range(0,n):
        r,a=a+b,b
        b=r
    return r

# Write a program in a language of your choice to calculate
# the sum of the first 100 even-valued
# Fibonacci numbers
# the evens = 
# 2,8,34,144,610
# want n=0 returns 2, n=1 returns 8, etc
# want to calculate the n^th indexed even fib number s.t evenfib(0) = 2
# BUT want the total sum of n even fib numbers.
def sumFibEven(n):
    assert n>=0
    a,b = 0,2
    r = b
    sumf = 0
    i = 0
    while i < n:
        sumf += r
        # the next even fib = 4 * current even fib + previous even fib
        # 1,1,2,3,5,8 - it's every third num
        r = 4*b + a
        a,b = b, r
        i+=1
        # r is the n^th even fib num
    return sumf


# use the two pointer technique
def getDupes(l1, l2):
    x, y, res = 0, 0, []
    
    while (x < len(l1)) and (y < len(l2)):
        # if dupes
        if l1[x] == l2[y]:
            # if the current element is not
            # already in the resultant list,
            # add it
            if not(res) or (l1[x] != res[-1]):
                res.append(l1[x])
            x += 1
            y += 1
        elif l1[x] < l2[y]:
            # if the current element
            # in l1 is smaller than that in l2,
            # there's no matching element in l2,
            # so, inc x by 1
            x += 1
        else:
            # vice versa
            y += 1
    
    return res

# stop as soon as any non-even digit is detected
def checkInt(i):
    for digit in str(i):
        if (int(digit) % 2 != 0):
            return False
    return True

# format X+XX+XXX+XXXX
def returnValue(x):
    s,part = 0,0
    for i in range(1,5):
        part = (part*10) + x
        s += part
    return s
    