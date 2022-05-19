def citeste_date1(numar1):
    inp = input()
    for i in inp.split():
        numar1.append(int(i))

    return numar1


def citeste_date2(numar2):
    inp = input()
    for i in inp.split():
        numar2.append(int(i))

    return numar2


def adunare(numar1, numar2):
    numar3 = []
    transport = 0

    for i in range(len(numar1) - 1, - 1, -1):
            numar3.append( ((numar1[i] + numar2[i]) + transport) % 2 )

            if numar1[i] + numar2[i] + transport >= 2:
                transport = (numar1[i] + numar2[i] + transport) // 2
            else:
                transport = 0

    rez = numar3[::-1]

    return rez

print()
print("Pe cati biti se realizeaza adunarea: ", end = '')
k = int(input())
print()

print("Scrieti cifrele binare ale primului numar: ", end = '')
numar1 = []
numar1 = citeste_date1(numar1)
print()
numar2 = []
print("Scrieti cifrele binare celui de-al doilea numar: ", end = '')
numar2 = citeste_date2(numar2)
print()

print("Adunarea celor doua numere este data de lista: ", end = '')
print(adunare(numar1, numar2))
print()

verificare = adunare(numar1, numar2)

if len(verificare) >= k:
    print("Adunarea nu este valida, se produce depasirea domeniului de", k, "biti")

# numar1: 0 1 1 1 1 0 0 0
# numar2: 0 0 1 1 1 0 0 1
