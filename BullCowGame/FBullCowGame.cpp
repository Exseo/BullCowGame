#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
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

//recieves a valid guess, increments turn, and returns count; not called with invalid guess
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); //assuming same lenght as guess

	//loop through letters of HiddenWord
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) 
	{//compare letters to Guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) 
		{//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) 
			{//if they are in the same place
				if (MHWChar == GChar)//increment bulls
				{BullCowCount.Bulls += 1;}
				else{BullCowCount.Cows += 1;}// else increment cows
			}
			else continue;
		}
	}
	
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	};

	return BullCowCount;
}