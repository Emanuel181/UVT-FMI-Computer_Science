print("Sintaxa ce se va analiza este: ", end='')
caz = input()

if caz == "stricta":

    print("Introduceti expresia ce va fi verificata: ", end='')

    prop, cnt_c, cnt_p, poz, conectori = input(), 0, 0, 0, ['∧', '∨', '⇒', '¬', '⇔']

    def  remove_spaces(exp):
        return "".join(exp.split())

    prop = remove_spaces(prop)

    print()

    for i in prop:
        if (i in conectori or i == ')') and poz == 0:
            print("Conectorii sau paranteza inchisa nu poate sa apara pe prima pozitie. Nu, expresia nu este o propozitie bine definita.")
            exit()

        if i in conectori and (i != '¬' and poz <= 1):
            print("Un conector binar apare cel mai devreme pe pozitia 3. Nu, expresia nu este o propozitie bine definita.")
            exit()

        elif i in conectori:
            cnt_c += 1

        if i == '(' or i == ')':
            if i == ')' and poz == 0:
                print("O propozitie bine definita nu poate sa inceapa cu o paranteza care se inchide. Nu, expresia nu este o propozitie bine definita.")
                exit()
            else:
                cnt_p += 1
        poz += 1

    for i in range(len(prop)):
        if prop[i] == '(':
            print("POZITIA[", i, ']:', prop[i])
            print("Propozitia vrea sa fie una complexa, ma astept la o paranteza, o negatie sau o propozitie atomica.")
            if prop[i + 1] == '(' or (prop[i + 1] == '¬' or 'A' <= prop[i + 1] <= 'Z'):
                continue
            else:
                print("Pe pozitia", i, "se afla o paranteza, iar pe pozitia urmatoare se astepta o negatie, o paranteza deschisa sau o propozitie atomica, dar nu e prezenta niciuna. Nu, expresia nu este o propozitie bine definita.")
                exit()

        if prop[i] == '¬':
            print("POZITIA[", i, ']:', prop[i])
            print("Am un conector binar, ma astept la o propozitie atomica sau la o paranteza deschisa.")
            if 'A' <= prop[i + 1] <= 'Z' or prop[i + 1] == '(':
                continue
            else:
                print("Pe pozitia", i, "se afla o negatie iar pe pozitia urmatoare se asteapta o propozitie atomica sau o paranteza deschisa, dar nu e prezenta niciuna. Nu, expresia nu este o propozitie bine definita.")
                exit()

        if 'A' <= prop[i] <= 'Z' and prop[i - 1] not in conectori:
            print("POZITIA[", i, ']:', prop[i])
            print("Am o propozitie atomica care nu e precedata de un conector, ma astept la un conector.")
            if prop[i + 1] in conectori:
                continue
            else:
                print("Pe pozitia", i, "se afla o propozitie atomica, iar pe urmatoarea pozitie se asteapta obligatoriu un conector, dar nu e prezent. Nu, expresia nu este o propozitie bine definita.")
                exit()

        if 'A' <= prop[i] <= 'Z' and prop[i - 1] in conectori:
            print("POZITIA[", i, ']:', prop[i])
            print("Am o propozitie atomica care e precedata de un conector, ma astept la o paranteza inchisa.")
            if prop[i + 1] == ')':
                continue
            else:
                print("Pe pozitia", i, "se afla o propozitie atomica ce este precedata de un conector, iar pe urmatoarea pozitie se asteapta obligatoriu o paranteza, dar nu e prezenta niciuna. Nu, expresia nu este o propozitie bine definita.")
                exit()

        if prop[i] in conectori:
            print("POZITIA[", i, ']:', prop[i])
            print("Am un conector, ma astept la o paranteza deschisa sau la o propozitie atomica.")
            if prop[i + 1] == '(' or 'A' <= prop[i + 1] <= 'Z':
                continue
            else:
                print("Pe pozitia", i, "se afla un conector, iar pe urmatoarea pozitie se asteapta fie o paranteza deschisa, fie o propozitie atomica, dar nu e prezenta niciuna. Nu, expresia nu este o propozitie bine definita.")
                exit()

        if prop[i] == ')':
            print("POZITIA[", i, ']:', prop[i])
            print("Pe pozitia", i, "se afla o paranteza inchisa, deci acum s-a inchis o expresie complexa")
            continue

    if cnt_p - 2*cnt_c != 0:
        print()
        print("Numarul de perechi  de paranteze nu corespunde cu numarul de conectori. Nu, expresia nu este o propozitie bine definita.")
        if cnt_p % 2 == 0:
            rez = cnt_p // 2
        else:
            rez = cnt_p / 2
        print("Sunt", cnt_c, "conectori si", rez, "perechi de paranteze.")
        exit()

    elif i == len(prop) - 1:
            print()
            print("Da, expresia este o propozitie bine definita.")
            print(cnt_p - 2*cnt_c)
            exit()

    else:
        print("Propozitia reprezinta un caz nou ce trebuie analizat, iar programul trebuie actualizat")
        exit()

if caz == "relaxata":
    print("Va urma...")
