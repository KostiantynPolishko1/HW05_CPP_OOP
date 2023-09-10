#include <iostream>
#include <ctime>

using std::cout;
using std::cin;

const short	MIN_SIZE = 1;
const short	MAX_SIZE = 10;

int inputValue(int a);
short inputSize(std::string text);
void fillMatrix(int** const arr, const short& row, const short& col);
void printMatrix(int** const arr, const short& row, const short& col);
void clearMatrix(int** const arr, const short& row, const short& col);

int main(void)
{
    cout << "Start!\n";

	srand(time(NULL));
	rand();

	short sizeRow = 0, sizeCol = 0;
	
	sizeRow = inputSize("rows");
	sizeCol = inputSize("columns");

	int** arrMatrix = new int* [sizeRow];
	for (short i = 0; i < sizeRow; i++)
		*(arrMatrix + i) = new int[sizeCol];

	fillMatrix(arrMatrix, sizeRow, sizeCol);

	cout << "\n\tmatrix size " << sizeRow << " x " << sizeCol << "\n\n";
	printMatrix(arrMatrix, sizeRow, sizeCol);

	clearMatrix(arrMatrix, sizeRow, sizeCol);

	/*for (int** iter = arrMatrix; iter != arrMatrix + sizeRow; iter++) {
		delete[] *iter;
		*iter = nullptr;
	}
	delete[] arrMatrix;
	arrMatrix = nullptr;*/

	return 0;
}

int inputValue(int a)
{
	while (true) // the cycle continues until the user enters the correct value
	{
		cout << "\tenter -> ";
		cin >> a;
		if (cin.peek() != '\n') // if the previous extraction was unsuccessful,
		{
			cout << "\t\tINPUT ERROR!\n";
			cin.clear(); // then return the cin to 'normal' mode of operation
			cin.ignore(32767, '\n'); // and remove the previous input values from the input buffer
			continue;
		}
		
		cin.ignore(32767, '\n'); //if all is well, return a and remove the previous input values from the input buffer
		system("CLS");

		return abs(a);
	}
}

short inputSize(std::string text) {

	while (true) 
	{
		short size = 0;

		cout << "\n\tnumber of " + text + " (" << MIN_SIZE << "..." << MAX_SIZE << ")\n";
		size = inputValue(size);
		if (size <= MAX_SIZE && size >= MIN_SIZE)
			return size;

		system("CLS");
		cout << "\tOUT of RANGE. ERROR!\n";
	};
};

void fillMatrix(int** const arr, const short& row, const short& col) {

	for (int** iter = arr; iter != arr + row; iter++)
		for (int* jter = *iter; jter != *iter + col; jter++)
			*jter = 10 + rand() % 51;
};

void printMatrix(int** const arr, const short& row, const short& col) {

	for (int** iter = arr; iter != arr + row; iter++) {
		cout << "\t";
		for (int* jter = *iter; jter != *iter + col; jter++)
			cout << *jter << " ";
		cout << "\n";
	}
};

void clearMatrix(int** arr, const short& row, const short& col) {

	for (int** iter = arr; iter != arr + row; iter++) {
		delete[] * iter;
		*iter = nullptr;
	}
	delete[] arr;
	arr = nullptr;
};