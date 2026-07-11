#include <iostream>

using namespace std;

enum enQuestionsLevel { Easy = 1, Medium = 2, Hard = 3, Mix = 4 };

enum enOperation { Addition = 1, Subtraction = 2, Multiplication = 3, Division = 4, MixOp = 5 };

struct stRoundElements
{
	short Number1;
	short Number2;
	char OpTypeSymbol;
	int ComputerResult;
};

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

char GetOperationTypeSymbol(enOperation OpType)
{
	switch (OpType)
	{
	case enOperation::Addition:
	{
		return '+';
		break;
	}
	case enOperation::Subtraction:
	{
		return '-';
		break;
	}
	case enOperation::Multiplication:
	{
		return '*';
		break;
	}
	case enOperation::Division:
	{
		return '/';
		break;
	}
	case enOperation::MixOp:
	{
		return GetOperationTypeSymbol((enOperation)GetRandomNumber(1, 4));
		break;
	}
	default:
	{
		cout << "\nNothing here! Go back )-: |...| :-(\n";
	}
	}
}

void DisplayRoundResult(stRoundElements Round, int UserAnswer)
{
	if (UserAnswer == Round.ComputerResult)
	{
		cout << "\nCorrect Answer :-)\n";
		system("A0");
	}
	else
	{
		cout << "\nWrong Answer :-(\a\n";
		cout << "The right answer is " << Round.ComputerResult << endl;
		system("color 47");
	}
}

int GetComputerResult(short Number1, short Number2, char OpTypeSymbol)
{
	switch (OpTypeSymbol)
	{
	case enOperation::Addition:
		return (Number1 + Number2);
	case enOperation::Subtraction:
		return (Number1 - Number2);
	case enOperation::Multiplication:
		return (Number1 * Number2);
	case enOperation::Division:
		return (Number1 / Number2);
	default:
		return (Number1 + Number2);
	}
}

stRoundElements GenerateRoundElements(enQuestionsLevel QuestionLevel, enOperation OpType)
{
	stRoundElements Round;

	Round.Number1 = GetRandomNumberAccordingToLevel(QuestionLevel);
	Round.Number2 = GetRandomNumberAccordingToLevel(QuestionLevel);
	Round.OpTypeSymbol = GetOperationTypeSymbol(OpType);
	Round.ComputerResult = GetComputerResult(Round.Number1, Round.Number2, Round.OpTypeSymbol);

	return Round;
}

void DisplayRound(short RoundNumber, short NumberOfRounds, enQuestionsLevel QuestionLevel, enOperation OpType)
{
	stRoundElements Round = GenerateRoundElements(QuestionLevel, OpType);
	int UserAnswer;

	cout << "Round [" << RoundNumber << "/" << NumberOfRounds << "]\n\n";
	cout << Round.Number1 << endl;
	cout << Round.Number2 << "   " << Round.OpTypeSymbol << endl;
	cout << "------------------------\n";
	cin >> UserAnswer;

	DisplayRoundResult(Round, UserAnswer);
}

void GenerateRounds(short NumberOfRounds, enQuestionsLevel QuestionLevel, enOperation OpType)
{
	for (short RoundNumber = 1; RoundNumber <= NumberOfRounds; RoundNumber++)
	{
		DisplayRound(RoundNumber, NumberOfRounds, QuestionLevel, OpType);
	}
}

int main()
{	
	srand((unsigned)time(NULL));
	
	return 0;
}