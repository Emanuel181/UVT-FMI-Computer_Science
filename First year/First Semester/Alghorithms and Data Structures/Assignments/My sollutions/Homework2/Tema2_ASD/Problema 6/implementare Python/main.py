def determina_subset(d, v, n, c):
    s = []
    for i in range(n):
        if c - d[i] >= 0:
            s.append(v[i])
            c -= d[i]

    return s


# input: numarul de elemente ale set-ului de valori si de dimensiuni
n = 6

# input: set-ul de dimensiuni unde d1 < d2 < d3 < ... < dn
d = [2.5, 3.2, 4.8, 5.0, 6.3, 8.9]

# input: set-ul de valori unde v1 > v2 > v3 > ... > vn
v = [10, 8, 7, 5, 3, 2]

# input: capacitatea rucsacului
c = 10.5

print(determina_subset(d, v, n, c))