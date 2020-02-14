


def manhattan_distance(a,b):
    x=0
    for i in range(len(a)):
        x+=abs(a[i]-b[i])
    return x
print(manhattan_distance([2,4],[1,1]))