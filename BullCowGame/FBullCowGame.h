#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//All values initialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame(); // Constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWone() const;
	EGuessStatus CheckGuessValidity(FString) const; // TODO make a more rich return value

	void Reset(); // TODO make a more rich return value
	FBullCowCount SubmitValidGuess(FString);
	

private:
	// See constuctor for initalisation 
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};