import math


def euclid_distance(a,b):
    x=0
    for i in range(len(a)):
        x+=(a[i]-b[i])**2
    return math.sqrt(x)

print(euclid_distance([2,4],[1,1]))