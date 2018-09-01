#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool sim(bool, int);

int main()
{
	srand(time(NULL));
	
	cout << "Enter number of doors to check: ";
	int totalDoors; 
	cin >> totalDoors;
	int totalLoops;
	cout << "Enter number of loops to test for: ";
	cin >> totalLoops;

	//int totalLoops = 1000;
	//int totalDoors = 3;
	int totalSuccess = 0;
	float percentSuccess = 0;
	cout << "Calculating chance of success with " << totalDoors << " doors over " <<  totalLoops << " loops while staying: " << endl;

	for (int i = 0; i < totalLoops; i++)
	{
		if (sim(0, totalDoors))
			totalSuccess++;
	}

	cout << "Total success:" << totalSuccess << endl;
	if(totalSuccess != 0)
		percentSuccess = (float)totalSuccess / (float)totalLoops;
	cout << "Percent success: " << percentSuccess << endl;

	totalSuccess = 0;
	cout << "Calculating chance of success with " << totalDoors << " doors over " << totalLoops << " loops while switching: " << endl;

	for (int i = 0; i < totalLoops; i++)
	{
		if (sim(1, totalDoors))
			totalSuccess++;
	}

	cout << "Total success:" << totalSuccess << endl;
	if (totalSuccess != 0)
		percentSuccess = (float)totalSuccess / (float)totalLoops;
	cout << "Percent success: " << percentSuccess << endl;

	system("pause");
}

// setting false = stay, true = switch
bool sim(bool setting, int numDoors)
{
	bool *doors = new bool[numDoors];

	int goodDoor = rand() % numDoors;
	doors[goodDoor] = true;
	for (int i = 0; i < numDoors; i++)
	{
		if (i != goodDoor)
		{
			doors[i] = false;
		}
	}

	int selection = rand() % numDoors;
	int altDoor = goodDoor;
	
	if (selection == goodDoor)
	{
		while (altDoor == goodDoor)
		{
			altDoor = rand() % numDoors;
		}
	}

	if (setting)
	{
		selection = altDoor;
	} 

	bool retValue = doors[selection];

	delete doors;
	return retValue;
}