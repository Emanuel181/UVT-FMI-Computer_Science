def citire_coef(coef, n):

    for i in range(n):
        print("coef[",i,"] = ", sep = '', end = '')
        coef.append(int(input()))
        print()

    return coef



def cautare_div_termen_liber(num):
    lista_div = []

    for i in range(1,num + 1):
        if num % i == 0:
            lista_div.append(i)
            lista_div.append((-i))

    return lista_div



def cautare_div_termen_grad_maxim(num):
    lista_div = []

    for i in range(1,abs(num) + 1):
        if num % i == 0:
            lista_div.append(i)
            lista_div.append(-i)

    return lista_div



def radacini(div_tl, div_tm):
    lista_radacini = []
    for i in div_tl:
        for j in div_tm:
            lista_radacini.append((i,j))

    return lista_radacini

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



def calculare_polinom(lista_radacini, coef):
    lista_rationali = []

    for k in range(len(lista_radacini)):
        sum_numarator = 0
        sum_numitor = 0
        for i in range(n-1, 0, -1):
            numa = lista_radacini[k][0]
            numi = lista_radacini[k][1]
            numa = numa ** i
            numi = numi ** i

            numa *= coef[i]
            numa, numi = simplificare(numa, numi)

            if numa < 0:
                sum_numarator, sum_numitor = scadere(sum_numarator, sum_numitor, numa, numi)
            else:
                sum_numarator, sum_numitor = adunare(sum_numarator, sum_numitor, numa, numi)

        if coef[0] < 0:
            sum_numarator, sum_numitor = scadere(sum_numarator, sum_numitor, -1 * coef[0], 1)
        else:
            sum_numarator, sum_numitor = adunare(sum_numarator, sum_numitor, coef[0], 1)


        if sum_numarator == 0:
            lista_rationali.append([lista_radacini[k][0], lista_radacini[k][1]])

    return lista_rationali




print()
print("Cati coeficienti sa aiba polinomul?(incluzand termenul liber): ", end = '')
n = 3
print()


print()
print("Scrieti coeficientii, termenul de pe ultima pozitie va fi termenul liber:")
coef = [8,-10,3]
# coef = citire_coef(coef, n)
print()

div_tl = cautare_div_termen_liber(coef[len(coef) - 1])
div_tm = cautare_div_termen_grad_maxim(coef[0])
lista_radacini = radacini(div_tl, div_tm)


print(lista_radacini)
print()
print("Lista cu divizorii termenului de grad maxim (", coef[0], ") este:  ", div_tm)
print("Lista cu divizorii termenului liber (", coef[len(coef)-1], ") este:", div_tl)
print()


coef = coef[::-1]


rez = calculare_polinom(lista_radacini, coef)


# Am lucrat cu modul iar pentru un rezultat corect de forma (a,b) imi afiseaza si (-a,-b), inca nu stiu cum
# sa rezolv aceasta problema de afisare, asa ca le-am convertit pe toate la valoarea absoluta
for i in range(len(rez)):
    if rez[i][0] < 0 and rez[i][1] < 0:
        rez[i][0] = abs(rez[i][0])
        rez[i][1] = abs(rez[i][1])

print(rez)
