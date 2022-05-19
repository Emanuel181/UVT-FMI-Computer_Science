def serie_1(x, eps, n):
        curent = (((-1) ** (n+1))/n) * ((x - 1)**n)
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

def serie_2(x,eps,n):
    curent = (((x-1)/x)**n)/n
    # sum = curent
    # print(sum)

    if abs(curent < eps):
        return n

    else:
        while curent >= eps:
            n += 1
            curent = (((x-1)/x)**n)/n
            # sum += curent
            # print(sum)

        return n


print()
print("Valoarea epsilon este(se va scrie sub forma de numar real): ", end = '')
eps = float(input())
print()

print("Valoarea lui x este: ", end = '')
x = float(input())
print()

if 0 < x <= 1 :
    print("Numarul de termeni din suma este: ", serie_1(x,eps,1), end = '')
    print()

else:
    print("Numarul de termeni din suma este: ", serie_2(x,eps,1), end ='')
    print()