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

# want n=0 returns 2, n=1 returns 8, etc
# want to calculate the n^th indexed even fib number s.t evenfib(0) = 2
# BUT want the total sum of n even fib numbers.
def sum_fib_even(n):
    '''
    Calculate the sum of the first n even-valued Fibonacci numbers.

    :param n: The number of even-valued Fibonacci numbers to sum.
    :return: The sum of the first n even-valued Fibonacci numbers.
    '''
    assert n>=0, "n must be non-negative"
    a,b = 0,2
    r,sumf,i = b,0,0
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
def get_dupes(l1, l2):
    '''
    Returns the intersection of the given sorted lists as an array
    
    :param l1: The first sorted list
    :param l2: The second sorted list
    :return: The intersection of l1 and l2 as an array
    '''
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

def only_even_digits(i):
    '''
    Checks if the given integer i contains only even digits

    :param i: the integer to check
    :return: true if i contains only even digits, false otherwise
    '''
    while (i > 0):
        digit = i % 10;
        if (digit % 2) != 0:
            return False
        i //= 10
    return True

# format X+XX+XXX+XXXX
def return_value(x):
    '''
    Calculates the value of X+XX+XXX+XXXX where X=x
    :param x: the integer to be used as X
    :return: The result of X+XX+XXX+XXXX where X=x
    '''
    result,part = 0,0
    for i in range(0,4):
        part = (part*10) + x
        result += part
    return result