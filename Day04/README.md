# Day 04

Začnemo z zapisom "skladišča" v vektor stringov (vrstic). Dodamo tudi "padding, (pike)" okoli celotnega skladišča da poenostavi zapis preverjanja.

## Naloga 1

Z for loop gremo čez vse pozicije v skladišču (izključujoče padding), če pristanemo na rolici papirja preštejemo koliko rolic je okoli, če je manj od 4 jo dodamo številu ki ga iščemo.

## Naloga 2

Naredimo isto le da če jo lahko dostopa jo odstranimo ('@'->'.'). Ponavljamo dokler se število pobranih ne spreminja več.