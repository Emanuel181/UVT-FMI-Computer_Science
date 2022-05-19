print("Introduceti limita multimii de valori (Presupunem ca fiecare tablou are elemente din {1, ..., m})")
print("m = ", end = '')
m = int(input())
print()

def tablou_de_frecventa(arr1, arr2, arr3):
    frq = [0] * m
    for i in range(len(arr1)):
        frq[arr1[i]] += 1
        frq[arr2[i]] += 1
        frq[arr3[i]] += 1

    return frq

def gasire_element_comun(frq):
    for i in range(m):
        if frq[i] == 3:
            return True

    return False


a = [3, 1, 5, 10]
b = [4, 2, 6, 1]
c = [5, 3, 1, 7]

frq = tablou_de_frecventa(a, b, c)
print(gasire_element_comun(frq, c))






