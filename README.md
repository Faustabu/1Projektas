# v1.0
 * Pima strategjia : studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "nuskriaustukų" ir "galvočių". 
 * Papildžiau programą antra strategija: nuskriaustukus įkeliu į naująjį "nuskriaustukų" konteinerį ir ištrintu iš bendro studentai konteinerio.
 1000 ir 10000 -su failais kur visi pazymiai
 kiti failai imti be pazymiu, tik su galutiniu, nes kitaip nuskaitant neuzteko atminties.
|studentu skaiciai|1 000|10 000|100 000|1 000 000| 10 000 000|
|--------------|-----------|---------|----------|----------|-----------|
|nuskaitymas su list| 0.040967 |4.093822 | 0.034434 | 0.312733 | 3.035935 |
|nuskaitymas su vector| 0.040504 | 4098021 | 0.022091 | 0.204266 | neuzteko atminties|
|nuskaitymas su deque| 0.041334 | 4.182744 | 0.021439 | 0.194491 | neuzteko atminties |
|rusiavimas su list 1str| 0.001913 | 0.160919 | 0.022107 | 0.214453 | neuzteko atminties |
|rusiavimas su list 2str| 0.002161 | 0.227877 | 0.032493 | 0.321754 | neuzteko atminties |
|rusiavimas su vector 1str| 0.002902 | 0.197460 | 0.013347 | 0.116763 | neuzteko atminties|
|rusiavimas su vector 2str| 0.002050 | 0.244130 | 0.015099 | 0.130109 | neuzteko atminties|
|rusiavimas su deque 1str| 0.002769 | 0.308236 | 0.017595 | 0.160189 | neuzteko atminties|
|rusiavimas su deque 2str| 0.002871 | 0.314141 | 0.013697 | 0.130628 | neuzteko atminties|

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
