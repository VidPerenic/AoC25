# Day 07

Uporabimo map (za drugo nalogo, za prvo bi lahko samo set), key je lokacija žarka (indeks v vrstici ki jo beremo) in vrednost je število možnosti da pridemo v ta žarek (za drugo nalogo) 

Uporabljamo bfs način prehoda skozi graf.
Najprej najdemo kje je 'S' in tam zapišemo 1. Vsako drugo vrsto preskočimo ker so same pike. Če v prebrani vrsti najdemo spliter, ki ima nad sabo žarek, ga splitamo na naslednji način:

- Na točki levo in desno prištejemo vrednost v dani točki (število možnosti za priti v dani žarek), če žarka na sosednjih točkah ni se samo prepiše vrednost na dva nova žarka, če žarek že obstaja je skupnih možnosti za priti v tisti žarek seštevek dosedanjih možnosti. (Boljše obrazloženo na skici).
- Točko v kateri smo izbrišemo (ker se je splitala) in povečamo števec 1 za 1.

![Shema algoritma](image.png)

## Naloga 2

Da dobimo vse možnosti do vseh končnih žarkov moramo vse možnosti do posameznih žarkov sešteti.

