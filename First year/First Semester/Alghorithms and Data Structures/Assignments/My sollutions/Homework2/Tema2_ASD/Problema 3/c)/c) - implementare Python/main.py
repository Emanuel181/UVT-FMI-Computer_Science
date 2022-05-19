# Algoritm pentru lucrul cu numere mari

def citire_NrMare() :
    NrMare = input()
    NrMare = [int(char) for char in NrMare]
    NrMare = NrMare[::-1]
    NrMare.insert(0, len(NrMare))

    return NrMare

def scade_NrMari(a,b):

    if a[0] > b[0]:
        while b[0] != a[0]:
            b.append(0)
            b[0] += 1

    i = 1
    t = 0
    rez = [0] * a[0]

    while(i <= a[0]):
        nr = (a[i] - b[i]) + t

        if nr < 0:
            rez[i-1] = nr + 10
            t = -1
        else:
            rez[i-1] = nr

        i += 1

    rez.insert(0, len(rez))

    return rez


print()
print('''
Programul foloseste algoritmi pentru lucrul cu numere mari unde pe pozitia [0] din lista se afla numarul de cifre, iar cifrele numarului
sunt stocate in ordine inversa. Pentru a citi numarul, se citeste lista de la dreapta la stanga exceptand ultima pozitie care indica de fapt
numarul de cifre ale numarului. Asa cum se spune in cerinta, se presupune ca primul numar este mai mare sau egal decat al doilea.''')

print()

print("Primul numar este: ", end = '')
NrMare1 = citire_NrMare()
print(NrMare1)


print()

print("Al doilea numar este: ", end = '')
NrMare2 = citire_NrMare()
print(NrMare2)

print()

print("Diferenta lor sub forma de lista este: ", scade_NrMari(NrMare1, NrMare2))








