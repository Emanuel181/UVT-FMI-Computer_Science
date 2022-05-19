def swap(date, i, j):
    aux = date[i]
    date[i] = date[j]
    date[j]= aux

    return date


def sortare_date(date):
    for i in range(len(date)-1):
        for j in range(i+1, len(date)):
            if date[i][2] > date[j][2]:
                date = swap(date, i, j)
            elif date[i][1] > date[j][1] and date[i][2] == date[j][2]:
                date = swap(date, i, j)
            elif date[i][0] > date[j][0] and date[i][2] == date[j][2] and date[i][1] == date[j][1]:
                date = swap(date, i, j)

    return date


date = [(27, 3, 2004), (28, 10, 1990), (27, 3, 2004), (12, 5, 2012), (12, 6, 2012), (13, 5, 2012), (23, 12, 2018), (22, 12, 2018), (14, 9, 2020), (15, 9, 2021)]

print()
print("Inainte: ", end = ' ')
print(date)
print()

date = sortare_date(date)

print("Dupa: ", end = ' ')
print(date)
print()