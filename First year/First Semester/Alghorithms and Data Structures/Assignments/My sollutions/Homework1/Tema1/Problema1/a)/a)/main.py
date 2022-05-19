def cmmdc(a, b):
    if a == 0:
        return b
    if b == 0:
        return a

    while b != 0:
        r = a % b
        a = b
        b = r

    return a


def simplificare(numitor, numarator):
    if numitor == 0:
        print("Impartire nevalida")

    else:
        if cmmdc(numitor, numarator) == 1:
            return "Fractia este ireductibila"
        else:
            return cmmdc(numitor, numarator)


print("Numaratorul primei fractii: ", end = '')
numarator1 = int(input())
print("Numitorul primei fractii: ", end = '')
numitor1 = int(input())

print()
print("Subpunctul a): ")

rez = simplificare(numitor1, numarator1)

if(type(rez)) == str:
    print(rez + ': ', end = '')
    print(numarator1, '/', numitor1, sep = '')
else:
    print("Fractia simplificata este: ", numarator1 // rez, '/', numitor1 // rez, sep = '')
print()