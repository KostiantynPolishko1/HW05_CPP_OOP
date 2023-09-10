#include <iostream>

const short	MIN_SIZE = 1;
const short	MAX_SIZE = 10;

int inputValue(int a);

short inputSize(std::string text);

int main(void)
{
	using std::cout;
	using std::cin;
    cout << "Start!\n";

	short sizeRow = 0, sizeCol = 0;
	
	sizeRow = inputSize("rows");
	sizeCol = inputSize("columns");

	cout << "\n\tmatrix size " << sizeRow << " x " << sizeCol << "\n";

	return 0;
}

int inputValue(int a)
{
	while (true) // the cycle continues until the user enters the correct value
	{
		std::cout << "\tenter -> ";
		std::cin >> a;
		if (std::cin.peek() != '\n') // if the previous extraction was unsuccessful,
		{
			std::cout << "\t\tINPUT ERROR!\n";
			std::cin.clear(); // then return the cin to 'normal' mode of operation
			std::cin.ignore(32767, '\n'); // and remove the previous input values from the input buffer
			continue;
		}
		
		std::cin.ignore(32767, '\n'); //if all is well, return a and remove the previous input values from the input buffer
		system("CLS");

		return abs(a);
	}

}

short inputSize(std::string text) {

	while (true) 
	{
		short size = 0;

		std::cout << "\tnumber of " + text + " (" << MIN_SIZE << "..." << MAX_SIZE << ")\n";
		size = inputValue(size);
		if (size <= 10 && size >= 1)
			return size;

		system("CLS");
		std::cout << "\tOUT of RANGE. ERROR!\n";
	};
};