import math

def serie_1(x, eps, n):
    curent = (((-1) ** (n + 1)) / n) * ((x - 1) ** n)
    # sum = curent
    # print(sum)

    if abs(curent < eps):
        return n

    else:
        while curent >= eps:
            n += 1
            curent = (((-1) ** (n + 1)) / n) * ((x - 1) ** n)
            # sum += curent
            # print(sum)

        return n


def serie_2(x, eps, n):
    curent = (((x - 1) / x) ** n) / n
    # sum = curent
    # print(sum)

    if abs(curent < eps):
        return n

    else:
        while curent >= eps:
            n += 1
            curent = (((x - 1) / x) ** n) / n
            # sum += curent
            # print(sum)

        return n


def calc_aproximare(m,h,eps):
    rez = 0
    for i in range(1, m+1):
        if 0 < i*h <= 1:
            rez = rez + ((serie_1(i*h,eps,1) - math.log(i*h))**2)
        else:
            rez = rez + ((serie_2(i*h,eps,1) - math.log(i*h))**2)

    return rez



print()
print("Valoarea epsilon este(se va scrie sub forma de numar real): ", end='')
eps = float(input())
print()

print("Valoarea lui m pentru limita sumei: ", end='')
m = int(input())
print()

h = 5/m

print("Aproximarea este: ", end = '')
print(calc_aproximare(m, h, eps))