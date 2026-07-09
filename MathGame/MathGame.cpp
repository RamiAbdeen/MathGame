#include <iostream>

using namespace std;

short ReadNumberOfRounds()
{
	short NumberOfRounds;

	do
	{
		cout << "How many rounds do you want to play? ";
		cin >> NumberOfRounds;
	} while (NumberOfRounds < 0);

	return NumberOfRounds;
}

int main()
{
	
	return 0;
}