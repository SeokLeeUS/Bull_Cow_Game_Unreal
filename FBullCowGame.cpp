#pragma once
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

FBullCowGame::FBullCowGame(){ 	Reset();}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	int32 MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "planet"; //this MUST be isogram word
	MyHiddenWord = HIDDEN_WORD;

	return;
}



bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

void FBullCowGame::PrintGameSummary() const
{
	if (bGameIsWon == true)
	{
		std::cout<<"you win!";
	}
	else if (MyCurrentTry > 3)
	{
		std::cout<<"bad luck";
	}
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{

	if (!IsIsogram(Guess)) // if the guess is not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowecase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}

}



// receives a valid guess, increments turn, and returns count. 



FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{

	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 WordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
			

		}

	}
	
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }
	TMap<char, bool> LetterSeen;// loop through all the letter of the word
	for (auto Letter : Word)
	{		
		Letter = tolower(Letter);
		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::IsLowecase(FString Word) const
{
	for (auto letter : Word)
	{
		auto letter_low = tolower(letter);
		if (letter_low != letter)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}
