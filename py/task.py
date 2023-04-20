# Define a generator which generates the positive integers up to
# and including a supplied value which are divisible by another
# supplied positive integer
def gen(n, i):
    return (j for j in range(1,n+1) if j%i==0)

# and use it to calculate the sum of all
# positive integers less than 102030 which are divisible by 3
def useGen():
      return sum((gen(102030,3)))

'''
Write a function which is passed an integer, n, and
returns a list of n lists such that:
f(0) returns []
f(1) returns [[1]]
f(2) returns [[1], [1,2]]
f(3) returns [[1], [1,2], [1,2,3]]
etc.
'''
def f(n):
        return [list(range(1, x+1)) for x in range(1, n+1)]