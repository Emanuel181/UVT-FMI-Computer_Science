def comprimare(str):
    cmp = []
    j = 0
    i = 0
    while i < len(str):
        if str[i] == str[i+1]:
            cnt = 1
            j = i + 1
            while j < len(str) and str[j] == str[i]:
                cnt += 1
                j += 1

            cmp.append(str[i])
            cmp.append(cnt)

            i = j - 1

        else:
            cmp.append(str[i])
        i += 1

    return cmp

print("Introduceti sirul: ", end = '')
str = input()
print()
print("Sirul comprimat este: ", end = '')
str = comprimare(str)
for i in str:
    print(i, end = '')

print()
