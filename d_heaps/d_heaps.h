#include <iostream>
#include <vector>

template<typename T>
class DHeap {
private:
    std::vector<T> heap;
    int d;
    int parent(int i) {
        return (i - 1) / d;
    }

    // Возвращает индекс k-го потомка узла с индексом i
    int child(int i, int k) {
        return d * i + k + 1;
    }

    void ToUp(int i) {
        while (i > 0 && heap[i] > heap[parent(i)]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int maxChild(int i) {
        int max = i;
        for (int k = 0; k <= d; k++) {
            int c = child(i, k);
            if (c < heap.size() && heap[c] < heap[max])
                max = c;
        }
        return max;
    }

    void ToDown(int i) {
        int p = maxChild(i);
        while (p != 0 && heap[i] < heap[p]) {
            swap(heap[i], heap[p]);
            i = p;
            p = maxChild(i);
        }
    }
public:
    DHeap(int d) :d(d) {
        if (d < 2)
            throw "d должно быть больше 2";
    }

    void Insert(const T& value) {
        heap.push_back(value);
        ToUp(heap.size() - 1);
    }

    void Remove(const T& value) {
        int i;
        for (i = 0; i < heap.size(); i++)
            if (heap[i] == value)
                break;
        if (i == heap.size())
            throw "Элемент не найден";

        heap[i] = heap.back();
        heap.pop_back();

        if (i < heap.size()) {
            ToUp(i);
            ToDown(i);
        }

    }

    bool isEmpty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }

    void Print() const {
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << ' ';
        cout << "\n";
    }
};
