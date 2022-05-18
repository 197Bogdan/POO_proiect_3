#include <iostream>
#include <vector>
#include "heap.h"
#include "heapfactory.h"

using namespace std;

int main()
{

	HeapFactory<char>* char_factory = HeapFactory<char>::getInstance();
	HeapFactory<int>* int_factory = HeapFactory<int>::getInstance();
	HeapFactory<int>* int_factory2 = HeapFactory<int>::getInstance();		// incercam sa cream un al doilea HeapFactory<int>
	HeapFactory<string>* string_factory = HeapFactory<string>::getInstance();

	if (int_factory == int_factory2)
		cout << "Ambii pointeri au adresa singurului factory: " << int_factory << endl << endl;		// fiecare tip de HeapFactory este singleton
	else
		cout << "Exista 2 instante ale singletonului." << endl << endl;

    Heap<int>* heapmin_int = int_factory->createHeap("min");		// cream un heap de minim folosind metoda factory-ului, upcast automat
    heapmin_int->insert(100);
    heapmin_int->insert(30);
	heapmin_int->insert(10);
	heapmin_int->insert(15);
	heapmin_int->insert(5);
	heapmin_int->remove();		// scoatem radacina = 5
	heapmin_int->remove();		// scoatem radacina = 10
	heapmin_int->insert(50);
	heapmin_int->insert(40);
	std::vector<int> v;
	heapmin_int->heapSort(v);		// punem in v valorile din heap sortate folosind heapSort
	for (auto i : v)
		cout << i << " ";		// afisam v
	cout << endl << endl << endl;

	vector<string> strings = { "abcd", "LFA", "//{}", "! !", "02" };
	Heap<string>* heapmax_string = string_factory->createHeap("max", strings);		// cream un heap de max folosind direct un vector cu valori
	heapmax_string->heapSort(strings);
	for (auto i : strings)
		cout << i << " ";
	cout << endl << endl << endl;

	Heap<char>* heapmin_char = char_factory->createHeap("abcd");	// argument invalid, returneaza nullptr
	if (heapmin_char == nullptr)
		cout << "Este nullptr." << endl << endl;
	heapmin_char = char_factory->createHeap("min", { 'a', '2', 'P', '|', '~' });	// parametru vector constant
	vector<char> chars;
	heapmin_char->heapSort(chars);
	for (auto i : chars)
		cout << i << " ";
	cout << endl;

}
