#include <iostream>
#include <thread>
#include <chrono>

int resultMat[4] = {};
int firstMat[4] = { 1,2,3,4 };
int secondMat[4] = { 5,6,7,8 };

void printArray()
{
	for (int i = 0; i < 4; i++) {
		printf("%i ", resultMat[i]);
	}
	printf("\n");
}

void calculateSecondPart()
{
	for (int i = 2; i < 4; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		resultMat[i] = firstMat[i] * secondMat[i];
		printf("Second part calculation\t");
		printArray();
	}
}

int main()
{


	std::thread th1(calculateSecondPart);
	for (int i = 0; i < 2; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		resultMat[i] = firstMat[i] * secondMat[i];
		printf("First part calculation\t");
		printArray();
	}

	th1.join();
	printf("Joined result\t");
	printArray();

	return 0;

}