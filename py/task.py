def gen(n, i):
    '''
    Returns a generator of the positive integers up 
    to and including n which are divisible by i.

    :param n: the inclusive limit of the positive 
              integers to be generated
    :param i: the positive integer by which the
              generated integers are divisble
    :return: generator of the positive integers up 
             to and including n which are divisible
             by i.
    '''
    return (j for j in range(1,n+1) if j%i==0)

def useGen():
    '''
    Returns the sum of all positive integers less
    than 102030 which are divisible by 3
    '''
    return sum((gen(102030,3)))

def f(n):
    '''
    Returns a list of n lists such that f(0)
    returns [], f(1) returns [[1]], f(2) returns
    [[1], [1,2]] and so forth

    :param n: the number of lists to be returned within
              the nested list (nested list of size n).
              This is also the maximum value of the last
              nested list.
    :return: a nested list of size n, e.g. f(2) [[1],[1,2]]
    '''
    return [list(range(1, x+1)) for x in range(1, n+1)]