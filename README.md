# PRISTOP K REŠEVANJU NALOG AoC25




## Day 02

 ### Naloga 1

 Za prvo možnost vzamemo prvo polovico začetka območja (če je to mogoče) in prištevamo po ena dokler ne presežemo končne vrednosti območja.

 ### Naloga 2

 Proviramo vse dolžine ponavljanja (teh je: start/2) in proviramo če so na danem bmočju (med start in end), zapišemo jih v unordered set, ker želimo neponavljajoče, nakoncu jih seštejemo.

 Ker pa napisana funkcija deluje le če sta začetek in konec enako dolga v main razdelimo neveljavna območja na dva dela npr 67-115 -> 67-99 in 100 ->115.

 ## Day 03 

 ### Naloga 1

Najdemo maksimalno vrednost od začetka do predzadnjega, zatem najdemo še od prejšnje najdene do konca. Števke združimo spremenimo v int in prištevamo končnemu rezultatu.

### Naloga 2

Podobno kot pri prvi le da začnemo iskanje do 11 predzadnje števke in potem od najdene do 10 predzadnje itd. do konca.
 
 ## Naloga 4

Začnemo z zapisom "skladišča" v vektor stringov (vrstic). Dodamo tudi "padding, (pike)" okoli celotnega skladišča da poenostavi zapis preverjanja.

### Naloga 1

Z for loop gremo čez vse pozicije v skladišču (izključujoče padding), če pristanemo na rolici papirja preštejemo koliko rolic je okoli, če je manj od 4 jo dodamo številu ki ga iščemo.

### Naloga 2

Naredimo isto le da če jo lahko dostopa jo odstranimo ('@'->'.'). Ponavljamo dokler se število pobranih ne spreminja več.