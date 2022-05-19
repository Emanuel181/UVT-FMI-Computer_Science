# Algoritm pentru lucrul cu numere mari

def citire_NrMare() :
    NrMare = input()
    NrMare = [int(char) for char in NrMare]
    NrMare = NrMare[::-1]
    NrMare.insert(0, len(NrMare))

    return NrMare

def inmultire_NrMari(a,b):
    prod = [0] * (a[0] + b[0]+1)

    prod[0] = (a[0] + b[0]-1)

    for i in range(1, b[0]+1):
        for j in range(1, a[0]+1):
            prod[i+j-1] += (b[i]*a[j])

    t = 0

    for i in range(1, prod[0]+1):
        t += prod[i]
        prod[i] = t % 10
        t //= 10

    if t:
        # prod[prod[0] + 1] = t
        return [-1] * (a[0] + b[0] )
    return prod


print()
print('''
Programul foloseste algoritmi pentru lucrul cu numere mari unde pe pozitia [0] din lista se afla numarul de cifre, iar cifrele numarului
sunt stocate in ordine inversa. Pentru a citi numarul, se citeste lista de la dreapta la stanga exceptand ultima pozitie care indica de fapt
numarul de cifre ale numarului. !!!!![Primul numar trebuie sa fie cel care are cele mai multe cifre]!!!!!.''')

print()

# Primul numar trebuie sa fie cel cu cifrele mai multe
print("Primul numar este: ", end = '')
NrMare1 = citire_NrMare()
print(NrMare1)


print()

print("Al doilea numar este: ", end = '')
NrMare2 = citire_NrMare()
print(NrMare2)

print()

if inmultire_NrMari(NrMare1,NrMare2)[0] == -1:
    print(inmultire_NrMari(NrMare1, NrMare2))
    print("S-a produs o depasire de domeniu, se afiseaza o lista de -1")

else:
    print("Inmultirea lor sub forma de lista este: ", inmultire_NrMari(NrMare1, NrMare2))
    print("Rezultatul se citeste de la dreapta spre stanga exceptand prima pozitie(pot sa apara cifre de 0 nesemnificative)")









