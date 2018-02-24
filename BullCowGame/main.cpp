/*
This is the console executable, this makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all user interaction.
For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"


FBullCowGame BCGame; // instantiate a new game


using int32 = int;
using FText = std::string;


void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();


// The entry point for our application
int main()
{
	bool bAskToPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bAskToPlayAgain = AskToPlayAgain();
	} while (bAskToPlayAgain);
	return 0; // Exits the application
}


void PrintIntro()
{
	// Introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}


void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for number of turns
	for (int32 count = 1; count <= MaxTries; count++) { // TODO change from FOR to WHILE loop
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		// FBullCowCount is the name of the struct while BullCowCount is the name of the variable (kind of like instantiating)

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
	}
	// TODO summarize game
	return;
}


// Loop continually until the user gives a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// Get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckMyGuess(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please input an isogram i.e. a word with no repeating letters.\n";
			break;
		case EGuessStatus::No_Lowercase:
			std::cout << "Please use all lowercase letters.\n";
			break;
		default:
			// Assume you have a valid guess
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::Ok);
	return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}