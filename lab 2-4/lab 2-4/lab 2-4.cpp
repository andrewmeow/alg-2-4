

#include <iostream>
#include "skip_list.h"
#include "d_heap.h"
#include "priority_queue.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "____________Skip_list_________\n";
    SkipList<int> list;
    list.Insert(3);
    list.Insert(6);
    list.Insert(7);
    list.Insert(9);
    list.Insert(12);
    list.Insert(19);
    list.Insert(17);
    list.Insert(26);
    list.Insert(21);
    list.Insert(25);

    cout << "Список:\n";
    list.Print();

    cout << "\nИщем 19: " << (list.Find(19) ? "Нашлось" : "Не нашлось") << endl;
    cout << "Ищем 15: " << (list.Find(15) ? "Нашлось" : "Не нашлось") << endl;

    list.Remove(19);
    cout << "\nСписок после удаления 19:\n";
    list.Print();

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

    cout << "____________Priority_Queue_________\n";

    PriorityQueue<int> pq(3); // Создаем приоритетную очередь с тремя приоритетами
    pq.Push(5, 0); // Добавляем элемент с приоритетом 0
    pq.Push(2, 1); // Добавляем элемент с приоритетом 1
    pq.Push(7, 2); // Добавляем элемент с приоритетом 2
    pq.Push(1, 0); // Добавляем элемент с приоритетом 0

    while (!pq.IsEmpty()) {
        std::cout << "Извлечен элемент с наивысшим приоритетом: " << pq.Pop() << std::endl;
    }
    return 0;
}
