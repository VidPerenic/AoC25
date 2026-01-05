# Day 01

Preberemo po vrstici, če gre v desno prištevamo če gre v levo pa odštevamo. ko prištejemo (v desno), števcu naloge 2 prištejemo poz / 100 (tolikorat smo šli čez).

Pri premiku v levo števcu prištejemo (100 - poz + rot) / 100. Ker je pri prehodu  čez nič veliko edge casov raje prezrcalimo čez 50 (100 - poz) in prištevamo rotacijo, dobljeno številko delimo 100 da dobimo kolikorat smo šli čez 0. Pri tem načinu je še vedno problem, če smo na 0 in gremo v negativno še enkrat prišteje, da smo šli čez. Da to rešimo, odštejemo eno če smo na 0.

Doblejno pozicijo mapiramo na območje 0-100 z enačbo poz = (100 + poz % 100) % 100 

Če smo na 0 prištejemo števcu 1.
