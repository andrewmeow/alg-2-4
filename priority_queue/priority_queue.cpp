#include "priority_queue.h"
#include <iostream>
#include <locale>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "____________Priority_Queue_________\n";

    PriorityQueue<int> pq(3); // ������� ������������ ������� � ����� ������������
    pq.Push(5, 0); // ��������� ������� � ����������� 0
    pq.Push(2, 1); // ��������� ������� � ����������� 1
    pq.Push(7, 2); // ��������� ������� � ����������� 2
    pq.Push(1, 0); // ��������� ������� � ����������� 0

    while (!pq.IsEmpty()) {
        cout << "�������� ������� � ��������� �����������: " << pq.Pop() << std::endl;
    }
}
