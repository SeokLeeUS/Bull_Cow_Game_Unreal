/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. From game logic, see the FBullCowGame class. 
*/

#pragma once
#include <iostream> // importing standard stuff
#include <string>
#include "FBullCowGame.h"

// make Unreal friendly syntax
using FText = FString;
using int32 = int;

// prototype function outside of class definition
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

// class definition
FBullCowGame BCGame;

// entry point for our application 
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	
	return 0;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	// loop for the number of turns asking for guesses
	while((!BCGame.IsGameWon()) && (BCGame.GetCurrentTry() <= MaxTries))
	{
		FText Guess = GetValidGuess(); 



		//Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		//Print number of bulls and cows
		std::cout << " Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
		BCGame.PrintGameSummary();
	}

	return;
}

void PrintIntro() {

	// introduce the game
	std::cout << "\n\nWelcome to bulls and cows, a fun word game!\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I am thinking of?\n";
	std::cout << std::endl;
}

// loop continually until the user gives a valid guess
FText GetValidGuess() {

	FText Guess = "";
	// get a guess from the player
	//std::cout << BCGame.GetCurrentTry();
	EGuessStatus Status = EGuessStatus::Invaid_Status;
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try # " << CurrentTry << ". Enter your guess: ";

		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;

		case EGuessStatus::Not_Lowercase:
			std::cout << "please enter lowercase.\n";
			break;

		default:
			//assume the guess is valid
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = " ";
	std::getline(std::cin, Response);
	return((Response[0] == 'y') || (Response[0] == 'Y'));
}
