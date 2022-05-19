def citeste(binar):
    inp = input()

    for i in inp.split():
        binar.append(int(i))

    return binar


def conv_din_complement(binar):
    for i in range(len(binar)):
        if binar[i] == 1:
            binar[i] = 0
        else:
            binar[i] = 1

    return binar

def aduna_1(binar):
    transport = 0
    for i in range(len(binar) - 1, -1, -1):
        if binar[i] == 1 and i == len(binar) - 1:
            binar[i] = 0
            transport = 1

        elif binar[i] == 1:
            binar[i] = (binar[i] + transport) % 2
            if binar[i] == 0:
                transport = 1
            else:
                transport = 0

        else:
            binar[i] = binar[i] + transport
            transport = 0

    return binar

def converteste_zecimal(binar):
    zecimal = 0
    binar.reverse()
    for i in range(len(binar)):
        if binar[i] == 1:
            zecimal += 2**i

    return zecimal




print("Introduceti reprezentarea binara: ", end = '')
print()

binar = []
binar = citeste(binar)

if binar[0] == 1:
    binar = conv_din_complement(binar)
    binar = aduna_1(binar)
    print("Numarul reprezentat de lista ce continea complementul fata de 2 al acestuia este: ", -1 * converteste_zecimal(binar))

elif binar[0] == 0:
    print("Lista contine numarul in binar, dupa convertire acesta este: ", converteste_zecimal(binar))

else:
    print("Se asteapta o lista doar cu 0 sau 1")
    print("Input neacceptat")
    print()