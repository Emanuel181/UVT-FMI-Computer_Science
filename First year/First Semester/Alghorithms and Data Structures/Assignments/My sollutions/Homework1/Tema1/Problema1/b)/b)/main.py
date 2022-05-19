def cmmdc(a,b):
    while (b != 0):
        r = a % b
        a = b
        b = r

    return a

def simplificare(numarator1, numitor1):

    a = numarator1
    b = numitor1

    div = cmmdc(numarator1,numitor1)

    return numarator1//div, numitor1//div


def adunare(numarator1, numitor1, numarator2, numitor2):
    numarator1 = (numitor2*numarator1) + (numarator2 * numitor1)
    numitor1 = numitor1 * numitor2

    return simplificare(numarator1, numitor1)



def scadere(numarator1, numitor1, numarator2, numitor2):
    numarator1 = (numitor2*numarator1) - (numarator2 * numitor1)
    numitor1 = numitor1 * numitor2

    return simplificare(numarator1, numitor1)


def inmultire(numarator1, numitor1, numarator2, numitor2):
    if numarator1 == 0 or numarator2 == 0:
        return 0

    numarator1 *= numarator2
    numitor1 *= numitor2

    return simplificare(numarator1, numitor1)


def impartire(numarator1, numitor1, numarator2, numitor2):
    if numarator1 == 0 or numarator2 == 0:
        return 0

    rez_numarator = numarator1 * numitor2
    rez_numitor = numitor1 * numarator2

    return simplificare(rez_numarator, rez_numitor)



print("Numaratorul primei fractii: ", end = '')
numarator1 = int(input())
print("Numitorul primei fractii: ", end = '')
numitor1 = int(input())
print("Numaratorul celei de-a doua fractii: ", end = '')
numarator2 = int(input())
print("Numitorul celei de-a doua fractii: ", end = '')
numitor2 = int(input())
print()


print("Subpunctul b: ")
print("Adunarea fractiilor este: ", adunare(numarator1, numitor1, numarator2,numitor2) )
print()
print("Scadera fractiilor este: ",  scadere(numarator1, numitor1, numarator2,numitor2))
print()
print("Inmultirea fractiilor este: ", inmultire(numarator1, numitor1, numarator2,numitor2))
print()
print("Impartirea fractiilor este: ", impartire(numarator1, numitor1, numarator2,numitor2))