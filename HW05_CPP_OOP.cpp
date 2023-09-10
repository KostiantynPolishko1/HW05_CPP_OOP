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

int sumTotal(int** const arr, const short& row, const short& col);
void sumRows(int** const arr, const short& row, const short& col);
void sumColumns(int** const arr, const short& row, const short& col);
void sumDiagonal(int** const arr, const short& row, const short& col);

void dataMatrix(int** const arr, const short& row, const short& col, const std::string rotation);

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

	dataMatrix(matrixR0, sizeRow, sizeCol, "0");

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
	int i = 1;
	for (int** iter = arr; iter != arr + row; iter++)
		for (int* jter = *iter; jter != *iter + col; jter++)
			//*jter = 1 + rand() % 11;
			*jter = i++;
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

int sumTotal(int** const arr, const short& row, const short& col) {
	int sum = 0;
	for (int** iter = arr; iter != arr + row; iter++)
		for (int* jter = *iter; jter != *iter + col; jter++)
			sum += *jter;

	return sum;
};

void sumRows(int** const arr, const short& row, const short& col) {

	for (int** iter = arr, i = 1; iter != arr + row; iter++)
	{
		int sumRow = 0;
		for (int* jter = *iter; jter != *iter + col; jter++) {
			sumRow += *jter;
		}
		cout << "\t\t" << "row" << i++ << " = " << sumRow << "\n";
	}
};

void sumColumns(int** const arr, const short& row, const short& col) {

	for (short i = 0; i < col; i++)
	{
		int sumCol = 0;
		for (short j = 0; j < row; j++)
			sumCol += arr[j][i];

		cout << "\t\t" << "col" << i+1 << " = " << sumCol << "\n";
	}
};

void sumDiagonal(int** const arr, const short& row, const short& col) {

	int sumMainD = 0, sumOppositeD = 0;

	for (short i = 0; i < row; i++)
		for (short j = 0; j < col; j++) {
			if (i == j)
				sumMainD += arr[i][j];
			if ((i + j) == (row - 1))
				sumOppositeD += arr[i][j];
		}

	cout << "\t\tmain\t= " << sumMainD << "\n";
	cout << "\t\toposite\t= " << sumOppositeD << "\n";
};

void dataMatrix(int** const matrix, const short& row, const short& col, const std::string rotation) {

	cout << "\n\tdata of matrix " << row << " x " << col << ", rotation " + rotation + " clockwise\n";

	cout << "\n\t1. Total = " << sumTotal(matrix, row, col) << "\n";
	cout << "\n\t2. sum by:\n"; sumRows(matrix, row, col);
	cout << "\n\t3. sum by:\n"; sumColumns(matrix, row, col);

	if(row == col)
	{
		cout << "\n\t4. sum by diagonal:\n";
		sumDiagonal(matrix, row, col);
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