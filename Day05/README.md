# Day 05

Začeno z zapisom vseh danih območij v vektor parov, jih uredimo po velikosti začetne vrednosti območij. Nato naredimo nov vektor parov območij ki se ne prekrivajo (merged). To storimo z naslednjim algoritmom: Prvo območje prepišemo, če se naslednje območje prekriva ampak ne celo (začetek naslednjega < konec merged) zapišemo nov konec. Če se ne prekrivajo ga dodamo kot novo območje.

## Naloga 1

Če je podan id v katerem od (merged) območij prištejemo števec.

## Naloga 2

Vsi Id ki so še sveži je seštevek velikosti (merged)območij.
