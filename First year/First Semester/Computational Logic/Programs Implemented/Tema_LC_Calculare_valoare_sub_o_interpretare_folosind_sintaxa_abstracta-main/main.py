print("-"*160)

def convert_str_to_lst(p):
    return [char for char in p if char != ' ']


def replace_operators(prop):
    for i in range(len(prop)):
        if prop[i] == '~':
            prop[i] = '⇒'
        elif prop[i] == '/':
            prop[i] = '∨'
        elif prop[i] == '=':
            prop[i] = '⇔'
        elif prop[i] == '&' or prop[i] == '^':
            prop[i] = '∧'

    return prop


def get_atoms(prop):
    interpreters = {}
    for i in prop:
        if 'A' <= i <= 'Z':
            if i not in interpreters:
                interpreters[i] = "null"

    return interpreters


def receive_interpretations(atomi):
    print()
    for i in sorted(atomi):
        print("Interpretarea lui", i, "este: ", end='')
        atomi[i] = int(input())
    print()

    return atomi


def replace_atoms_with_interpretations(prop, atomi):
    for i in range(len(prop)):
        if prop[i] in atomi:
            prop[i] = atomi[prop[i]]

    return prop


prop = input("Introduceti sintaxa abstracta data de programul ce returneaza sub forma de lista formula propozitionala: ")
prop = prop.split()


p = input("Introduceti formula propozitionala originala: ")
p = convert_str_to_lst(p)


prop = replace_operators(prop)


p = replace_operators(p)
p = ''.join(p)


atomi = get_atoms(prop)
atomi = receive_interpretations(atomi)


prop = replace_atoms_with_interpretations(prop, atomi)


# print(prop) # - debug

rez = "null"

for i in range(len(prop)-1, -1, -1):
    # Warning approach
    if prop[i] == '!':
        prop[i+1] = int(not(prop[i+1]))
        rez = prop[i+1]
        for j in range(i, len(prop)):
            if prop[i] != 0 or prop[i] != 1:
                prop[i] = '*'
        # print(prop)# - debug


    elif prop[i] in ['⇒','∨','⇔','∧']:
        if prop[i] == '∧':
            a, b = '*', '*'
            for j in range(i+1, len(prop)):
                if prop[j] == 1 or prop[j] == 0:
                    if a == '*':
                        a = prop[j]
                        prop[j] = '*'
                        continue
                    else:
                        b = prop[j]
                        prop[j] = '*'
                        break
            # print(a, b)# - debug
            prop[i] = int(int(a) and int(b))
            rez = prop[i]
            # print(prop)# - debug


        elif prop[i] == '⇔':
            a, b = '*', '*'
            for j in range(i+1, len(prop)):
                if prop[j] == 0 or prop[j] == 1:
                    if a == '*':
                        a = prop[j]
                        prop[j] = '*'
                        continue

                    else:
                        b = prop[j]
                        prop[j] = '*'
                        break
            # print(a,b)# - debug
            prop[i] = int(a == b)
            rez = prop[i]
            # print(prop)# - debug


        elif prop[i] == '⇒':
            a, b = '*', '*'
            for j in range(i+1, len(prop)):
                if prop[j] == 1 or prop[j] == 0:
                    if a == '*':
                        a = prop[j]
                        prop[j] = '*'
                        continue
                    else:
                        b = prop[j]
                        prop[j] = '*'
                        break
            # print(a,b)# - debug
            prop[i] = int(not(a) or b)
            rez = prop[i]
            # print(prop)# - debug


        if prop[i] == '∨':
            a, b = '*', '*'
            for j in range(i+1, len(prop)):
                if prop[j] == 1 or prop[j] == 0:
                    if a == '*':
                        a = prop[j]
                        prop[j] = '*'
                        continue
                    else:
                        b = prop[j]
                        prop[j] = '*'
                        break
            # print(a,b)# - debug
            prop[i] = int(a or b)
            rez = prop[i]
            # print(prop)# - debug


# print(prop)# - debug
print()
print("Valoarea propozitiei", p, "sub intepretarea I₀:", [atomi[x] for x in atomi], "este", rez, '(', 'True' if rez == 1 else 'False', ')')
print("-"*160)

