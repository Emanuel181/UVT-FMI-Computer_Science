def eps(a, e):
    actual = a
    next = ((2*actual) + a/(actual**2))/3

    if abs(next - actual) < e:
        print(next)
        exit()

    else:
        while abs(next - actual) >= e:
            print(next)
            actual = next
            next = ((2 * actual) + (a / (actual ** 2))) / 3



a = int(input())
print()
print(a)
eps(a, 0.00001)
