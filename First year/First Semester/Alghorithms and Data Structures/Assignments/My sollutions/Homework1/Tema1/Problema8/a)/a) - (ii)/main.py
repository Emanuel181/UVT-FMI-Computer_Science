def decompresie(str):
    dcmp = []

    for i in range(len(str) - 1):
        if 'a' <= str[i] <= 'z' and str[i + 1].isnumeric() == True:
            aux = str[i] * int(str[i + 1])
            dcmp.append(aux)

        elif 'a' <= str[i] <= 'z' and str[i + 1].isnumeric() == False:
            dcmp.append(str[i])

    return dcmp


print()
print("Introduceti sirul compresat: ", end='')
str = input()
str = decompresie(str)
print()
print()
print("Sirul decompresat este: ", end='')
for c in str:
    print(c, end='')
print()



