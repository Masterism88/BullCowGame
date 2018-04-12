#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); //TODO make a more rich return value
	int GetMaxTries();
	int GetCurrentTries();
	bool IsGameWone();
	bool CheckGuessValidity(std::string); //TODO make a more rich return value
	

private:
	int MyCurrentTry;
	int MyMaxTries;
};