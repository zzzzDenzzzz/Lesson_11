#include<iostream>

int enterNumber()
{
	int number;
	std::cout << "Enter number: ";
	std::cin >> number;
	return number;
}

void printResult(int result)
{
	std::cout << "result = " << result << std::endl;
}

int sum(int a, int b)
{
	if (a == b)
	{
		return b;
	}
	return a + sum(a + 1, b);
}

int main()
{
	int a = enterNumber();
	int b = enterNumber();
	int result = sum(a, b);
	printResult(result);

	return 0;
}