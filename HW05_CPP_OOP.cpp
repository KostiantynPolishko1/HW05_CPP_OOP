#include <iostream>
#include <ctime>

using std::cout;
using std::cin;

const short	MIN_SIZE = 2;
const short	MAX_SIZE = 10;

int inputValue(int a);

short inputSize(std::string text);

void fillMatrix(int** const arr, const short& row, const short& col);

void rotateMatrix90(int** const arr, short row, short col);

void printMatrix(int** const arr, const short& row, const short& col, const std::string rotation);

void clearMatrix(int** const arr, const short& row);

int main(void)
{
    cout << "Start!\n";

	srand(time(NULL));
	rand();

	short sizeRow = 0, sizeCol = 0;
	
	sizeRow = inputSize("rows");
	sizeCol = inputSize("columns");

	int** matrixR0 = new int* [sizeRow];
	for (short i = 0; i < sizeRow; i++)
		*(matrixR0 + i) = new int[sizeCol];

	fillMatrix(matrixR0, sizeRow, sizeCol);
	printMatrix(matrixR0, sizeRow, sizeCol, "0");

	rotateMatrix90(matrixR0, sizeRow, sizeCol);
	
	clearMatrix(matrixR0, sizeRow);

	return 0;
}

int inputValue(int a)
{
	while (true)
	{
		cout << "\tenter -> ";
		cin >> a;
		if (cin.peek() != '\n')
		{
			cout << "\t\tINPUT ERROR!\n";
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}
		
		cin.ignore(32767, '\n');
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
			*jter = 1 + rand() % 11;
};

void rotateMatrix90(int** const arr, short row, short col) {

	std::swap(row, col);

	int** matrixR90 = new int* [row];
	for (int** iter = matrixR90; iter != matrixR90 + row; iter++)
		*iter = new int[col];

	for (int** iter90 = matrixR90, **iter0 = arr, i = 0; iter90 != matrixR90 + row; iter90++, i++)
	{
		for (int* jter90 = *iter90, *jter0 = *iter0, j = 0; jter90 != *iter90 + col; jter90++, j++) {
			iter0 = arr + ((col - 1) - j);
			jter0 = *iter0 + i;
			*jter90 = *jter0;
		}
	}

	printMatrix(matrixR90, row, col, "90");
	clearMatrix(matrixR90, row);
};

void printMatrix(int** const arr, const short& row, const short& col, const std::string rotation) {

	cout << "\n\tmatrix " << row << " x " << col << ", rotation " + rotation + " clockwise\n\n";

	for (int** iter = arr; iter != arr + row; iter++) {
		cout << "\t";
		for (int* jter = *iter; jter != *iter + col; jter++)
			cout << *jter << " ";
		cout << "\n";
	}
};

void clearMatrix(int** arr, const short& row) {

	for (int** iter = arr; iter != arr + row; iter++) {
		delete[] * iter;
		*iter = nullptr;
	}
	delete[] arr;
	arr = nullptr;
};