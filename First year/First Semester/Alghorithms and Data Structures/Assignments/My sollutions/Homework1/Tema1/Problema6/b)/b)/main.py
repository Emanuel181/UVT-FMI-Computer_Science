def citire_x(x):
    x = input()
    x = x.split()
    for i in range(len(x)):
        x[i] = int(x[i])

    return x


def construire_m(m,x):
    sum = 0

    for i in range(0, len(x)):
        sum += x[i]
        m.append(sum//(i+1))

    return m


x = []
print("Introduceti elementele lui x pe un rand: ", end = '')
x = citire_x(x)
print()

m = []
print("Tabloul m este: ")
m = construire_m(m,x)

print(m)
