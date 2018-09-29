/* This is the console executable that makes use of the BullCow class
This acts as the view in a MVC patter, and is respponsible for all
user interaction. For game logic see the FBullCowGame class

*/

#include <iostream>
#include <string>	
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();


FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);

	return 0; // exit the application
}

 
// introduce the game
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinki ng of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	// loop for the number of turns asking for guesses
	
	for (int32 count = 1; count <= MaxTries; count++) // TODO change from FOR to WHILE loop once we are validating tries
	{
		FText Guess = GetValidGuess(); 
		
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		// submit valid guess to the game revieve counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	// TODO summarise game
}

// loop continualy until the user gives a valid guess
FText GetValidGuess()
{
		EGuessStatus Status = EGuessStatus::InvalidStatus;

	do {

		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		FText Guess = "";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		//check guess validity
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an Isogram; a word without repeating letters.\n";
			break;
		case EGuessStatus::NULL_Entry:
			std::cout << "Please make a guess before submitting.\n";
			break;
		case EGuessStatus::Non_Letters:
			std::cout << "Please enter only letters.\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		case EGuessStatus::Repeat_Guess:
			std::cout << "Please don't repeate guesses.\n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	}while (Status != EGuessStatus::OK); // keep looping until we get no errors
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
