#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); // Constructor
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWone() const;

	void Reset(); // TODO make a more rich return value
	bool CheckGuessValidity(std::string); // TODO make a more rich return value
	// TODO Provide a method for counting bulls & cows, and increasing try #
	

private:
	// See constuctor for initalisation 
	int MyCurrentTry;
	int MyMaxTries;
};