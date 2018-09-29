#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//all values initialized to zero
struct FBullCowCount	
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

// List of codes for the guess validity
enum class EGuessStatus 
{
	InvalidStatus,
	OK,
	Not_Isogram,
	NULL_Entry,
	Non_Letters,
	Wrong_Length,
	Not_Lowercase,
	Repeat_Guess
};


class FBullCowGame{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; // TODO Make a more rich return value
	
	void Reset(); // TODO make a more rich return value.

	//count bulls and cows , and increase try # assuming a valid guess
	FBullCowCount SubmitValidGuess(FString);

// ^^ Please try and ignore this and focus on the interface above ^^
private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	bool bGameIsWon = false;
	FString MyHiddenWord = "world";
};