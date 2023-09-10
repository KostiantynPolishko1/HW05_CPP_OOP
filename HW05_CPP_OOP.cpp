#include <iostream>
#include <ctime>

using std::cout;
using std::cin;

const short	MIN_SIZE = 2;
const short	MAX_SIZE = 10;

int inputValue(int a);

short inputSize(std::string text);

void fillMatrix(int** const arr, const short& row, const short& col);

void rotateMatrix90(int** const arr, const short& row, const short& col);

void printMatrix(int** const arr, const short& row, const short& col);

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

	cout << "\n\tmatrix " << sizeRow << " x " << sizeCol << ", rotation 0\n\n";
	fillMatrix(matrixR0, sizeRow, sizeCol);
	printMatrix(matrixR0, sizeRow, sizeCol);

	std::swap(sizeRow, sizeCol);
	cout << "\n\tmatrix " << sizeRow << " x " << sizeCol << ", rotation 90 clockwise\n\n";

	int** matrixR90 = new int* [sizeRow];
	for (int** iter = matrixR90; iter != matrixR90 + sizeRow; iter++)
		*iter = new int[sizeCol];

	//printMatrix(matrixR90, sizeRow, sizeCol);
	for (short i = 0; i < sizeRow; i++)
		for (short j = 0; j < sizeCol; j++)
			matrixR90[i][j] = matrixR0[(sizeCol - 1) - j][i];

	rotateMatrix90(matrixR90, sizeRow, sizeCol);
	printMatrix(matrixR90, sizeRow, sizeCol);
	
	clearMatrix(matrixR90, sizeRow);
	
	std::swap(sizeRow, sizeCol);
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

	int ind = 1;
	for (int** iter = arr; iter != arr + row; iter++)
		for (int* jter = *iter; jter != *iter + col; jter++)
			//*jter = 10 + rand() % 51;
			*jter = ind++;
};

void rotateMatrix90(int** const arr, const short& row, const short& col) {

	int** arrTemp = new int* [row];
	for (int** iter = arrTemp; iter != arrTemp + row; iter++)
		*iter = new int [col];

	for (int** iter = arr; iter != arr + row; iter++)
		for (int* jter = *iter; jter != *iter + col; jter++)
			;
};

void printMatrix(int** const arr, const short& row, const short& col) {

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