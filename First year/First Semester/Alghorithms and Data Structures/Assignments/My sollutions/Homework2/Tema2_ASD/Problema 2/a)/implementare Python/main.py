import math

def creare_lista_normeEuclidiene(mat):
    lista_normeEuclidiene = []
    for i in mat:
        norma_euclidiana = 0
        for j in i:
            norma_euclidiana += j ** 2

        lista_normeEuclidiene.append(math.sqrt(norma_euclidiana))

    return lista_normeEuclidiene

def sortare_linii_dupa_normaEuclidiana(mat, lista_normeEuclidiene):
    for i in range(len(lista_normeEuclidiene)):
        for j in range(i+1, len(lista_normeEuclidiene)):
            # Sortare crescatoare lista de norme euclidiene unde fiecare lista_normeEuclidiene[i]/[j] are corespondent pe mat[i]/[j]
            if lista_normeEuclidiene[i] > lista_normeEuclidiene[j]:
                aux = lista_normeEuclidiene[i]
                lista_normeEuclidiene[i] = lista_normeEuclidiene[j]
                lista_normeEuclidiene[j] = aux
                # Sortare crescatoare linii
                aux = mat[i]
                mat[i] = mat[j]
                mat[j] = aux
    return mat


mat = [[0, 2, 32], [0, 2, 16], [0, 2, 8], [0, 2, 4]]
print("Inainte: ")
print(mat)

lista_normeEuclidiene = creare_lista_normeEuclidiene(mat)
print(lista_normeEuclidiene)
mat = sortare_linii_dupa_normaEuclidiana(mat, lista_normeEuclidiene)

print()
print("Dupa: ")
print(mat)



