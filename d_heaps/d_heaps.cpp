#include "d_heaps.h"
#include <iostream>
#include <locale>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "____________D_Heap_________\n";
    DHeap<int> heap(3); // Создаем 3-кучу

    heap.Insert(10);
    heap.Insert(4);
    heap.Insert(9);
    heap.Insert(1);
    heap.Insert(7);
    heap.Insert(5);
    heap.Insert(3);

    cout << "Куча:\n";
    heap.Print();

    heap.Remove(5);

    cout << "Куча после удаления 5: ";
    heap.Print();
    cout << endl;

}