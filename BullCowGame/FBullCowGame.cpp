#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; } // getter method (returns the value of a private member variable)
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; } // getter method (returns the value of a private member variable)
int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length(); } // getter method (returns the value of a private member variable)

void FBullCowGame::Reset() // setter function (sets the value of a private member variable)
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::DidIWin() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckMyGuess(FString Guess) const
{
	if (false) {
		// If the guess isn't an isogram
		return EGuessStatus::Not_Isogram;
	} else if (false) {
		// If the guess isn't all lowercase
		return EGuessStatus::No_Lowercase;
	} else if (Guess.length() != GetHiddenWordLength()) {
		// If the guess length is wrong
		return EGuessStatus::Wrong_Length;
	} else {
		// Otherwise
		EGuessStatus::Ok;
	}
}

// Receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length(); // Assuming same length as Guess

	// Loop through all letters in the guess
	for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
	{
		// Compare letters to the hidden word
		for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
		{
			// If the position of letters match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) 
			{
				// If 
				if (GChar == MHWChar)
				{
					// Increment bulls
					BullCowCount.Bulls++;
				} else {
					// Increment cows
					BullCowCount.Cows++;
				}
				
			}
		}
	}

	return BullCowCount;
}
