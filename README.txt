READ ME TEMA PA:

STUDENT: VACULENCO M. MAXIM
GRUPA: 314AA

Pentru inceput, am alocat variabilele, am deschis si verificat ca s-au deschis fisierele, am citit vectorul de cerinte folosit pentru checker, precum si nr de echipe.

Dupa care, am inceput sa ramific problema in if-uri per cerinta. Pentru prima cerinta, am apelat intr-un for o functie mare, cea de citire a echipelor, precum si cea de adaugare
la inceputul listei.

Pentru cerinta doi, gaseam numarul de echipe de scos din lista conform cerintei printr-o functie, dupa care prin alta functie aflam la fiecare pas minimul actual de scor din toata lista 
de echipe, si scoteam prima echipa din lista cu acel scor, si tot asa cat timp numarul de echipe de scos este diferit de 0. Si pentru a imi usura munca pentru urmatoarele cerinte, 
am actualizat si numarul de echipe.

Pentru cerinta trei, am alocat tot ce am avut nevoie, am creat coada de meciuri, stivele, am dat enQueue la toate meciurile pe care le si cream din mers; 
Am inceput sa rezolv cerinta propriu-zis, si anume in primul for dadeam deQueue la meciuri din coada, simulam meciurile efectiv, si dadeam push in stive echipelor; 
Dupa care, am inceput un while nr echipelor (pe care il tot actualizam) este diferit de 1, tot dadeam pop la echipe si maream punctajele, dadeam enQueue la meciurile create din mers, 
dupa care iar deQueue si simulam meciurile, punand in stiva toate cele;
ramaneam in while, afisand constant cele necesare, iar cand ieseam afisam corespunzator si echipa castigatoare dupa ce ii dadeam pop.