# PRISTOP K REŠEVANJU NALOG AoC25




## Day 02

 ### naloga 1

 Za prvo možnost vzamemo prvo polovico začetka območja (če je to mogoče) in prištevamo po ena dokler ne presežemo končne vrednosti območja.

 ### naloga 2

 Proviramo vse dolžine ponavljanja (teh je: start/2) in proviramo če so na danem bmočju (med start in end), zapišemo jih v unordered set, ker želimo neponavljajoče, nakoncu jih seštejemo.

 Ker pa napisana funkcija deluje le če sta začetek in konec enako dolga v main razdelimo neveljavna območja na dva dela npr 67-115 -> 67-99 in 100 ->115.

 