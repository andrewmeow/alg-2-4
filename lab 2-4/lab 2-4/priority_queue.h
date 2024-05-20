#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class PriorityQueue {
private:
	vector<vector<T>> m;

public:
	PriorityQueue(int maxPriority) :m(maxPriority){}


	T Pop() {
		for (auto& q : m) {
			if (!q.empty()) {
				T value = q.front();
				q.erase(q.begin());
				return value;
			}
		}
		throw "Очередь пуста";
	}


	void Push(const T& value, int pr) {
		if (pr > m.size())
			throw "Нет такого приоритета";

		m[pr].push_back(value);
	}

	bool IsEmpty()
	{
		for (auto& q : m) {
			if (!q.empty())
				return false;
		}
		return true;
	}
};

