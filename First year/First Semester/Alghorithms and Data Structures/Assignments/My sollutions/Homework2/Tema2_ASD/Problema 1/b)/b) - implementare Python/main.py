def cauta_elemente_comune(arr1, arr2):
    tabl_comun = []

    for i in range(len(arr1)):
        for j in range(len(arr2)):
            if arr1[i] == arr2[j]:
                tabl_comun.append(arr1[i])

    return tabl_comun

def cauta_element_comun(arr1, arr2):
    for i in range(len(arr1)):
        for j in range(len(arr2)):
            if arr1[i] == arr2[j]:
                return True


a = [3, 1, 5, 10]
b = [4, 2, 6, 1]
c = [5, 3, 1, 7]


tabl_comun = cauta_elemente_comune(a, b)
print(cauta_element_comun(tabl_comun, c))

