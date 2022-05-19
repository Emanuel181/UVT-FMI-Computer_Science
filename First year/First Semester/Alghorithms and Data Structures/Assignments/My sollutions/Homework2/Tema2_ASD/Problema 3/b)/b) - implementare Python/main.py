
def citire_NrMare() :
    NrMare = input()
    NrMare = [int(char) for char in NrMare]
    NrMare = NrMare[::-1]
    NrMare.insert(0, len(NrMare))

    return NrMare

def aduna_NrMari(a,b):

    if a[0] > b[0]:
        while b[0] != a[0]:
            b.append(0)
            b[0] += 1

    elif b[0] > a[0]:
        while a[0] != b[0]:
            a.append(0)
            a[0] += 1

    i = 1
    t = 0
    rez = [0] * a[0]

    while(i <= a[0]):
        rez[i-1] = ((a[i] + b[i]) + t ) % 10
        t = ((a[i] + b[i]) + t) // 10
        i += 1

    # Depasire de domeniu
    if t != 0:
        return [-1] * a[0]

    return rez


print()
print("Primul numar este: ", end = '')
NrMare1 = citire_NrMare()
print(NrMare1)

print()

print("Al doilea numar este: ", end = '')
NrMare2 = citire_NrMare()
print(NrMare2)

print()

print("Suma lor este: ", aduna_NrMari(NrMare1, NrMare2))
if aduna_NrMari(NrMare1, NrMare2)[0] == -1:
    print("S-a produs o depasire de domeniu, s-a returnat o lista de -1")








