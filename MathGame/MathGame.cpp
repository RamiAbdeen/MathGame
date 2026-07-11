#include <iostream>

using namespace std;

enum enQuestionsLevel { Easy = 1, Medium = 2, Hard = 3, Mix = 4 };

enum enOperation { Addition = 1, Subtraction = 2, Multiplication = 3, Division = 4, MixOp = 5 };

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

enQuestionsLevel ReadQuestionLevel()
{
	short QuestionLevel;

	do
	{
		cout << "Select the game level: [1] Easy, [2] Medium, [3] Hard, [4] Mix\n";
		cin >> QuestionLevel;
	} while (QuestionLevel < 1 || QuestionLevel > 4);

	return (enQuestionsLevel)QuestionLevel;
}

enOperation ReadOperationType()
{
	short OperationType;

	do
	{
		cout << "Select the operation type: [1] Addition, [2] Subtraction, [3] Multiplication, [4] Division, [5] MixOp\n";
		cin >> OperationType;
	} while (OperationType < 1 || OperationType > 5);

	return (enOperation)OperationType;
}

short GetRandomNumber(short From, short To)
{
	short RandomNumber = rand() % (To - From + 1) + From;

	return RandomNumber;
}

short GetRandomNumberAccordingToLevel(enQuestionsLevel QuestionLevel)
{
	switch (QuestionLevel)
	{
	case enQuestionsLevel::Easy:
	{
		return GetRandomNumber(1, 10);
		break;
	}
	case enQuestionsLevel::Medium:
	{
		return GetRandomNumber(10, 50);
		break;
	}
	case enQuestionsLevel::Hard:
	{
		return GetRandomNumber(50, 100);
		break;
	}
	case enQuestionsLevel::Mix:
	{
		return GetRandomNumber(1, 100);
		break;
	}
	default:
	{
		cout << "\nNothing here! Go back )-: |...| :-(\n";
	}
	}
}

void DisplayRoundScreen(short RoundNumber, short NumberOfRounds)
{
	int YourAnswer;

	cout << "Round [" << RoundNumber << "/" << NumberOfRounds << "]\n\n";
	cout << GetRandomNumberAccordingToLevel() << endl;
	cout << GetRandomNumberAccordingToLevel() << "   " << OperationType() << endl;
	cout << "------------------------\n";
	cin >> YourAnswer;

	DisplayRoundResult();
}

int main()
{	
	srand((unsigned)time(NULL));
	
	return 0;
}