#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

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

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)//If the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)//If guess length isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength() )//If the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else 
	{
		return EGuessStatus::OK;
	}
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
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) 
	{
		//compare letters to hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) 
		{
		//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) 
			{//if they are in the same place
				if (MHWChar == GChar)
				{//increment bulls
					BullCowCount.Bulls += 1;
				}
				else 
				{// else increment cows - counts second letters in word as cows AND bulls?
					BullCowCount.Cows += 1;
				}
			}
			else continue;
		}
	}

	return BullCowCount;
}