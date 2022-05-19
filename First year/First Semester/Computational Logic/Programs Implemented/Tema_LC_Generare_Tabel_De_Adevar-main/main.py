print("-"*160)
s = []

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


def replace_atoms_with_interpretations(prop, atomi, truth_values):
    j = 0
    ordered = [key for key in atomi]
    ordered.sort()
    for key in ordered:
        for i in range(len(prop)):
            if prop[i] in atomi and prop[i] == key and atomi[prop[i]] == "null":
                s.append([prop[i], '=', truth_values[j]])
                # print(prop[i], '=', truth_values[j])
                prop[i] = truth_values[j]

        j += 1

    return prop


def base2(num):
    l = []
    while num:
        l.append(num % 2)
        num //= 2

    l.reverse()

    return l

def generate_all_permutations(n):
    lst = []
    for i in range(n):
        if i == 0:
            lst.append([0])
        else:
            lst.append(base2(i))

    return lst

def convert_into_n_bits(lst, n):
    for list in lst:
        if len(list) < n:
            ind = n - len(list) - 1
            while ind >= 0:
                list.insert(0, 0)
                ind -= 1

    return lst


prop = input("Introduceti sintaxa abstracta data de programul ce returneaza sub forma de lista formula propozitionala: ")
prop = prop.split()


p = input("Introduceti formula propozitionala originala: ")
p = convert_str_to_lst(p)


prop = replace_operators(prop)


p = replace_operators(p)
p = ''.join(p)


atomi = get_atoms(prop)

num_atomi = len(atomi)
lst = generate_all_permutations(2**num_atomi)

# print(lst)

lst = convert_into_n_bits(lst, num_atomi)

# print(lst)

# print(prop) # - debug

copy = prop[:]
print()


for i in range(len(lst)):
    truth_values = lst[i]
    prop = replace_atoms_with_interpretations(prop, atomi,lst[i])
    # print(prop)  # - debug

    rez = "null"

    for i in range(len(prop)-1, -1, -1):
        # Warning approach
        if prop[i] == '!':
            prop[i + 1] = int(not (prop[i + 1]))
            rez = prop[i + 1]
            for j in range(i, len(prop)):
                if prop[i] != 0 or prop[i] != 1:
                    prop[i] = '*'
            # print(prop)# - debug


        elif prop[i] in ['⇒', '∨', '⇔', '∧']:
            if prop[i] == '∧':
                a, b = '*', '*'
                for j in range(i + 1, len(prop)):
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
                for j in range(i + 1, len(prop)):
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
                for j in range(i + 1, len(prop)):
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
                prop[i] = int(not (a) or b)
                rez = prop[i]
                # print(prop)# - debug

            if prop[i] == '∨':
                a, b = '*', '*'
                for j in range(i + 1, len(prop)):
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

    a = s[0]
    print(a)
    for i in range(1, len(s)):
        if s[i] != a:
            print(s[i])
            a = s[i]
    s.clear()

    print("Valoarea propozitiei", p, "sub intepretarea I:", truth_values, "este", rez, '(','True' if rez == 1 else 'False', ')')

    prop = copy[:]
    print()


# # print(prop)# - debug
print()
print("-"*160)
