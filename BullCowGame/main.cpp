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
void PrintGameSummary();
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
		PrintGameSummary();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);

	return 0; // exit the application
}

 
// introduce the game
void PrintIntro()
{
	std::cout << "\n\n";
	std::cout << "   ***********************************************************\n";
	std::cout << "           Welcome to Bulls and Cows, a fun word game!\n";
	std::cout << "              Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram?\n";
	std::cout << "   ***********************************************************\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	// loop asking for guesses while game 
	// is NOT won and there are tries remaining
	
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) // TODO change from FOR to WHILE loop once we are validating tries
	{
		FText Guess = GetValidGuess(); 
		
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		// submit valid guess to the game revieve counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	// TODO summarise game

	return;
}

// loop continualy until the user gives a valid guess
FText GetValidGuess()
{
		EGuessStatus Status = EGuessStatus::InvalidStatus;
		FText Guess; 
		FText LastGuess;
	do {

		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";

		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		//check guess validity
		switch (Status) {
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
				//assuming guess is valide
				break;
		}
		std::cout << std::endl;
	}while (Status != EGuessStatus::OK); // keep looping until we get no errors
	LastGuess = Guess;
	return Guess;
}

//End game print statements
void PrintGameSummary()
{
	std::cout << "\n\n";
	if (BCGame.IsGameWon())
	{//game is won
		std::cout << "Wow! You really are good at this game! It only took you ";
		if (BCGame.GetCurrentTry() == 2)
		{
			std::cout << " 1 try! I can hardly believe it! 0w0\n";
		}
		else
		{
			std::cout << BCGame.GetCurrentTry() - 1 << " tries!\n";
		}
		std::cout << "\nThink you can do it again?\n";
	}
	else
	{//game was lost
		std::cout << "Too bad, you lost! But don't worry, you can always try again!\n";
	}
}

bool AskToPlayAgain()
{
	std::cout << "\n    ---------------------------\n";
	std::cout << "     Do you want to play another round with that same word(y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
