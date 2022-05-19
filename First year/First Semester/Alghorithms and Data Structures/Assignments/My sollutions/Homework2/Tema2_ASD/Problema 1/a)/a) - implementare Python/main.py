def cautare_element_comun(arr1, arr2, arr3):
    for i in range(len(arr1)):
        for j in range(len(arr2)):
            for k in range(len(arr3)):
                if arr1[i] == arr2[j] and arr3[k] == arr1[i]:
                    return True


a = [3, 1, 5, 10]
b = [4, 2, 6, 1]
c = [5, 2, 1, 7]

print(cautare_element_comun(a, b, c))
