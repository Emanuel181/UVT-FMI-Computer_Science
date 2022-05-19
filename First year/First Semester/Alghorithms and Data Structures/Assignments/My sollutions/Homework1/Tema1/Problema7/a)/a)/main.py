def citire_arr(arr):
    arr = input()
    arr = arr.split()
    for i in range(len(arr)):
        arr[i] = int(arr[i])

    return arr


def cauta(arr, v):
    i = len(arr) - 1
    while i >= 0 and v < arr[i]:
        i -= 1

    return i+1

print("Scrieti elementele listei: ", end = '')
arr = []
arr = citire_arr(arr)
print()
print("Introduceti valoarea lui <v>: ", end = '')
v = int(input())
print()
print("Pozitia lui", v, "in sirul crescator este: ", cauta(arr,v))
