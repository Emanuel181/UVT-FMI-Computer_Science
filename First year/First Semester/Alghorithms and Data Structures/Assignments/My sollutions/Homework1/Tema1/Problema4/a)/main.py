def alg1(a,b):
    if a < b:
        a, b = b, a

    c = 0
    d = a

    while d > b:
        c += 1
        d = d - b

    return c, d


def alg2(n):
    i = 1
    x = 0

    while i <= n:
        i *= 2
        x += 1

    return x


# a, b, n = int(input), int(input()), int(input())

# print(alg1(a,b))

# print(alg2(n))