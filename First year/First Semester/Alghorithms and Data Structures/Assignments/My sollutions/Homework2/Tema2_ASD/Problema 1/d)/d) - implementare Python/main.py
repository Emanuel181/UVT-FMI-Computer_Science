def interclasare_elemente_comune(arr1, arr2):
    tabl_comun = []

    i = j = 0

    while i < len(arr1) and j < len(arr2):
        if arr1[i] == arr2[j]:
            tabl_comun.append(arr1[i])
            i+= 1
            j += 1

        elif arr1[i] < arr2[j]:
            i += 1

        elif arr2[j] < arr1[i]:
            j += 1

    return tabl_comun


def aflare_element_comun(arr1, arr2):
    i = j = 0

    while i < len(arr1) and j < len(arr2):
        if arr1[i] == arr2[j]:
            return True

        elif arr1[i] < arr2[j]:
            i += 1

        elif arr2[j] < arr1[i]:
            j += 1

    return False


a = [1, 3, 5, 10]
b = [1, 2, 4, 6]
c = [1, 3, 5, 7]

tabl_comun = interclasare_elemente_comune(a, b)

print(aflare_element_comun(tabl_comun, c))

