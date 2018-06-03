# MIPSASM

#### Opis:
Uproszczony asembler dla architektury MIPS, pokazujący jak działają ostatnie etapy kompilacji dla języków wyższego poziomu. 
Kodowanie instrukcji jest zgodne z MIPS ISA. Porządek bajtów jest określony według konwencji Big Endian. Program wczytuje instrukcje ze standardowego wejścia i zwraca kodowanie na standardowe wyjście.

#### Obsługuje:
 - instrukcje dotyczące przenoszenia danych
 - instrukcje porównania
 - instrukcje arytmetyczne i logiczne (intrukcje typu R i I)
 
#### Kompilacja:
Za pomocą przygotowanego Makefile: </br>
`make`

#### Testowanie:
Za pomocą przygotowanego skryptu `./tester.sh` lub przekazanie pliku z folderu tests/in na wejście programu : </br>
`./mipsasm < ./tests/in/test1a.in`