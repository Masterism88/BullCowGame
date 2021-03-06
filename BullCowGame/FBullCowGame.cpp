#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWone() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // If the guess isn't an isogram,
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // If the guess isn't all lowercase, 
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())//If the guess length is wrong,
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK; //otherwise
	}
}

//Receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess

	 //Loop through all letters in the hudden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		// Compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			// If they match
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { // If they're in the same palce
					BullCowCount.Bulls++; // Increment bulls
				}
				else {
					BullCowCount.Cows++; // Increment cows
				}
			}
		}
	}
	return BullCowCount;
}
