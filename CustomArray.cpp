#include "CustomArray.h"
#include <tuple>

using namespace std;

// Default constructor for custom array
numArray::numArray() {
	current_capacity = INITIAL_CAPACITY;
	num_items = 0;
	the_data = new int[INITIAL_CAPACITY];
}

// Reserves more memory for the function
void numArray::reserve(size_t new_capacity) {
	if (new_capacity > current_capacity) {
		if (new_capacity > 2 * current_capacity)
			current_capacity = new_capacity;
		else
			current_capacity *= 2;
		int* new_data = new int[current_capacity];
		for (size_t i = 0; i < num_items; i++)
			new_data[i] = the_data[i];
		delete[] the_data;
		the_data = new_data;
	}
}

// Overwriting subscripting operator
const int& numArray::operator[](size_t index) const {
	if (index < 0 || index >= num_items) {
		throw out_of_range("Index to operator[] is out of range");
	}
	return the_data[index];
}

int& numArray::operator[](size_t index) {
	if (index < 0 || index >= num_items) {
		throw out_of_range("Index to operator[] is out of range");
	}
	return the_data[index];
}

// delete an integer
void numArray::erase(size_t index) {
	if (index > num_items) {
		throw out_of_range("Index is out of range");
	}
	for (size_t i = index + 1; i < num_items; i++) {
		the_data[i - 1] = the_data[i];
	}
	num_items--;
}

// add an integer at the end of the list
void numArray::push_back(int the_value) {
	if (num_items == current_capacity) {
		reserve(2 * current_capacity);
	}

	the_data[num_items] = the_value;
	num_items++;
}

// check if an integer exist
int numArray::checkInt(int userInput) {
	for (int i = 0; i < num_items; i++) {
		if (userInput == the_data[i]) {
			return i;
		}
	}
	return -1;
}

// modify an integer with new value when provided with index
pair<int, int> numArray::modifyVal(size_t userIndex, int userNewInt) {
	if (userIndex < 0 || userIndex >= num_items) {
		throw out_of_range("Index is out of bounds");
	}

	int originalValue = the_data[userIndex];
	the_data[userIndex] = userNewInt;
	return make_pair(originalValue, userNewInt);
}

// getter 
 int numArray::getNumItem() {
	return num_items;
}

