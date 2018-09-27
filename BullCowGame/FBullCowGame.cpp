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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment the turn number
	MyCurrentTry++;

	//setup a return variable
	FBullCowCount BullCowCount;
	
	//loop through letters of GetGuess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++) 
	{
		//compare letters to hidden word
		for (int32 j = 0; j < HiddenWordLength; j++) 
		{
		//if they match then
			if (Guess[i] == MyHiddenWord[j]) 
			{//if they are in the same place
				if (i == j)
				{//increment bulls
					BullCowCount.Bulls += 1;
					continue;
				}
				else 
				{// else increment cows - counts second letters in word as cows AND bulls?
					BullCowCount.Cows += 1;
					continue;
				}
			}
			else continue;
		}
	}

	return BullCowCount;
}