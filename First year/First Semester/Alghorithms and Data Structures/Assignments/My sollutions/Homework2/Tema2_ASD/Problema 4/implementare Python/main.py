def cauta(mat, i, j, val, m):

    while i != m and j != -1:
        if val == mat[i][j]:
            return True

        elif val < mat[i][j]:
            j -= 1

        elif val > mat[i][j]:
            i += 1

    return False



mat = [[3,6,10],[5,9,12],[11,14,16]]

# Linii
m = 3

# Coloane
n = 3

#           matricea      i      j     val    liniile
print(cauta(mat,          0,    n-1,    14,       m))



