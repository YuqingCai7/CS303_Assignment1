#pragma once
#include <stdexcept>

using namespace std;

struct integerNumbers {
	int originalVal;
	int userVal;
};

// custom array class
class numArray {
private:
	static const size_t INITIAL_CAPACITY = 10;
	size_t current_capacity;
	size_t num_items;
	int* the_data;
public:
	numArray();
	void push_back(int the_value);
	void reserve(size_t new_capacity);
	int& operator[](size_t index);
	int getNumItem();
	const int& operator[] (size_t index) const;
	void erase(size_t index);
	int checkInt(int userInput);
	pair<int, int> modifyVal(size_t userIndex, int userNewInt);
};

