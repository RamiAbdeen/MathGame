#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum enQuestionsLevel { Easy = 1, Medium = 2, Hard = 3, Mix = 4 };

enum enOperation { Addition = 1, Subtraction = 2, Multiplication = 3, Division = 4, MixOp = 5 };

struct stRoundElements
{
	short Number1;
	short Number2;
	char OpTypeSymbol;
	int ComputerResult;
	int UserAnswer;
};

struct stRoundsCharacteristics
{
	short NumberOfRounds;
	enQuestionsLevel QuestionLevel;
	enOperation OpType;
	short Wins = 0;
	short Loses = 0;
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
	}
	case enQuestionsLevel::Medium:
	{
		return GetRandomNumber(10, 50);
	}
	case enQuestionsLevel::Hard:
	{
		return GetRandomNumber(50, 100);
	}
	case enQuestionsLevel::Mix:
	{
		return GetRandomNumber(1, 100);
	}
	default:
	{
		return GetRandomNumber(1, 10);
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
	}
	case enOperation::Subtraction:
	{
		return '-';
	}
	case enOperation::Multiplication:
	{
		return '*';
	}
	case enOperation::Division:
	{
		return '/';
	}
	case enOperation::MixOp:
	{
		return GetOperationTypeSymbol((enOperation)GetRandomNumber(1, 4));
	}
	default:
	{
		return '+';
	}
	}
}

void DisplayRoundResult(stRoundElements Round)
{
	if (Round.UserAnswer == Round.ComputerResult)
	{
		cout << "\nCorrect Answer :-)\n";
		system("color A0");
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
	case '+':
		return (Number1 + Number2);
	case '-':
		return (Number1 - Number2);
	case '*':
		return (Number1 * Number2);
	case '/':
		return (Number1 / Number2);
	default:
		return (Number1 + Number2);
	}
}

stRoundElements GenerateRoundElements(stRoundsCharacteristics Rounds)
{
	stRoundElements Round;

	Round.Number1 = GetRandomNumberAccordingToLevel(Rounds.QuestionLevel);
	Round.Number2 = GetRandomNumberAccordingToLevel(Rounds.QuestionLevel);
	Round.OpTypeSymbol = GetOperationTypeSymbol(Rounds.OpType);
	Round.ComputerResult = GetComputerResult(Round.Number1, Round.Number2, Round.OpTypeSymbol);

	return Round;
}

void CountResults(stRoundsCharacteristics& Rounds, stRoundElements Round)
{
	if (Round.UserAnswer == Round.ComputerResult)
		Rounds.Wins++;
	else
		Rounds.Loses++;
}

void DisplayRound(short RoundNumber, stRoundsCharacteristics& Rounds)
{
	stRoundElements Round = GenerateRoundElements(Rounds);

	cout << "Round [" << RoundNumber << "/" << Rounds.NumberOfRounds << "]\n\n";
	cout << Round.Number1 << endl;
	cout << Round.Number2 << "   " << Round.OpTypeSymbol << endl;
	cout << "------------------------\n";
	cin >> Round.UserAnswer;

	DisplayRoundResult(Round);
	CountResults(Rounds, Round);
}

void GenerateRounds(stRoundsCharacteristics& Rounds)
{
	for (short RoundNumber = 1; RoundNumber <= Rounds.NumberOfRounds; RoundNumber++)
	{
		system("cls");
		system("color 07");
		DisplayRound(RoundNumber, Rounds);
		system("pause");
	}
}

string QuestionLevelString(enQuestionsLevel QuestionLevel)
{
	switch (QuestionLevel)
	{
	case enQuestionsLevel::Easy:
		return "Easy";
	case enQuestionsLevel::Medium:
		return "Medium";
	case enQuestionsLevel::Hard:
		return "Hard";
	case enQuestionsLevel::Mix:
		return "Mix";
	default:
		return "Easy";
	}
}

string OpTypeString(enOperation Optype)
{
	switch (Optype)
	{
	case enOperation::Addition:
		return "Addition";
	case enOperation::Subtraction:
		return "Subtraction";
	case enOperation::Multiplication:
		return "Multiplication";
	case enOperation::Division:
		return "Division";
	case enOperation::MixOp:
		return "Mix";
	default:
		return "Addition";
	}
}

string GameResult(stRoundsCharacteristics Rounds)
{
	if (Rounds.Wins == Rounds.Loses)
		return "Draw";
	else if (Rounds.Wins > Rounds.Loses)
		return "Win";
	else
		return "Lose";
}

void DisplayFinalResult(stRoundsCharacteristics Rounds)
{
	system("cls");
	system("color 07");

	cout << "--------------------------------\n";
	cout << "\tFinal Result\n";
	cout << "--------------------------------\n";
	cout << "Number of rounds   : " << Rounds.NumberOfRounds << endl;
	cout << "Level of difficulty: " << QuestionLevelString(Rounds.QuestionLevel) << endl;
	cout << "Type of operation  : " << OpTypeString(Rounds.OpType) << endl;
	cout << "Wins               : " << Rounds.Wins << endl;
	cout << "Loses              : " << Rounds.Loses << endl;
	cout << "Game result        : " << GameResult(Rounds) << endl;
	cout << "--------------------------------\n";

	system("pause");
}

void StartGame()
{
	char PlayAgain = 'y';
	do
	{
		system("cls");

		stRoundsCharacteristics Rounds;

		Rounds.NumberOfRounds = ReadNumberOfRounds();
		Rounds.QuestionLevel = ReadQuestionLevel();
		Rounds.OpType = ReadOperationType();

		GenerateRounds(Rounds);
		DisplayFinalResult(Rounds);

		cout << "\nDo you want to play again? Y/N\n";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{	
	srand((unsigned)time(NULL));

	StartGame();
	
	return 0;
}