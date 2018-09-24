#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

//recieves a valid guess, increments turn, and returns count
BullCowCount FBullCowGame::SubmitGuess(Fstring)
{
	//increment the turn number
	MyCurrentTry++;

	//setup a return variable
	BullCowCount BullCowCount;

	//loop through letters of GetGuess
		//compare letters to hidden word

	return BullCowCount();
}