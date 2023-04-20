# Define a generator which generates the positive integers up to and including a supplied value
# which are divisible by another supplied positive integer
def gen(n, i):
    return (j for j in range(1,n+1) if j%i==0)

# and use it to calculate the sum of all
# positive integers less than 102030 which are divisible by 3
def useGen():
      return sum((gen(102030,3)))