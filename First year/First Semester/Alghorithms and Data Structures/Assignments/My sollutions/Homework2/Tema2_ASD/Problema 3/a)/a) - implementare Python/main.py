
def citire_NrMare() :
    NrMare = input()
    NrMare = [int(char) for char in NrMare]
    NrMare = NrMare[::-1]
    NrMare.insert(0, len(NrMare))

    return NrMare

def compara_NrMari(a, b):
    if a[0] > b[0]:
        return "+1"

    elif b[0] > a[0]:
        return "-1"

    else:
        for i in range(a[0], -1, -1):
            if a[i] > b[i]:
                return "+1"
            elif b[i] > a[i]:
                return "-1"

    # Numere egale
    return 0

print("Primul numar este: ", end = '')
NrMare1 = citire_NrMare()
print(NrMare1)

print()

print("Al doilea numar este: ", end = '')
NrMare2 = citire_NrMare()
print(NrMare2)

print()

if compara_NrMari(NrMare1, NrMare2) == "+1":
     print("Primul numar este mai mare")

elif compara_NrMari(NrMare1, NrMare2) == "-1":
    print("Al doilea numar este mai mare")

else:
    print("Numerele sunt egale")














