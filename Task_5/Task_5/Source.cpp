#include<iostream>
#include<stdlib.h>
#include<time.h>
#define STEP 2

void initArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		array[i] = 10 + rand() % 90;
	}
}

void printArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int foo(int array[], int length, int start_position = 0, int step = STEP)
{
	int index_min;
	int sum_min;
	int sum_1;
	int sum_2;
	int i, j, k;

	for (i = 0; i < length - (step - 1); i++)
	{
		for (j = start_position; j < (start_position + step) && j <= length - 1; j++)
		{
			if (j == start_position)
			{
				sum_1 = 0;
			}
			sum_1 += array[j];
			if (j - start_position == step - 1)
			{
				std::cout << "sum_1 = " << sum_1 << std::endl;
				if (i > 0)
				{
					sum_min = (sum_1 <= sum_min) ? sum_1 : sum_min;
					index_min = (sum_1 <= sum_min) ? (j - step + 1) : index_min;
					std::cout << "index min = " << index_min << std::endl;
				}
			}
		}

		start_position++;

		for (k = start_position; k < (start_position + step) && j <= length - 1; k++)
		{
			if (k == start_position)
			{
				sum_2 = 0;
			}
			sum_2 += array[k];
			if (k - start_position == step - 1)
			{
				std::cout << "sum_2 = " << sum_2 << std::endl;
				if (i > 0)
				{
					sum_min = (sum_2 <= sum_min) ? sum_2 : sum_min;
					index_min = (sum_2 <= sum_min) ? (k - step + 1) : index_min;
					std::cout << "index min = " << index_min << std::endl;
				}
			}
		}

		start_position++;

		if (i == 0)
		{
			index_min = (sum_1 <= sum_2) ? (j - step) : (k - step);
			sum_min = (sum_1 <= sum_2) ? sum_1 : sum_2;
			std::cout << "index min = " << index_min << std::endl;
		}
	}
	return index_min;
}

int main()
{
	srand((unsigned int)time(NULL));

	const int LENGTH = 20;
	int array[LENGTH];
	initArray(array, LENGTH);
	printArray(array, LENGTH);

	int index_min = foo(array, LENGTH);
	std::cout << "index min = " << index_min << std::endl;

	return 0;
}