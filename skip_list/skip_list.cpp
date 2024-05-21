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

    cout << "Список:\n";
    list.Print();

    cout << "\nИщем 19: " << (list.Find(19) ? "Нашлось" : "Не нашлось") << endl;
    cout << "Ищем 15: " << (list.Find(15) ? "Нашлось" : "Не нашлось") << endl;

    list.Remove(19);
    cout << "\nСписок после удаления 19:\n";
    list.Print();

}