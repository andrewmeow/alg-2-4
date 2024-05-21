#include "skip_list.h"
#include <iostream>
#include <locale>
using namespace std;
int main() {
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

    cout << "������:\n";
    list.Print();

    cout << "\n���� 19: " << (list.Find(19) ? "�������" : "�� �������") << endl;
    cout << "���� 15: " << (list.Find(15) ? "�������" : "�� �������") << endl;

    list.Remove(19);
    cout << "\n������ ����� �������� 19:\n";
    list.Print();

}