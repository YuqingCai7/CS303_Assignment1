#include <iostream>
#include <fstream>
#include <string>
#include "CustomArray.h"

using namespace std;


int main()
{
	// Create a custom array named array1
	numArray array1;    


	// Read the file and provide error handling if unable to open the file
	ifstream inputFile;
	inputFile.open("A1input.txt");
	if (!inputFile.is_open()) {
		cout << "Error opening the file!" << endl;
		return 1;
	}

	// Push the integer read from the file into the array
	int temp;
	while (!inputFile.eof()) {
		inputFile >> temp;
		array1.push_back(temp);
	}

	// Testing the array if uploaded correctly
	//for (int i = 0; i < array1.getNumItem(); i++) {
	//	cout << array1[i] << " ";
	//	if ((i + 1) % 10 == 0) {
	//		cout << endl;
	//	}
	//}

	// Display main menu 
	cout << "Please use the following command to initialize a desireable function: " << endl << endl;
	cout << "[C] - Check if a specific number exists in the array and return the index of the number" << endl;
	cout << "[M] - Modify an existing number and return both the original and new number" << endl;
	cout << "[A] - Add a new number to the end of the array" << endl;
	cout << "[E] - Erase an existing number from the array" << endl;
	cout << "[Q] - Exit the program" << endl << endl;


	// Ask the user to enter command 
	string userInput;
	cout << "Enter command here: ";
	getline(cin, userInput);
	
	// Validate user input
	try {
		userInput = toupper(userInput.at(0));

		while (userInput != "Q") {
			if (userInput == "C") {
				cout << "Please enter the number you wish to check: ";
				int userInput;
				cin >> userInput;
				int index = array1.checkInt(userInput);
				if (index != -1) {
					cout << "The number you entered is found at index: " << index << endl << endl;
				}
				else {
					cout << "The number you entered is not found." << endl << endl;
				}
			}

			else if (userInput == "M") {
				try {
					cout << "Please enter the index of number you wish to modify: ";
					int userMInput;
					if (!(cin >> userMInput)) {
						throw invalid_argument("Please enter a valid integer.");
					}
					if (userMInput < 0 || userMInput >= array1.getNumItem()) {
						throw out_of_range("Index out of bounds");
					}
					cout << "Please enter a new replacement number: ";
					int newNum;
					if (!(cin >> newNum)) {
						throw invalid_argument("Invalid input. Please enter a valid integer.");
					}

					pair<int, int> numResult = array1.modifyVal(userMInput, newNum);
					cout << "The original number " << numResult.first << " has been replaced with " << numResult.second << endl << endl;
				}
				catch (const exception& e) {
					cerr << "Error: " << e.what() << endl << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if (userInput == "A") {
				try {
					cout << "Please enter the number you wish to add: ";
					int userInputAdd;

					if (!(cin >> userInputAdd)) {
						throw invalid_argument("Please enter a valid integer.");
					}
					array1.push_back(userInputAdd);
					cout << "The number has been added to the list." << endl << endl;
				}
				catch (const exception& e) {
					cerr << "Error: " << e.what() << endl << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			else if (userInput == "E") {
				cout << "Please enter the index of the number you wish to erase: ";
				int userInputDel;
				cin >> userInputDel;
				array1.erase(userInputDel);
				cout << "The number has been erased from the list." << endl << endl;
			}

			else {
				throw invalid_argument("Please enter 'C', 'M', 'A', 'E', or 'Q'");
			}

			cout << "Enter command here: ";
			cin >> userInput;
			userInput = toupper(userInput.at(0));
		}

		cout << "Thank you for using my program!" << endl << endl;
	}

	// Error handling
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	// Close the file
	inputFile.close();
	return 0;
}

