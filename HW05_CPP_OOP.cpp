#include <iostream>

int checkV(int a);

int main(void)
{
	using std::cout;
	using std::cin;
    cout << "Start!\n";

	cout << checkV(0) << "\n";

	return 0;
}

int checkV(int a)
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