#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

template<typename T>
class SkipList {
private:

	struct TNode {
		TNode** next;
		T value;
		TNode(const T& value_, int lvl) : value(value_) {
			next = new TNode * [lvl + 1];
			for (int i = 0; i <= lvl; i++)
				next[i] = nullptr;
		}
		~TNode() { delete[] next; }

	};

	int maxLvl;
	TNode* head;
	int currLvl;

	int randLvl() {
		int lvl = 0;
		while (lvl < maxLvl && rand() % 2 == 0)
			lvl++;
		return lvl;
	}

public:
	SkipList() : maxLvl(10), currLvl(0) {
		head = new TNode(T(), maxLvl); srand(static_cast<unsigned>(time(nullptr)));
	}
	~SkipList() {}

	void Insert(const T& value)
	{
		TNode* curr = head;
		TNode** tmp = new TNode * [maxLvl + 1];
		for (int i = currLvl; i >= 0; i--)
		{
			while (curr->next[i] != nullptr && curr->next[i]->value < value)
				curr = curr->next[i];
			tmp[i] = curr;
		}

		int lvl = randLvl();
		if (lvl > currLvl)
		{
			for (int i = currLvl + 1; i <= lvl; i++)
				tmp[i] = head;
			currLvl = lvl;
		}
		TNode* newTNode = new TNode(value, lvl);
		for (int i = 0; i <= lvl; i++)
		{
			newTNode->next[i] = tmp[i]->next[i];
			tmp[i]->next[i] = newTNode;
		}
	}

	bool Find(const T& value) {

		TNode* curr = head;
		for (int i = currLvl; i >= 0; i--) {
			while (curr->next[i] != nullptr && curr->next[i]->value < value)
			{
				curr = curr->next[i];
			}
		}
		curr = curr->next[0];
		return curr != nullptr && curr->value == value;
	}

	void Remove(const T& value) {
		TNode* curr = head;
		TNode** tmp = new TNode * [maxLvl + 1];

		for (int i = currLvl; i >= 0; i--)
		{
			while (curr->next[i] != nullptr && curr->next[i]->value < value)
				curr = curr->next[i];
			tmp[i] = curr;
		}

		curr = curr->next[0];
		if (curr != nullptr && curr->value == value)
		{
			for (int i = 0; i <= currLvl; i++) {
				if (tmp[i]->next[i] != curr)
					break;
				tmp[i]->next[i] = curr->next[i];
			}

			delete curr;
			while (currLvl > 0 && head->next[currLvl] == nullptr)
				currLvl--;
		}
	}

	void Print() const {
		for (int i = currLvl; i >= 0; --i) {
			TNode* node = head->next[i];
			std::cout << "Level " << i << ": ";
			while (node != nullptr) {
				std::cout << node->value << " ";
				node = node->next[i];
			}
			std::cout << std::endl;
		}
	}

};
