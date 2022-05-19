def to_base_2(num):
    b2, p = 0, 1

    while(num):
        b2 = p*(num % 2) + b2
        num //= 2
        p *= 10

    return b2

def creare_lista_baza_2(num, lst):
    lst = [0] * (16 - len(str(num)))

    for cif in str(num):
        lst.append(cif)

    return lst

def complementeaza(lst):
    for i in range(len(lst) - 1, -1, -1):
        if lst[i] == 1:
            poz = i
            break

    for j in range(poz - 1, -1, -1):
        if lst[j] == 1:
            lst[j] = 0
        else:
            lst[j] = 1

    return lst

def to_int(lst):
    for i in range(len(lst)):
        lst[i] = int(lst[i])

    return lst

print("Introduceti numarul in baza 10: ", end = '')
num = int(input())
copy = num
num = to_base_2(num)
lst = []
lst = creare_lista_baza_2(num,lst)
lst = to_int(lst)
print()
print("Reprezentarea in baza 2 a numarului", copy, "este:   ", end='')
print(lst)
print()
lst = complementeaza(lst)
print("Complementul fata de 2 pentru numarul", copy, "este: ", end='')
print(lst)
