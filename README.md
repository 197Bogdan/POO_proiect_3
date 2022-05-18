# POO_proiect_3

#### Proiectul implementeaza un template de Heap si un template de HeapFactory. Folosite impreuna, returneaza un heap de minim/maxim pentru orice tip de date care are definiti operatorii '<' si '>'.
### How to use: 
#### <pre> 1. Se instantiaza un pointer HeapFactory\<T>* factory (T fiind tipul de date dorit) folosind metoda statica HeapFactory\<T>::getInstance() </pre>
#### <pre> 2. Folosind pointerul factory se pot instantia heapuri goale de minim/maxim folosind metoda factory->createHeap(string tip_heap), unde tip_heap poate fi "max" sau "min". Metoda createHeap poate primi ca un al doilea parametru optional un vector din ale carui valori sa se creeze heapul.  </pre>
#### Nota: HeapFactory-ul respecta design pattern-urile de Factory si Singleton. Pentru un tip de date poate exista doar un HeapFactory. 
### Functionalitati:
#### Heapul are functionalitati de baza, precum: 
##### <pre>Insert(T value): insereaza valoarea in heap</pre>
##### <pre>Remove(): sterge si returneaza radacina</pre>
##### <pre>Peek(): returneaza radacina</pre>
##### <pre>heapSort(vector\<T> v&): pune in vectorul V valorile din heap in ordine sortata folosind heapSort</pre>
###### Exemplu de cod in main.cpp


 
