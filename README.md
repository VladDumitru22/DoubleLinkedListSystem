Acest repository conține un program C care implementează o listă dublu înlănțuită pentru manipularea unei secvențe de cuvinte.
Lista permite adăugarea, afișarea și ștergerea elementelor atât de la începutul cât și de la sfârșitul listei, precum și manipularea acesteia pe baza unor comenzi.

Caracteristici principale:

Structura de date:
Lista dublu înlănțuită (Double Linked List) care permite accesul și manipularea eficientă a elementelor atât dinspre început, cât și dinspre sfârșit, datorită legăturii bidirecționale (fiecare nod are un pointer către nodul anterior și un pointer către nodul următor).

Operațiuni disponibile:

Adăugare elemente:

addNodeBeginning(): Adaugă un nod la începutul listei.
addNodeFinal(): Adaugă un nod la sfârșitul listei.
addNodeIndex(): Adaugă un nod într-o poziție specifică a listei, dată fiind o valoare de index.

Ștergere elemente:

deleteFirst(): Șterge primul nod al listei.
deleteLast(): Șterge ultimul nod al listei.
deleteList(): Șterge întreaga listă.

Afișare:

display(): Afișează lista de la început la sfârșit.
invertedDisplay(): Afișează lista de la sfârșit la început.

Funcții de alocare și eliberare memorie:

Memoria pentru fiecare nod (atât pentru cuvânt, cât și pentru structura de nod) este alocată dinamic, iar la ștergerea nodurilor, memoria este eliberată corespunzător.

Intrare și Ieșire:

Intrare:

Comenzile sunt citite ca un număr întreg (int command), fiecare comandă corespunde unei operațiuni asupra listei.
Utilizatorul poate introduce următoarele comenzi:
1: Afișează lista de la început la sfârșit.
2: Afișează lista de la sfârșit la început.
3: Adaugă un nod la începutul listei.
4: Adaugă un nod la sfârșitul listei.
5: Adaugă un nod într-o poziție specifică, bazată pe un index dat.
6: Șterge primul nod al listei.
7: Șterge ultimul nod al listei.
8: Șterge întreaga listă.
9: Ieșire din program.

Ieșire:

Programul va afișa conținutul listei (de la început la sfârșit sau invers) în funcție de comanda introdusă.
În cazul adăugării sau ștergerii unui nod, va fi actualizată lista respectivă.

Tipuri de date:

word: Cuvântul stocat într-un nod este reprezentat ca un șir de caractere (maxim 30 de caractere).
next și prev: Pointeri care indică nodurile vecine din listă, atât anterior cât și următor.
