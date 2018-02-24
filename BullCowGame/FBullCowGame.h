#pragma once
#include <string>

using int32 = int;
using FString = std::string;

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	Invalid_Status,
	Ok,
	Not_Isogram,
	Wrong_Length,
	No_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame(); // Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool DidIWin() const;
	EGuessStatus CheckMyGuess(FString) const;

	void Reset(); //TODO get a richer return value
	FBullCowCount SubmitValidGuess(FString Guess);

// ^^ Please try to ignore this and focus on the above interface ^^
private:
	// See constructor for intialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};