#include<iostream>

void theEndOfTheWorld(int gold_disk, char diamond_rod_A, char diamond_rod_B, char diamond_rod_C)
{
	if (gold_disk == 0)
	{
		return;
	}
	else if (gold_disk == 1)
	{
		theEndOfTheWorld(gold_disk - 1, diamond_rod_A, diamond_rod_B, diamond_rod_C);
		std::cout << diamond_rod_A << "=>" << diamond_rod_C << std::endl;
	}
	else
	{
		theEndOfTheWorld(gold_disk - 1, diamond_rod_A, diamond_rod_C, diamond_rod_B);
		std::cout << diamond_rod_A << "=>" << diamond_rod_C << std::endl;
		theEndOfTheWorld(gold_disk - 1, diamond_rod_B, diamond_rod_A, diamond_rod_C);
	}
}

int main()
{
	int gold_disk = 4;
	const char DIAMOND_ROD_A = 'A';
	const char DIAMOND_ROD_B = 'B';
	const char DIAMOND_ROD_C = 'C';

	theEndOfTheWorld(gold_disk, DIAMOND_ROD_A, DIAMOND_ROD_B, DIAMOND_ROD_C);

	return 0;
}