#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();


FBullCowGame BCGame; // Instantiate a new game

int main()
{
	// Entry point for application
	bool PlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		PlayAgain = AskToPlayAgain();
	} while (PlayAgain);

	return 0; // Exit application
}


void PrintIntro()

{	// Introduce the game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	// Loop for number of turns asking for guesses
	// TODO Change from FOR to WHILE loop once we are validating tries
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= MaxTries; count++) {
		std::string Guess = GetGuess(); // TODO make loop checking valid

		// TODO Submit valid gues to the game
		// TODO Print number of bulls and cows
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO Summarise game
}

std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();

	// Get a guess from the player
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	// Ask player to play again
	std::cout << "Do you want to play again? (y/n)";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
