#pragma once
/* The game logic (no view code or direct user interaction)
The game is a simple guess the word game based on Mastermind
*/

#include <string>
#include <iostream> 

// make Unreal friendly syntax
using FString = std::string;
using int32 = int;

enum class EGuessStatus
{
	Invaid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

enum class EResetStatus
{
	No_Hidden_Word,
	OK
};


struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


class FBullCowGame {
public:
	FBullCowGame();//constructor


	void Reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	void PrintGameSummary() const;

	EGuessStatus CheckGuessValidity(FString) const; 
	// counts bulls & cows, and increasing try #
	FBullCowCount SubmitValidGuess(FString);


private:
	// see constructor for initialization 
	int MyCurrentTry; 
	int MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowecase(FString) const;
};