#### Acest progra ia ca argument o propozitie si retuneaza sintaxa abstracta a acesteia folosind arborii binari

#### Ultima actualizare: 13.12.2021


#### [ REPOZITORIU ]

  Github

#### [ CUM SE RULEAZA CODUL ]

Programul se va descarca inainte apasand pe butonul verde "Code" si selectand "Downlad as ZIP" sau se poate copia direct codul sursa, din fisierul **main.py** intr-un IDE(cum ar fi **Visual Studio 2019**) sau editor de text(cum ar fi **Visual Studio Code**; in cazul acesta, va fi nevoie instalarea de extensii ce permit rularea de cod C++).

#### Cerinte ale input-ului

In analiza propozitiei nu trebuie sa existe spatii intre elemente, de asemena, vor trebui folosite conventii pentru conectorii logici, deoarece encoding-ul din C++ nu recunoaste simboluri de tip unicode.
  
  ##### Conventii din cauza codifiarii in C++ a caracterelor
     ! e negatie
     / e disjunctie
     ~ e implicatie
     = e echivalenta
     &, ^, * sunt conjunctii

 *Nefolosirea conventiilor duce la eroare*

#### [ EXEMPLE ]

      (((P⇔Q)∨S)⇒T) devine (((P=Q)/S)~T)
      ((P⇔Q)∧((¬Q)∧(¬P))) devine ((P=Q)&((!Q)&(!P)))
      ((P⇔Q)∨((¬Q)∨P)) devine ((P=Q)/((!Q)/P))
      
   ![Screenshot 2021-12-18 184416](https://user-images.githubusercontent.com/92999481/146649043-75d01c9c-7004-4bc8-936b-fb05f8552b36.png)
   ![2](https://user-images.githubusercontent.com/92999481/146649142-ac6d1c03-a1ee-4cc8-992d-01a389660d69.png)
   ![3](https://user-images.githubusercontent.com/92999481/146649159-3724df66-dad4-414c-b079-fdc6cbdc0252.png)


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

[ Rusu Emanuel ]

Grupa 1, subgrupa 2

Facultatea de Matematica - Informatica, anul I

Prof: Adrian Craciun

Prof. seminar: Alexandra Fortis
