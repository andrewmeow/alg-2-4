#include "priority_queue.h"
#include <iostream>
#include <locale>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "____________Priority_Queue_________\n";

    PriorityQueue<int> pq(3); // Создаем приоритетную очередь с тремя приоритетами
    pq.Push(5, 0); // Добавляем элемент с приоритетом 0
    pq.Push(2, 1); // Добавляем элемент с приоритетом 1
    pq.Push(7, 2); // Добавляем элемент с приоритетом 2
    pq.Push(1, 0); // Добавляем элемент с приоритетом 0

    while (!pq.IsEmpty()) {
        cout << "Извлечен элемент с наивысшим приоритетом: " << pq.Pop() << std::endl;
    }
}
