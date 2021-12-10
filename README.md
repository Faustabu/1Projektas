# v1.0
 * Pima strategjia : studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "nuskriaustukų" ir "galvočių". 
 * Papildžiau programą antra strategija: nuskriaustukus įkeliu į naująjį "nuskriaustukų" konteinerį ir ištrintu iš bendro studentai konteinerio.
 
|studentu skaiciai|1 000|10 000|100 000|1 000 000| 10 000 000|
|--------------|-----------|---------|----------|----------|-----------|
|nuskaitymas su list| 0.013672 |0.040806 | 0.154455 | 0.962242 | 27.757485|
|nuskaitymas su vector| 0.001546 | 0.015253 | 0.147996 | 0.936603 | neuzteko atminties|
|nuskaitymas su deque| 0.001484 | 0.014485 | 0.0144205 | 0.887862 | 1.851611 |
|rusiavimas su list 1str| 0.000247 | 0.001444 | 0.012052 | 0.109947 | 2.056703 |
|rusiavimas su list 2str| 0.000050 | 0.000588 | 0.005369 | 0.077133 | 1.934070 |
|rusiavimas su vector 1str| 0.000122 | 0.000866 | 0.011518 | 0.161209 | neuzteko atminties|
|rusiavimas su vector 2str| 0.0001930 | 0.206431 | 23.760108 | 3141.168301 | neuzteko atminties|
|rusiavimas su deque 1str| 0.000136 | 0.001292 | 0.017167 | 0.170332 | neuzteko atminties|
|rusiavimas su deque 2str| 0.000731 | 0.071838 | 7.624660 | -- | neuzteko atminties|

### Naudojimosi CmakeList instrukcija:
### Building
Standart build using cmake.
On windows with nmake:
```
cmake -G "NMake Makefiles" .
nmake
```
 
### Running
type `Stud`
