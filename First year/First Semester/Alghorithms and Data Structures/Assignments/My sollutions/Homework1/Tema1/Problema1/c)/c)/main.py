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

def citire_tablou(tablou_coef, c):
    for i in range(c):
        print('tabl_coef[', i, '] = ', end = '')
        tablou_coef.append(int(input()))

def adunare(numarator1, numitor1, numarator2, numitor2):
    if numarator1 == 0:
        return numarator2,numitor2

    else:
        numarator1 = (numitor2 * numarator1) + (numarator2 * numitor1)
        numitor1 = numitor1 * numitor2
        if numarator1 == 0:
            return 0, 0

    return numarator1, numitor1

def scadere(numarator1, numitor1, numarator2, numitor2):
    if numarator1 == 0:
        return -numarator2, numitor2

    else:
        numarator1 = (numitor2 * numarator1) - abs((numarator2 * numitor1))
        numitor1 = numitor1 * numitor2

        if numarator1 == 0:
            return 0, 0

    return numarator1, numitor1


def calculare_polinom(tabl_coef, numarator_valoare, numitor_valoare, c):

    sum_numarator = 0
    sum_numitor = 0

    for i in range(c - 1, 0, -1):
        numa = numarator_valoare
        numi = numitor_valoare
        numa = numa ** i
        numi = numi ** i

        numa *= tabl_coef[i]
        numa, numi = simplificare(numa,numi)

        if numa < 0:
            sum_numarator, sum_numitor = scadere(sum_numarator, sum_numitor, numa, numi)
        else:
            sum_numarator, sum_numitor = adunare(sum_numarator, sum_numitor, numa, numi)


    if tabl_coef[0] < 0:
        sum_numarator, sum_numitor = scadere(sum_numarator, sum_numitor, -1*tabl_coef[0], 1)
    else:
        sum_numarator, sum_numitor = adunare(sum_numarator, sum_numitor, tabl_coef[0], 1)

    return sum_numarator, sum_numitor



print("Subpunctul c): ")

print("Introdu numarul coeficientilor polinomului: ")
c = 4

print("Numaratorul valorii pentru care s va calcula polinomul: ")
numarator_valoare = 1

print("Numitorul valorii pentru care se va calcula polinomul")
numitor_valoare = 2

print("Dati valorile coeficientilor: ")
# [ATENTIE]: VALORILE SE INTRODUC IN ORDINEA INVERSA !!!
tabl_coef = [2, 1, -1, 2]



a,b = calculare_polinom(tabl_coef, numarator_valoare, numitor_valoare, c)
div = cmmdc(a,b)
print("Valoarea polinomului este: ", a//div ,' / ', b//div, end = '')
print()